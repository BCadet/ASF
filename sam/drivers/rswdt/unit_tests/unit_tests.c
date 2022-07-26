/**
 * \file
 *
 * \brief Unit tests for RSWDT driver.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <stdint.h>
#include <stdbool.h>
#include <board.h>
#include <sysclk.h>
#include <rswdt.h>
#include <string.h>
#include <unit_test/suite.h>
#include <stdio_serial.h>
#include <conf_test.h>
#include <conf_board.h>

/**
 * \mainpage
 *
 * \section intro Introduction
 * This is the unit test application for the RSWDT driver.
 * It consists of test cases for the following functionality:
 * - Reinforced Safety Watchdog init
 * - Reinforced Safety Watchdog restart
 * - Reinforced Safety Watchdog reset
 *
 * \section files Main Files
 * - \ref unit_tests.c
 * - \ref conf_test.h
 * - \ref conf_board.h
 * - \ref conf_clock.h
 * - \ref conf_usart_serial.h
 *
 * \section device_info Device Info
 * All SAM devices can be used.
 * This example has been tested with the following setup:
 * - sam4e16e_sam4e_xplained_pro
 
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for ARM. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.microchip.com/">Microchip</a>.\n
 * Support and FAQ: https://www.microchip.com/support/
 */

//! \name Unit test configuration
//@{
/**
 * \def CONF_TEST_RSWDT
 * \brief Init reinforced safety watchdog, restart it and trigger it.
 */
//@}

/* Is set to 1 when a reinforced safety watchdog interrupt happens */
static volatile int gs_rswdt_triggered = 0U;

/* Systick Counter */
static volatile uint32_t gs_ul_ms_ticks = 0U;

/**
 * \brief RSWDT interrupt handler.RSWDT and WDT are the same as the interrupt number.
 */
void WDT_Handler(void)
{
	/* Clear IRQ */
	RSWDT->RSWDT_SR;

	/* Update state machine */
	gs_rswdt_triggered = 1;
}

/**
 * \brief SysTick handler.
 */
void SysTick_Handler(void)
{
	/* Increment counter necessary in delay(). */
	gs_ul_ms_ticks++;
}

/**
 * \brief Delay number of tick Systicks (happens every 1 ms).
 */
static void delay_ms(uint32_t ul_dly_ticks)
{
	uint32_t ul_cur_ticks;

	ul_cur_ticks = gs_ul_ms_ticks;
	while ((gs_ul_ms_ticks - ul_cur_ticks) < ul_dly_ticks) {
	}
}

/**
 * \brief Test reinforced safety watchdog setting
 *
 * This test sets the reinforced safety watchdog to trigger an interrupt every 100ms.
 *
 * \param test Current test case.
 */
static void run_rswdt_test(const struct test_case *test)
{
	/* Clear reinforced safety watchdog if already enabled */
	rswdt_restart(RSWDT);

	/* Enable RSWDT interrupt line from the core */
	NVIC_DisableIRQ(RSWDT_IRQn);
	NVIC_ClearPendingIRQ(RSWDT_IRQn);
	NVIC_SetPriority(RSWDT_IRQn, 4);
	NVIC_EnableIRQ(RSWDT_IRQn);

	/* Test1: Initialize RSWDT to trigger a reset after 100ms */
	rswdt_init(RSWDT, RSWDT_MR_WDFIEN, 26, 26);

	delay_ms(50);
	test_assert_true(test, gs_rswdt_triggered == 0, "Test1: unexpected reinforced safety watchdog interrupt!");

	/* Test2: Restart the reinforced safety watchdog */
	rswdt_restart(RSWDT);
	delay_ms(50);
	test_assert_true(test, gs_rswdt_triggered == 0, "Test2: unexpected reinforced safety watchdog interrupt!");

	/* Test 3: Trigger the reinforced safety watchdog interrupt (reset) */
	delay_ms(200);
	test_assert_true(test, gs_rswdt_triggered == 1, "Test3: no reinforced safety watchdog interrupt received, expected one!");
}

/**
 * \brief Run RSWDT driver unit tests
 */
int main(void)
{
	const usart_serial_options_t usart_serial_options = {
		.baudrate = CONF_TEST_BAUDRATE,
#ifdef CONF_TEST_CHAR_LENGTH
		.charlength = CONF_TEST_CHAR_LENGTH,
#endif
		.paritytype = CONF_TEST_PARITY,
#ifdef CONF_TEST_STOP_BITS
		.stopbits = CONF_TEST_STOP_BITS,
#endif
	};

	sysclk_init();
	board_init();

	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_TEST_USART, &usart_serial_options);

	/* Set up SysTick Timer for 1 msec interrupts. */
	if (SysTick_Config(sysclk_get_cpu_hz() / 1000)) {
		/* Capture error. */
		while (1) {
		}
	}

	/* Define all the test cases */
	DEFINE_TEST_CASE(rswdt_test, NULL, run_rswdt_test, NULL,
		"Reinforced Safety Watchdog init, restart and reset");

	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(rswdt_tests) = {
		&rswdt_test,
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(rswdt_suite, rswdt_tests, "SAM RSWDT driver test suite");

	/* Run all tests in the test suite */
	test_suite_run(&rswdt_suite);

	/* Disable the reinforced safety watchdog */
	rswdt_disable(RSWDT);
	
	while (1) {
		/* Busy-wait forever. */
	}
}
