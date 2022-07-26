/**
 * \file
 *
 * \brief User Interface
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

#include <asf.h>
#include "ui.h"
#include "ieee11073_skeleton.h"

static bool associated = false;

void ui_init(void)
{
	// Initialize LEDs
	LED_Off(LED_0_PIN);
}

void ui_powerdown(void)
{
	LED_Off(LED_0_PIN);
}


void ui_wakeup(void)
{
	LED_On(LED_0_PIN);
}

void ui_association(bool state)
{
	associated = state;
}

void ui_process(uint16_t framenumber)
{
	static uint8_t cpt_sof = 0;
	bool b_btn_state;
	static bool btn0_last_state = false;

	if (!associated) {
		if ((framenumber % 1000) == 0) {
			LED_On(LED_0_PIN);
		}
		if ((framenumber % 1000) == 500) {
			LED_Off(LED_0_PIN);
		}
	} else {
		LED_On(LED_0_PIN);
	}

	/* Scan process running each 20ms */
	cpt_sof++;
	if (20 > cpt_sof) {
		return;
	}

	cpt_sof = 0;

	/* Use buttons to send measures */
	b_btn_state = !port_pin_get_input_level(BUTTON_0_PIN);
	if (b_btn_state != btn0_last_state) {
		btn0_last_state = b_btn_state;
		if (b_btn_state) {
			ieee11073_skeleton_send_measure_1();
		}
	}
}

/**
 * \defgroup UI User Interface
 *
 * Human interface on SAML21-XPlain:
 * - LED0 blinks when USB host has checked and enabled PHDC interface
 * - LED0 is on when PHDC has validated association
 * - SW0 is used to send a measure
 *
 */
