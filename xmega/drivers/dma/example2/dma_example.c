/**
 * \file
 *
 * \brief AVR XMEGA DMA example 2
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

/**
 * \mainpage
 *
 * \section intro Introduction
 * This simple example shows how to use the \ref dma_group.
 *
 * \section files Main Files
 * - dma_example.c example application
 * - conf_example.h example configuration
 *
 * \section device_info Device Info
 * All AVR XMEGA devices with a DMA controller can be used. This example have
 * been tested with the following setup:
 * - XMEGA-A1 Xplained
 * - XMEGA-A3BU Xplained
 * - XMEGA-B1 Xplained
 *
 * \section description Description of the example
 *
 * This example will start a DMA transfer between two internal memory areas,
 * and upon completion it will verify this by comparing those areas.
 *
 * During the progress of the application it will output some information to
 * the LEDS, and these LEDS have the following assignment:
 * - LED0: DMA transaction has been started
 * - LED1: DMA completed successfully
 *
 * In a successful operation LED 0 will light up for a short time, then it will
 * turn off and LED 1 will turn on to indicate transfer success. If LED 1 does
 * not turn on after LED 0, a fault has occurred in the transfer.
 *
 * \section dependencies Dependencies
 * This example depends on the following modules:
 * - \ref dma_group
 * - \ref pmic_group for interrupt handling
 * - \ref ioport_group for LED output
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for AVR. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.microchip.com/">Microchip</a>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <conf_example.h>
#include <string.h>
#include <asf.h>

/** \brief Source buffer to use for DMA transfer */
static uint8_t source[DMA_BUFFER_SIZE];

/** \brief Destination buffer to use for DMA transfer */
static uint8_t destination[DMA_BUFFER_SIZE];

/**
 * \brief Fill buffer with a specific pattern
 *
 * \param buffer Buffer to fill with a specific pattern
 * \param len Length of the buffer
 */
static void fill_pattern(uint8_t *buffer, size_t len)
{
	int i;

	for (i = 0; i < len; i++) {
		buffer[i] = 42 ^ (i & 0xff) ^ (i >> 8);
	}
}

/**
 * \brief Verify if buffer if filled by the specific pattern generated by the
 * fill_pattern() function.
 *
 * \param buffer Buffer to verify
 * \param len Length of the buffer
 *
 * \retval true Buffer is equal to specific pattern
 * \retval false Buffer is not equal to specific pattern
 */
static bool verify_pattern(uint8_t *buffer, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		if (buffer[i] != (42 ^ (i & 0xff) ^ (i >> 8))) {
			return false;
		}
	}

	return true;
}

/**
 * \brief Callback for DMA transfer complete
 *
 * \param status Status of a completed (or failed) DMA transfer
 */
static void example_dma_transfer_done(enum dma_channel_status status)
{
	bool status_ok = true;

	/* Check DMA transfer status */
	if (status == DMA_CH_TRANSFER_COMPLETED) {
		LED_Off(LED0);
	}

	/* Check if destination is as expected */
	if (verify_pattern(destination, DMA_BUFFER_SIZE) == false) {
		status_ok = false;
	}

	/* Check if source haven't been garbled */
	if (verify_pattern(source, DMA_BUFFER_SIZE) == false) {
		status_ok = false;
	}

	/* Check if all checks have passed successfully */
	if (status_ok == true) {
		LED_On(LED1);
	} else {
		LED_Off(LED1);
	}
}

/**
 * \brief main function
 */
int main(void)
{
	struct dma_channel_config config;

	/*
	 * Initialize basic features for the AVR XMEGA family.
	 *  - PMIC is needed to enable all interrupt levels.
	 *  - Board init for setting up GPIO and board specific features.
	 *  - Sysclk init for configuring clock speed and turning of unused
	 *    peripherals.
	 *  - Sleepmgr init for setting up the basics for the sleep manager,
	 *    although not used in this example, but the sleep manager is used
	 *    by the DMA driver.
	 */
	pmic_init();
	board_init();
	sysclk_init();
	sleepmgr_init();

	/*
	 * Fill source buffer with a specific pattern and clear destination so
	 * we are sure they are different.
	 */
	fill_pattern(source, DMA_BUFFER_SIZE);
	memset(destination, 0, DMA_BUFFER_SIZE);

	dma_enable();

	/*
	 * In this example the example_dma_transfer_done() function will be
	 * used as the callback function from completed DMA block transfers.
	 * This function is called whenever an interrupt occurs on the DMA
	 * channel this function is set to handle. A callback function is set
	 * by the dma_set_callback() function in the DMA driver interface.
	 */
	dma_set_callback(DMA_CHANNEL, example_dma_transfer_done);

	/* Make sure config is all zeroed out so we don't get any stray bits */
	memset(&config, 0, sizeof(config));

	/*
	 * This example will configure a DMA channel with the following
	 * settings:
	 *  - Low interrupt priority
	 *  - 1 byte burst length
	 *  - DMA_BUFFER_SIZE bytes for each transfer
	 *  - Reload source and destination address at end of each transfer
	 *  - Increment source and destination address during transfer
	 *  - Source address is set to \ref source
	 *  - Destination address is set to \ref destination
	 */
	dma_channel_set_interrupt_level(&config, DMA_INT_LVL_LO);
	dma_channel_set_burst_length(&config, DMA_CH_BURSTLEN_1BYTE_gc);
	dma_channel_set_transfer_count(&config, DMA_BUFFER_SIZE);
	dma_channel_set_src_reload_mode(&config,
			DMA_CH_SRCRELOAD_TRANSACTION_gc);
	dma_channel_set_dest_reload_mode(&config,
			DMA_CH_DESTRELOAD_TRANSACTION_gc);
	dma_channel_set_src_dir_mode(&config, DMA_CH_SRCDIR_INC_gc);
	dma_channel_set_dest_dir_mode(&config, DMA_CH_DESTDIR_INC_gc);
	dma_channel_set_source_address(&config, (uint16_t)(uintptr_t)source);
	dma_channel_set_destination_address(&config,
			(uint16_t)(uintptr_t)destination);
	dma_channel_write_config(DMA_CHANNEL, &config);

	/* Use the configuration above by enabling the DMA channel in use. */
	dma_channel_enable(DMA_CHANNEL);

	/*
	 * Enable interrupts as the example is now configured to handle them
	 * properly.
	 */
	cpu_irq_enable();

	/*
	 * Trigger a manual start since there is no trigger sources used in
	 * this example.
	 */
	dma_channel_trigger_block_transfer(DMA_CHANNEL);

	/* Light the first LED to indicate that the DMA has started. */
	LED_On(LED0);

	while (true) {
		/*
		 * Force a NOP instruction for an eventual placement of a debug
		 * session breakpoint.
		 */
		asm ("nop\n");
	}
}
