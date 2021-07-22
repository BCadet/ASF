/**
 * \file
 *
 * \brief megaAVR STK600 AVR libc setbaud Example
 *
 * Copyright (c) 2011-2018 Microchip Technology Inc. and its subsidiaries.
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
 * \section board STK600 development board
 * \section intro Introduction
 * This example demonstrates how to use the avr libc utility setbaud to find
 * the correct settings for the UART baudrate registers.
 *
 * \section files Files:
 * - mega_setbaud_example.c: megaAVR STK600 setbaud example application
 *
 * \section exampledescription Brief description of the example application
 * This application will set up the UART according to the settings in the
 * conf_uart.h file, baudrate is calculated using the avr libc setbaud utility.
 * When initialization of the UART is done the application sends the letter 'A'
 * on the UART and expect to receive the same letter, hence the hardware must
 * be set up so that the TX and RX pin is shorted to create a loop back.
 *
 * The util/setbaud tool is a tool offered by the avr libc library, and is
 * a function for compile time calculation of the baudrate register of values.
 * In application where run-time baudrate change is not needed this is a tool
 * which easily calculates the best baudrate register settings while keeping the
 * flash footprint at a minimum.
 *
 * A common way of using the setbaud tool is:
 * \code
	 // Define the CPU clock frequency, e.g. 1MHz
	 #define F_CPU 1000000UL
	 // Define the target baudrate, e.g. 9600bps
	 #define BAUD 9600
	 // Set the accepted tolerance, e.g. 2%
	 #define BAUD_TOL 2

	 // Load the calculated values into the correct registers
	 UBRR0H = UBRRH_VALUE;
	 UBRR0L = UBRRL_VALUE;

	 //Then we need to take into account that we may need to set the 2X bit in
	 //the UART control register to achieve the correct baudrate.
	 #ifdef USE_2X
	 UCSR0A |= (1 << U2X0);
	 #endif

	 // The last thing that needs to be done is to enable output on the TX pin,
	 // input on the RX pin and enable the RX and TX in the UART itself. In
	 // addition to setting the correct mode and bit length, parity and stop-bits.
\endcode
 *
 * \section compinfo Compilation Info
 * This software was written for the <A href="http://gcc.gnu.org/">GNU GCC</A>
 * for AVR. \n
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.microchip.com/">Microchip</A>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#define _ASSERT_ENABLE_
#include "compiler.h"

#define TIMEOUT 250

// Set the correct BAUD and F_CPU defines before including setbaud.h
#include "conf_clock.h"
#include "conf_uart.h"
#include <util/setbaud.h>

/**
 * \brief Initialize the uart with correct baud rate settings
 *
 * This function will initialize the UART baud rate registers with the correct
 * values using the AVR libc setbaud utility. In addition set the UART to 8-bit,
 * 1 stop and no parity.
 */
static void uart_init(void)
{
#if defined UBRR0H
	/* These values are calculated by the setbaud tool based on the values
	defined in conf_clock.h and conf_uart.h. The only thing that the application
	need to do is to load these values into the correct registers.*/
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#else
#error "Device is not supported by the driver"
#endif

	/* Check if the setbaud tool require that the 2x speed bit has to be set in
	order to reach the specified baudrate. */
#if USE_2X
	UCSR0A |= (1 << U2X0);
#endif

	// Enable RX and TX and set up port
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	// Set the TX pin as output
	UART_PORT_DDR |= (1 << UART_TX_PIN);
	// Set the RX pin as input
	UART_PORT_DDR &= ~(1 << UART_RX_PIN);

	// 8-bit, 1 stop bit, no parity, asynchronous UART
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00) | (0 << USBS0) |
			(0 << UPM01) | (0 << UPM00) | (0 << UMSEL01) |
			(0 << UMSEL00);
}

/**
 * \brief Function for sending a char over the UART
 *
 * \param data the data to send over UART
 */
static void uart_putchar(uint8_t data)
{
	// Make sure that the UART buffer is empty
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

/**
 * \brief Function for getting a char from the UART
 *
 * \note This function is blocking and will expect to receive something
 * on the UART.
 *
 * \retval uint8_t the data received from the UART
 * \retval 0       if timeout
 */
static uint8_t uart_getchar(void)
{
	uint8_t timeout = TIMEOUT;
	// Wait for RX to complete
	while ((!(UCSR0A & (1 << RXC0))) && timeout) {
		timeout--;
	}
	if (timeout) {
		return UDR0;
	} else {
		// No data, timeout
		return 0;
	}
}

/**
 * \brief Example application on how to use the libc setbaud utility.
 *
 * This application shows how to use the avr libc setbaud utility to get the
 * correct values for the baud rate registers. It also performs a test where
 * it sends a character on the UART and check if the same char is received
 * back.
 *
 * \note This application assumes that the TX and RX pins have been externally
 * shorted to create a loop back.
 */
int main(void)
{
	// Set up baud rate registers
	uart_init();
	// Write a set of letters to the UART
	uart_putchar('A');
	// Check to see if send and receive works.
	Assert(uart_getchar() == 'A');

	while (true);
}
