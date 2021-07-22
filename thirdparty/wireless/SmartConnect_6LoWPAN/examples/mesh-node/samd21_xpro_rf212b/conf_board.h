/**
 * \file
 *
 * \brief Board configuration
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

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED


#define CONF_BOARD_AT86RFX
#define EXT2_CONFIG
#define AT86RFX_SPI                  EXT2_SPI_MODULE
#define AT86RFX_RST_PIN              EXT2_PIN_7
#define AT86RFX_MISC_PIN             EXT2_PIN_12
#define AT86RFX_IRQ_PIN              EXT2_PIN_9
#define AT86RFX_SLP_PIN              EXT2_PIN_10
#define AT86RFX_SPI_CS               EXT2_PIN_15
#define AT86RFX_SPI_MOSI             EXT2_PIN_16
#define AT86RFX_SPI_MISO             EXT2_PIN_17
#define AT86RFX_SPI_SCK              EXT2_PIN_18
#define AT86RFX_CSD                  EXT2_PIN_5
#define AT86RFX_CPS                  EXT2_PIN_8



#define AT86RFX_SPI_SERCOM_MUX_SETTING   EXT2_SPI_SERCOM_MUX_SETTING
#define AT86RFX_SPI_SERCOM_PINMUX_PAD0   EXT2_SPI_SERCOM_PINMUX_PAD0
#define AT86RFX_SPI_SERCOM_PINMUX_PAD1   PINMUX_UNUSED
#define AT86RFX_SPI_SERCOM_PINMUX_PAD2   EXT2_SPI_SERCOM_PINMUX_PAD2
#define AT86RFX_SPI_SERCOM_PINMUX_PAD3   EXT2_SPI_SERCOM_PINMUX_PAD3




#define AT86RFX_IRQ_CHAN       EXT2_IRQ_INPUT
#define AT86RFX_IRQ_PINMUX     EXT2_IRQ_PINMUX
#define IC_TYPE             (0x00)

#define MCU_SOC_NAME        "ATSAMR21G18A"

#define AT86RFX_SPI_BAUDRATE		 4000000UL



#endif /* CONF_BOARD_H_INCLUDED */
