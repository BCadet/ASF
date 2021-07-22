/**
 * \file
 *
 * \brief SAM D20 Clock Driver
 *
 * Copyright (c) 2012-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef CLOCK_CONFIG_CHECK_H
#  define CLOCK_CONFIG_CHECK_H

#if !defined(CONF_CLOCK_FLASH_WAIT_STATES)
#  error CONF_CLOCK_FLASH_WAIT_STATES not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_CPU_DIVIDER)
#  error CONF_CLOCK_CPU_DIVIDER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_APBA_DIVIDER)
#  error CONF_CLOCK_APBA_DIVIDER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_APBB_DIVIDER)
#  error CONF_CLOCK_APBB_DIVIDER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_APBC_DIVIDER)
#  error CONF_CLOCK_APBC_DIVIDER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC8M_PRESCALER)
#  error CONF_CLOCK_OSC8M_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC8M_ON_DEMAND)
#  error CONF_CLOCK_OSC8M_ON_DEMAND not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC8M_RUN_IN_STANDBY)
#  error CONF_CLOCK_OSC8M_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_ENABLE)
#  error CONF_CLOCK_XOSC_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_EXTERNAL_CRYSTAL)
#  error CONF_CLOCK_XOSC_EXTERNAL_CRYSTAL not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_EXTERNAL_FREQUENCY)
#  error CONF_CLOCK_XOSC_EXTERNAL_FREQUENCY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_STARTUP_TIME)
#  error CONF_CLOCK_XOSC_STARTUP_TIME not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_AUTO_GAIN_CONTROL)
#  error CONF_CLOCK_XOSC_AUTO_GAIN_CONTROL not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_ON_DEMAND)
#  error CONF_CLOCK_XOSC_ON_DEMAND not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC_RUN_IN_STANDBY)
#  error CONF_CLOCK_XOSC_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_ENABLE)
#  error CONF_CLOCK_XOSC32K_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_EXTERNAL_CRYSTAL)
#  error CONF_CLOCK_XOSC32K_EXTERNAL_CRYSTAL not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_STARTUP_TIME)
#  error CONF_CLOCK_XOSC32K_STARTUP_TIME not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_AUTO_AMPLITUDE_CONTROL)
#  error CONF_CLOCK_XOSC32K_AUTO_AMPLITUDE_CONTROL not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_ENABLE_1KHZ_OUPUT)
#  error CONF_CLOCK_XOSC32K_ENABLE_1KHZ_OUPUT not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_ENABLE_32KHZ_OUTPUT)
#  error CONF_CLOCK_XOSC32K_ENABLE_32KHZ_OUTPUT not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_ON_DEMAND)
#  error CONF_CLOCK_XOSC32K_ON_DEMAND not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_XOSC32K_RUN_IN_STANDBY)
#  error CONF_CLOCK_XOSC32K_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_ENABLE)
#  error CONF_CLOCK_OSC32K_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_STARTUP_TIME)
#  error CONF_CLOCK_OSC32K_STARTUP_TIME not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_ENABLE_1KHZ_OUTPUT)
#  error CONF_CLOCK_OSC32K_ENABLE_1KHZ_OUTPUT not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_ENABLE_32KHZ_OUTPUT)
#  error CONF_CLOCK_OSC32K_ENABLE_32KHZ_OUTPUT not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_ON_DEMAND)
#  error CONF_CLOCK_OSC32K_ON_DEMAND not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_OSC32K_RUN_IN_STANDBY)
#  error CONF_CLOCK_OSC32K_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_ENABLE)
#  error CONF_CLOCK_DFLL_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_LOOP_MODE)
#  error CONF_CLOCK_DFLL_LOOP_MODE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_ON_DEMAND)
#  error CONF_CLOCK_DFLL_ON_DEMAND not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_FINE_VALUE)
#  error CONF_CLOCK_DFLL_FINE_VALUE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_SOURCE_GCLK_GENERATOR)
#  error CONF_CLOCK_DFLL_SOURCE_GCLK_GENERATOR not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_MULTIPLY_FACTOR)
#  error CONF_CLOCK_DFLL_MULTIPLY_FACTOR not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_QUICK_LOCK)
#  error CONF_CLOCK_DFLL_QUICK_LOCK not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_TRACK_AFTER_FINE_LOCK)
#  error CONF_CLOCK_DFLL_TRACK_AFTER_FINE_LOCK not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_KEEP_LOCK_ON_WAKEUP)
#  error CONF_CLOCK_DFLL_KEEP_LOCK_ON_WAKEUP not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_ENABLE_CHILL_CYCLE)
#  error CONF_CLOCK_DFLL_ENABLE_CHILL_CYCLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_MAX_COARSE_STEP_SIZE)
#  error CONF_CLOCK_DFLL_MAX_COARSE_STEP_SIZE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_DFLL_MAX_FINE_STEP_SIZE)
#  error CONF_CLOCK_DFLL_MAX_FINE_STEP_SIZE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_CONFIGURE_GCLK)
#  error CONF_CLOCK_CONFIGURE_GCLK not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_0_ENABLE)
#  error CONF_CLOCK_GCLK_0_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_0_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_0_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_0_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_0_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_0_PRESCALER)
#  error CONF_CLOCK_GCLK_0_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_0_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_0_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_1_ENABLE)
#  error CONF_CLOCK_GCLK_1_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_1_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_1_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_1_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_1_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_1_PRESCALER)
#  error CONF_CLOCK_GCLK_1_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_1_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_1_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_2_ENABLE)
#  error CONF_CLOCK_GCLK_2_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_2_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_2_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_2_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_2_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_2_PRESCALER)
#  error CONF_CLOCK_GCLK_2_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_2_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_2_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_3_ENABLE)
#  error CONF_CLOCK_GCLK_3_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_3_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_3_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_3_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_3_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_3_PRESCALER)
#  error CONF_CLOCK_GCLK_3_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_3_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_3_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_4_ENABLE)
#  error CONF_CLOCK_GCLK_4_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_4_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_4_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_4_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_4_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_4_PRESCALER)
#  error CONF_CLOCK_GCLK_4_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_4_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_4_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_5_ENABLE)
#  error CONF_CLOCK_GCLK_5_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_5_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_5_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_5_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_5_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_5_PRESCALER)
#  error CONF_CLOCK_GCLK_5_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_5_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_5_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_6_ENABLE)
#  error CONF_CLOCK_GCLK_6_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_6_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_6_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_6_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_6_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_6_PRESCALER)
#  error CONF_CLOCK_GCLK_6_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_6_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_6_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_7_ENABLE)
#  error CONF_CLOCK_GCLK_7_ENABLE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_7_RUN_IN_STANDBY)
#  error CONF_CLOCK_GCLK_7_RUN_IN_STANDBY not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_7_CLOCK_SOURCE)
#  error CONF_CLOCK_GCLK_7_CLOCK_SOURCE not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_7_PRESCALER)
#  error CONF_CLOCK_GCLK_7_PRESCALER not defined in conf_clocks.h
#endif

#if !defined(CONF_CLOCK_GCLK_7_OUTPUT_ENABLE)
#  error CONF_CLOCK_GCLK_7_OUTPUT_ENABLE not defined in conf_clocks.h
#endif

#endif /* CLOCK_CONFIG_CHECK_H */
