/**
 * \file
 *
 * \brief ATPL230 Physical layer - IIR Filter
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

#ifndef ATPL230IIRFILTER_H_INCLUDE
#define ATPL230IIRFILTER_H_INCLUDE

#include "compiler.h"

/**
 * \weakgroup phy_plc_group
 * @{
 */

/* \name IIR Filter definitions */
/* @{ */
#define LENGTH_ROW_DATA_FILTER_IIR      2
#define NUM_ROWS_DATA_FILTER_IIR        40
#define LENGTH_DATA_FILTER_IIR (NUM_ROWS_DATA_FILTER_IIR * LENGTH_ROW_DATA_FILTER_IIR)

#define LENGTH_ROW_DATA_CHIRP   4
#define NUM_ROWS_DATA_CHIRP     65
#define LENGTH_DATA_CHIRP       (NUM_ROWS_DATA_CHIRP * LENGTH_ROW_DATA_CHIRP)

#define LENGTH_ROW_DATA_ANGLE_REAL_IMAG_COMP    2
#define NUM_ROWS_DATA_ANGLE_REAL_IMAG_COMP      97
#define LENGTH_DATA_ANGLE_REAL_IMAG_COMP (NUM_ROWS_DATA_ANGLE_REAL_IMAG_COMP * LENGTH_ROW_DATA_ANGLE_REAL_IMAG_COMP)

#define LENGTH_ROW_DATA_OFFSET_CORRECTION       4
#define NUM_ROWS_DATA_OFFSET_CORRECTION         16
#define LENGTH_DATA_OFFSET_CORRECTION          (NUM_ROWS_DATA_OFFSET_CORRECTION * LENGTH_ROW_DATA_OFFSET_CORRECTION)
/* @} */

/* @} */

#endif  /* ATPL230IIRFILTER_H_INCLUDE */
