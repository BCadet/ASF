/*****************************************************************************
 *
 * \file
 *
 * \brief ET024006DHU TFT display driver example.
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
 *****************************************************************************/

/*! \mainpage
 * \section intro Introduction
 * This is the documentation for the ET024006DHU TFT display driver example.
 *
 * \section files Main Files
 * - et024006dhu.c, .h: the ET024006DHU driver;
 * - et024006dhu_example.c: the example 1
 * - smc_et024006dhu.h: SMC configuration
 *
 * \section compilinfo Compilation Information
 * This software is written for GNU GCC for AVR32 and for IAR Embedded Workbench
 * for Atmel AVR32. Other compilers may or may not work.
 *
 * \section deviceinfo Device Information
 * All AVR32 devices with an EBI and SMC module can be used.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.microchip.com/design-centers/32-bit">Atmel AVR UC3</A>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "board.h"
#include "gpio.h"
#include "power_clocks_lib.h"
#include "et024006dhu.h"
#include "delay.h"
#include "avr32_logo.h"
#include "conf_clock.h"

#if BOARD == EVK1105
#include "pwm.h"
avr32_pwm_channel_t pwm_channel6 = {
/*
  .cmr = ((PWM_MODE_LEFT_ALIGNED << AVR32_PWM_CMR_CALG_OFFSET)
    | (PWM_POLARITY_HIGH << AVR32_PWM_CMR_CPOL_OFFSET)
    | (PWM_UPDATE_DUTY << AVR32_PWM_CMR_CPD_OFFSET)
    | AVR32_PWM_CMR_CPRE_MCK_DIV_2),
    */
  //.cdty = 0,
  .cdty = 0,
  .cprd = 100
};

static void tft_bl_init(void)
{

  pwm_opt_t opt = {
    .diva = 0,
    .divb = 0,
    .prea = 0,
    .preb = 0
  };
  /* MCK = OSC0 = 12MHz
   * Desired output 60kHz
   * Chosen MCK_DIV_2
   * CPRD = 12MHz / (60kHz * 2) = 100
   *
   * The duty cycle is 100% (CPRD = CDTY)
   * */
  pwm_init(&opt);
  pwm_channel6.CMR.calg = PWM_MODE_LEFT_ALIGNED;
  pwm_channel6.CMR.cpol = PWM_POLARITY_HIGH; //PWM_POLARITY_LOW;//PWM_POLARITY_HIGH;
  pwm_channel6.CMR.cpd = PWM_UPDATE_DUTY;
  pwm_channel6.CMR.cpre = AVR32_PWM_CMR_CPRE_MCK_DIV_2;

  pwm_channel_init(6, &pwm_channel6);
  pwm_start_channels(AVR32_PWM_ENA_CHID6_MASK);

}
#endif

// Main function
int main(void)
{
  U32 i;

  // Set CPU and PBA clock
  pcl_switch_to_osc(PCL_OSC0, FOSC0, OSC0_STARTUP);

  gpio_enable_gpio_pin(LED0_GPIO);
  gpio_enable_gpio_pin(LED1_GPIO);
  gpio_enable_gpio_pin(LED2_GPIO);
  gpio_enable_gpio_pin(LED3_GPIO);

  et024006_Init( FOSC0, FOSC0 );

#if BOARD == EVK1105
  /* PWM is fed by PBA bus clock which is by default the same
   * as the CPU speed. We set a 0 duty cycle and thus keep the
   * display black*/
  tft_bl_init();
#elif BOARD == EVK1104 || BOARD == UC3C_EK
  gpio_set_gpio_pin(ET024006DHU_BL_PIN);
#endif

  // Clear the display i.e. make it black
  et024006_DrawFilledRect(0 , 0, ET024006_WIDTH, ET024006_HEIGHT, BLACK );

  // Draw the background AVR32 logo.
  et024006_PutPixmap(avr32_logo, 320, 0, 0, 0, 0, 320, 240);

  // Display lines of colored squares.
  for( i=0 ; i<16 ; i++ )
  {
    // From black to white.
    et024006_DrawFilledRect(20*i,   0, 20, 20, (2*i)/*B:5*/ | ((4*i)<<5)/*G:6*/ | ((2*i)<<11)/*R:5*/ );
    // From black to blue.
    et024006_DrawFilledRect(20*i,  20, 20, 20, (2*i) /*B:5*/);
    // From black to green
    et024006_DrawFilledRect(20*i, 200, 20, 20, ((4*i)<<5) /*G:6*/);
    // From black to red
    et024006_DrawFilledRect(20*i, 220, 20, 20, ((2*i)<<11) /*R:5*/);
  }


#if BOARD == EVK1105
  /* Lets do a nice fade in by increasing the duty cycle */
  while(pwm_channel6.cdty < pwm_channel6.cprd)
  {
    pwm_channel6.cdty++;
    pwm_channel6.cupd = pwm_channel6.cdty;
    //pwm_channel6.cdty--;
    pwm_async_update_channel(AVR32_PWM_ENA_CHID6, &pwm_channel6);
    delay_ms(10);
  }
#endif

  // Display text.
  et024006_PrintString("AVR UC3", (const unsigned char *)&FONT6x8, 80, 50, BLUE, -1);
  et024006_PrintString("AVR UC3", (const unsigned char *)&FONT8x8, 80, 60, BLACK, -1);

  // Draw a crossed square.
  et024006_DrawHorizLine(10, 50, 20, BLACK);
  et024006_DrawVertLine(10, 50, 20, BLACK);
  et024006_DrawHorizLine(10, 70, 20, BLACK);
  et024006_DrawVertLine(30, 50, 20, BLACK);
  et024006_DrawLine(10, 50, 30, 70, BLACK);
  et024006_DrawLine(30, 50, 10, 70, BLACK);

  while(true);
}
