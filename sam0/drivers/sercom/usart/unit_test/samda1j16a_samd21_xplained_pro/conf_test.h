/**
 * \file
 *
 * \brief SAM DA1 Xplained Pro test configuration.
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

#ifndef CONF_TEST_H_INCLUDED
#define CONF_TEST_H_INCLUDED

#define CONF_STDIO_USART          EDBG_CDC_MODULE
#define CONF_STDIO_MUX_SETTING    EDBG_CDC_SERCOM_MUX_SETTING
#define CONF_STDIO_PINMUX_PAD0    EDBG_CDC_SERCOM_PINMUX_PAD0
#define CONF_STDIO_PINMUX_PAD1    EDBG_CDC_SERCOM_PINMUX_PAD1
#define CONF_STDIO_PINMUX_PAD2    EDBG_CDC_SERCOM_PINMUX_PAD2
#define CONF_STDIO_PINMUX_PAD3    EDBG_CDC_SERCOM_PINMUX_PAD3
#define CONF_STDIO_BAUDRATE       38400

/* RX USART to test
 * For unit_test connection uniformity, SERCOM for USART should be
 * the same as SPI, SERCOM for USART in the EXT headers of the
 * rev. 2 is not suitable, just define them directly here.
 */
#define CONF_RX_USART              SERCOM1
#define CONF_RX_USART_SERCOM_MUX   USART_RX_0_TX_2_XCK_3
#define CONF_RX_USART_PINMUX_PAD0  PINMUX_PA16C_SERCOM1_PAD0
#define CONF_RX_USART_PINMUX_PAD1  PINMUX_PA17C_SERCOM1_PAD1
#define CONF_RX_USART_PINMUX_PAD2  PINMUX_PA18C_SERCOM1_PAD2
#define CONF_RX_USART_PINMUX_PAD3  PINMUX_PA19C_SERCOM1_PAD3

/* TX USART to test */
#define CONF_TX_USART              SERCOM5
#define CONF_TX_USART_SERCOM_MUX   USART_RX_1_TX_0_XCK_1
#define CONF_TX_USART_PINMUX_PAD0  PINMUX_PB16C_SERCOM5_PAD0
#define CONF_TX_USART_PINMUX_PAD1  PINMUX_PB17C_SERCOM5_PAD1
#define CONF_TX_USART_PINMUX_PAD2  PINMUX_PB22D_SERCOM5_PAD2
#define CONF_TX_USART_PINMUX_PAD3  PINMUX_PB23D_SERCOM5_PAD3

#endif /* CONF_TEST_H_INCLUDED */
