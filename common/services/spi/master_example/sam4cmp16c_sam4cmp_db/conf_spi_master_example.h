/**
 * \file
 *
 * \brief Spi Master example configuration.
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

#ifndef CONF_SPI_MASTER_EXAMPLE_H
#define CONF_SPI_MASTER_EXAMPLE_H

#include "conf_board.h"
#include "sysclk.h"

/*! \name Configuration
 */
//! @{
#define SPI_EXAMPLE                   SPI0
#define SPI_DEVICE_EXAMPLE_ID         0
#define SPI_EXAMPLE_BAUDRATE          1000000
#define SPI_EXAMPLE_LED_PIN_EXAMPLE_2 LED4_GPIO
//! @}

/*! \name Bit-Masks and Values for the Status Register
 */
//! @{
#define AT25DF_MSK_DENSITY       0x07  //!< Device status bit-mask
#define AT25DF_DENSITY           0x07  //!< Device default software protect value
//! @}

#endif  /* _CONF_SPI_MASTER_EXAMPLE_H */
