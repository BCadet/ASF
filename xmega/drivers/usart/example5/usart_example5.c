/**
 * \file
 *
 * \brief AVR XMEGA USART example 5
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

/*! \mainpage
 * \section intro Introduction
 * This example demonstrates how to use XMEGA E USART module with Start Frame
 * Detection.
 *
 * \section files Main Files
 * - usart_example5.c: the example application.
 * - conf_board.h: board configuration
 * - conf_usart_example.h: configuration of the example
 *
 * \section usart_apiinfo drivers/usart API
 * The USART driver API can be found \ref usart_group "here".
 *
 * \section deviceinfo Device Info
 * All AVR XMEGA devices can be used. This example has been tested with the 
 * following setup:
 *   - STK600 with ATxmega32E5 on STK600-RC032X
 *     USARTC0 on PC2 and PC3 pins should be connected to the RXD and TXD
 *     pins of STK600 RS232 spare port.
 *   - XMEGA E5 Xplained evaluation kit
 *     USARTD0 on PORTD pin 6 and 7 is used (Connected to board controller)
 * UART configuration is 115200 baudrate, no parity, data 8 bit.
 *
 * \section exampledescription Description of the example
 * The USART is configured to encode and decode only the data fields of both the
 * received and transmit data frame.
 * The data encoding consists of a NOT operation applied on the data field of
 * the USART frame.
 *
 * To perform such data encoding, the XCL glue logic sub module is configured
 * as follow:
 *  - On the received side LUTO performs NOT operation with IN0 input and the
 * LUTO output is connected on the USART internal input
 *  - On the transmit side LUT1 performs NOT operation with internal USART
 * TX pin.
 *
 * The example outputs an encoded message then, waits for a received character
 * on the configured USART and echoes the character back to the same USART.
 * As both USART encoder and decoder are enabled, the received character is
 * encoded twice (first time during reception, the second time during
 * transmission stage) thus, the resulting character is sent back equal to the
 * orignal received character.
 *
 * The example waits for a received character on the configured USART and
 * echoes the character back to the same USART.
 *
 * Note: The example configures the USART to use together variable frame length
 * (using the PEC counter of XCL module instead of build in USART counters,
 * to count transmission data bit) and data encoding/decoding features of
 * XMEGAE USART.
 * To keep the USART communication still functionnal with a regular USART 
 * computer, the example keeps the number of data bit to be proceed equals to
 * 8bits, but it could be extended to any value up to 255 using 
 * USART_SERIAL_VARIABLE_CHAR_LENGTH.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.microchip.com/design-centers/8-bit">Atmel AVR</A>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <conf_usart_example.h>
#include <asf.h>

ISR(USART_RX_Vect)
{
	usart_putchar(USART_SERIAL_EXAMPLE,
			usart_getchar(USART_SERIAL_EXAMPLE));
	usart_clear_rx_complete(USART_SERIAL_EXAMPLE);
	while (!usart_tx_is_complete(USART_SERIAL_EXAMPLE)) {
	}
	usart_clear_tx_complete(USART_SERIAL_EXAMPLE);
}

/*! \brief Main function.
 */
int main(void)
{
	uint8_t encoded_message[] = {
		0xF2, 0xF5, 0xAB, 0x97, 0x96, 0x8C, 0xDF, 0x96, 0x91, 0xDF,
		0x9E, 0x91, 0xDF, 0x9A, 0x91, 0x9C, 0x90, 0x9B, 0x9A, 0x9B,
		0xDF, 0x92, 0x9A, 0x8C, 0x8C, 0x9E, 0x98, 0x9A, 0xDF, 0x8C,
		0x9A, 0x91, 0x8B, 0xDF, 0x99, 0x8D, 0x90, 0x92,
		0xDF, 0xA7, 0xB2, 0xBA, 0xB8, 0xBE, 0xDF, 0xAA,
		0xAC, 0xBE, 0xAD, 0xAB, 0xDE
	};
	uint8_t i;

	/* Initialize the board.
	 * The board-specific conf_board.h file contains the configuration of
	 * the board initialization.
	 */
	board_init();
	sysclk_init();
	pmic_init();
	cpu_irq_enable();
	sleepmgr_init();
	sleepmgr_lock_mode(SLEEPMGR_STDBY);

	/* USART options. */
	static usart_xmegae_rs232_options_t USART_SERIAL_OPTIONS = {
		.baudrate = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT,
		.start_frame_detection = false,
		.one_wire = false,
		.pec_length = USART_SERIAL_VARIABLE_CHAR_LENGTH,
		.pec_action = USART_PECACT_PERC01_gc,
		.encoding_type = USART_DECTYPE_DATA_gc,
		.encoding_stream = USART_LUTACT_BOTH_gc,
	};

	/* Initialize usart driver in RS232 mode */
	usart_xmegae_init_rs232(USART_SERIAL_EXAMPLE, &USART_SERIAL_OPTIONS);
	usart_set_rx_interrupt_level(USART_SERIAL_EXAMPLE, USART_INT_LVL_LO);

	xcl_port(USART_SERIAL_XCL_PORT);
	xcl_lut_type(LUT_2LUT2IN);
	xcl_lut_in0(USART_SERIAL_LUT_IN_PIN);
	xcl_lut_in1(LUT_IN_XCL);
	xcl_lut0_output(LUT0_OUT_DISABLE);
	xcl_lut_config_delay(DLY11, LUT_DLY_DISABLE, LUT_DLY_DISABLE);
	xcl_lut0_truth(NOT_IN0);

	xcl_lut_in2(LUT_IN_XCL);
	xcl_lut_in3(LUT_IN_XCL);
	xcl_lut1_truth(NOT_IN3);

	/* Send "message header" */
	for (i = 0; i < sizeof(encoded_message); i++) {
		usart_putchar(USART_SERIAL_EXAMPLE, encoded_message[i]);
		while (!usart_tx_is_complete(USART_SERIAL_EXAMPLE)) {
		}
		usart_clear_tx_complete(USART_SERIAL_EXAMPLE);
	}

	/* Incoming character is process under interrupt
	 * main loop simply enters sleep mode */
	while (true) {
		sleepmgr_enter_sleep();
	}
}
