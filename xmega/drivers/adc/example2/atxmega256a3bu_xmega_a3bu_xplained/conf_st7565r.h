/**
 * \file
 *
 * \brief ST7565R display controller driver configuration file.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#ifndef CONF_ST7565R_H_INCLUDED
#define CONF_ST7565R_H_INCLUDED

// USART SPI interface
#define ST7565R_USART_SPI_INTERFACE
#define ST7565R_USART_SPI &USARTD0

// Minimum clock period is 50ns@3.3V -> max frequency is 20MHz
#define ST7565R_CLOCK_SPEED 1000000

#define ST7565R_DISPLAY_CONTRAST_MAX 80
#define ST7565R_DISPLAY_CONTRAST_MIN 70

// Pin mapping A3BU-Xplained
#define ST7565R_A0_PIN       NHD_C12832A1Z_REGISTER_SELECT
#define ST7565R_CS_PIN       NHD_C12832A1Z_CSN
#define ST7565R_RESET_PIN    NHD_C12832A1Z_RESETN

#endif /* CONF_ST7565R_H_INCLUDED */
