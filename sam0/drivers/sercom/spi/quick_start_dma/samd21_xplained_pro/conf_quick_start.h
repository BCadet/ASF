/**
 * \file
 *
 * \brief SERCOM SPI with DMA configurations for SAM D21 Xplained Pro
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

#ifndef CONF_QUICK_START_DMA_H_INCLUDED
#define CONF_QUICK_START_DMA_H_INCLUDED

//[definition_master]
#define CONF_MASTER_SPI_MODULE  EXT2_SPI_MODULE
#define CONF_MASTER_SS_PIN      EXT2_PIN_SPI_SS_0
#define CONF_MASTER_MUX_SETTING EXT2_SPI_SERCOM_MUX_SETTING
#define CONF_MASTER_PINMUX_PAD0 EXT2_SPI_SERCOM_PINMUX_PAD0
#define CONF_MASTER_PINMUX_PAD1 PINMUX_UNUSED
#define CONF_MASTER_PINMUX_PAD2 EXT2_SPI_SERCOM_PINMUX_PAD2
#define CONF_MASTER_PINMUX_PAD3 EXT2_SPI_SERCOM_PINMUX_PAD3
//[definition_master]

//[definition_slave]
#define CONF_SLAVE_SPI_MODULE  EXT1_SPI_MODULE
#define CONF_SLAVE_MUX_SETTING EXT1_SPI_SERCOM_MUX_SETTING
#define CONF_SLAVE_PINMUX_PAD0 EXT1_SPI_SERCOM_PINMUX_PAD0
#define CONF_SLAVE_PINMUX_PAD1 EXT1_SPI_SERCOM_PINMUX_PAD1
#define CONF_SLAVE_PINMUX_PAD2 EXT1_SPI_SERCOM_PINMUX_PAD2
#define CONF_SLAVE_PINMUX_PAD3 EXT1_SPI_SERCOM_PINMUX_PAD3
//[definition_slave]

//[definition_peripheral_trigger]
#define CONF_PERIPHERAL_TRIGGER_TX   SERCOM1_DMAC_ID_TX
#define CONF_PERIPHERAL_TRIGGER_RX   SERCOM0_DMAC_ID_RX
//[definition_peripheral_trigger]

#endif /* CONF_QUICK_START_DMA_H_INCLUDED */
