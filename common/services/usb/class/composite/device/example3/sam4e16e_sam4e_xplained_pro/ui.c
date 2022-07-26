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

/*! Sequence process running each \c SEQUENCE_PERIOD ms */
#define SEQUENCE_PERIOD 150

/*! Wakeup, ignore button change until button is back to default state */
static bool btn_wakeup = false;

static struct {
	bool b_modifier;
	bool b_down;
	uint8_t u8_value;
} ui_sequence[] = {
	/* Display windows menu */
	{true,true,HID_MODIFIER_LEFT_UI},
	/* Launch Windows Command line */
	{false,true,HID_R},
	{false,false,HID_R},
	/* Clear modifier */
	{true,false,HID_MODIFIER_LEFT_UI},
	/* Tape sequence "notepad" + return */
	{false,true,HID_N},
	{false,false,HID_N},
	{false,true,HID_O},
	{false,false,HID_O},
	{false,true,HID_T},
	{false,false,HID_T},
	{false,true,HID_E},
	{false,false,HID_E},
	{false,true,HID_P},
	{false,false,HID_P},
	{false,true,HID_A},
	{false,false,HID_A},
	{false,true,HID_D},
	{false,false,HID_D},
	{false,true,HID_ENTER},
	{false,false,HID_ENTER},
	/* Delay to wait "notepad" focus */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	{false,false,0}, /* No key (= SEQUENCE_PERIOD delay) */
	/* Display "Atmel " */
	{true,true,HID_MODIFIER_RIGHT_SHIFT}, /* Enable Maj */
	{false,true,HID_A},
	{false,false,HID_A},
	{true,false,HID_MODIFIER_RIGHT_SHIFT}, /* Disable Maj */
	{false,true,HID_T},
	{false,false,HID_T},
	{false,true,HID_M},
	{false,false,HID_M},
	{false,true,HID_E},
	{false,false,HID_E},
	{false,true,HID_L},
	{false,false,HID_L},
	{false,true,HID_SPACEBAR},
	{false,false,HID_SPACEBAR},
	/* Display "ARM " */
	{false,true,HID_CAPS_LOCK}, /* Enable caps lock */
	{false,false,HID_CAPS_LOCK},
	{false,true,HID_A},
	{false,false,HID_A},
	{false,true,HID_R},
	{false,false,HID_R},
	{false,true,HID_M},
	{false,false,HID_M},
	{false,true,HID_CAPS_LOCK}, /* Disable caps lock */
	{false,false,HID_CAPS_LOCK},
};

/* Wakeup pin is push button (SW0) */
#define  WAKEUP_PIN      (GPIO_PUSH_BUTTON_1)
#define  WAKEUP_PIO      (PIN_PUSHBUTTON_1_PIO)
#define  WAKEUP_PIO_ID   (PIN_PUSHBUTTON_1_ID)
#define  WAKEUP_PIO_MASK (PIN_PUSHBUTTON_1_MASK)
#define  WAKEUP_PIO_ATTR \
	(PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_LOW_LEVEL)

/* Interrupt on "pin change" from push button to do wakeup on USB
 * Note:
 * This interrupt is enable when the USB host enable remotewakeup feature
 * This interrupt wakeup the CPU if this one is in idle mode
 */
static void ui_wakeup_handler(uint32_t id, uint32_t mask)
{
	if (WAKEUP_PIO_ID == id && WAKEUP_PIO_MASK == mask) {
		/* It is a wakeup then send wakeup USB */
		udc_remotewakeup();
	}
}

void ui_init(void)
{
	sleepmgr_lock_mode(SLEEPMGR_SLEEP_WFI);
	/* Set handler for push button */
	pio_handler_set(WAKEUP_PIO, WAKEUP_PIO_ID, WAKEUP_PIO_MASK,
		WAKEUP_PIO_ATTR, ui_wakeup_handler);
	/* Enable IRQ for button */
	NVIC_EnableIRQ((IRQn_Type) WAKEUP_PIO_ID);
	/* Initialize LED */
	LED_Off(LED0);
}

void ui_powerdown(void)
{
	LED_Off(LED0);
}


void ui_wakeup_enable(void)
{
	/* Configure PIO as input */
	pio_configure_pin(WAKEUP_PIN, WAKEUP_PIO_ATTR);
	/* Enable interrupt */
	pio_enable_pin_interrupt(WAKEUP_PIN);
}

void ui_wakeup_disable(void)
{
	/* Disable interrupt for button pin */
	pio_disable_pin_interrupt(WAKEUP_PIN);
}

void ui_wakeup(void)
{
	LED_On(LED0);
}


void ui_start_read(void)
{
}

void ui_stop_read(void)
{
}

void ui_start_write(void)
{
}

void ui_stop_write(void)
{
}

void ui_process(uint16_t framenumber)
{
	bool b_btn_state, success;
	static bool btn_last_state = false;
	static bool sequence_running = false;
	static uint8_t u8_sequence_pos = 0;
	uint8_t u8_value;
	static uint16_t cpt_sof = 0;

	if ((framenumber % 1000) == 0) {
		LED_On(LED0);
	}
	if ((framenumber % 1000) == 500) {
		LED_Off(LED0);
	}
	/* Scan process running each 2ms */
	cpt_sof++;
	if ((cpt_sof % 2) == 0) {
		return;
	}

	/* Buttons down to send keys sequence */
	b_btn_state = (!ioport_get_pin_level(GPIO_PUSH_BUTTON_1));
	if (b_btn_state != btn_last_state) {
		btn_last_state = b_btn_state;
		if (btn_wakeup) {
			if (!b_btn_state) {
				btn_wakeup = false;
			}
		} else {
			sequence_running = true;
		}
	}

	/* Sequence process running each period */
	if (SEQUENCE_PERIOD > cpt_sof) {
		return;
	}
	cpt_sof = 0;

	if (sequence_running) {
		/* Send next key */
		u8_value = ui_sequence[u8_sequence_pos].u8_value;
		if (u8_value!=0) {
			if (ui_sequence[u8_sequence_pos].b_modifier) {
				if (ui_sequence[u8_sequence_pos].b_down) {
					success = udi_hid_kbd_modifier_down(u8_value);
				} else {
					success = udi_hid_kbd_modifier_up(u8_value);
				}
			} else {
				if (ui_sequence[u8_sequence_pos].b_down) {
					success = udi_hid_kbd_down(u8_value);
				} else {
					success = udi_hid_kbd_up(u8_value);
				}
			}
			if (!success) {
				return; /* Retry it on next schedule */
			}
		}
		/* Valid sequence position */
		u8_sequence_pos++;
		if (u8_sequence_pos >=
			sizeof(ui_sequence) / sizeof(ui_sequence[0])) {
			u8_sequence_pos = 0;
			sequence_running = false;
		}
	}
}

void ui_kbd_led(uint8_t value)
{
	UNUSED(value);
}


/**
 * \defgroup UI User Interface
 *
 * Human interface on SAM4E-XPRO:
 * - LED0 blinks when USB host has checked and enabled Mouse and MSC interface
 * - SW0 down opens a notepad application on Windows O.S.
 *   and sends key sequence "Atmel ARM"
 * - Only SW0 down will generate a wakeup to USB Host in remote wakeup mode.
 *
 */
