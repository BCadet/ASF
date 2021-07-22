/**
 * \file
 *
 * \brief SAM R34 serial bridge driver configuration.
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef __CONF_SERIALBRIDGE__
#define __CONF_SERIALBRIDGE__

#define CONF_SB_USART_MODULE  SERCOM5
#define CONF_SB_MUX_SETTING   EXT1_UART_SERCOM_MUX_SETTING
#define CONF_SB_PINMUX_PAD0   PINMUX_PB02D_SERCOM5_PAD0
#define CONF_SB_PINMUX_PAD1   PINMUX_PA23D_SERCOM5_PAD1
#define CONF_SB_PINMUX_PAD2   EXT1_UART_SERCOM_PINMUX_PAD2
#define CONF_SB_PINMUX_PAD3   EXT1_UART_SERCOM_PINMUX_PAD3
#define CONF_SB_BAUDRATE      115200


#endif /* __CONF_SERIALBRIDGE__ */
