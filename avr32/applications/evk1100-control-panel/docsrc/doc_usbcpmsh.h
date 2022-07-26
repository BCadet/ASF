/*****************************************************************************
 *
 * \file
 *
 * \brief EVK1100 Control Panel USB Mass storage host scenario.
 *
 * The Control Panel application is a demonstration application. Its purpose is
 * to automatically log local sensors and actuators data and events and make
 * these available through the various connectivity channels supported by the
 * AVR32.\n
 * The logs are accessible locally through USART or USB (Mass Storage class),
 * and/or remotely through the Internet (Web server).\n
 * The Control Panel is locally configurable through USART or USB (Mass Storage
 * class) or remotely configurable through the Internet (Web server).
 *
 * - OS:                 FreeRTOS port on AVR32 UC3.
 * - Boards:             EVK1100
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

/*! \page UsbCpMassStorageHost Accessing the Control Panel acting as a USB Mass Storage host
 * In this scenario, you are a local user who wishes to access the Control Panel
 * through its USB interface. You are equipped with a USB key. The Control Panel
 * will behave as a USB Mass Storage host while the USB key will be a USB Mass
 * Storage device. Since the Control Panel behaves as a host in this mode, it has
 * full control over its own memory and over the memory of the attached USB device.
 * \note The Control Panel's Web server is fully reachable in this mode.
 *
 * \section UsbHostSwitchToMS 1) Plugging a USB key to the Control Panel.
 * Plug your USB key to a miniA plug to STD-A Receptacle OTG cable to adapt to
 * the miniA-B receptacle on the board the Control Panel is running on.
 * Then plug the cable to the board. Thou shall see the USB sign appear on the
 * LCD(last column of the second line), and the menu line of the LCD(3rd line)
 * should change as pictured on the following:\n
 * \n
 * \image html UsbMsHostCpLogs.gif
 * \n
 *
 * \section UsbHostMenuNavigation 2) Navigating through the menu.
 * The symbol on the last column of the menu line(a right arrow) tells the user
 * that there is another available action in this menu: to access it, push the
 * joystick to the right. You shall then see the following:\n
 * \n
 * \image html UsbMsHostMvLogs.gif
 * \n
 * The symbol on the first column of the menu line(a left arrow) tells the user
 * that there is a previous available action in the menu: to access it, push the
 * joystick to the left. You shall then go back to the previous screen(displaying
 * the <b><i>"Copy Logs"</i></b> action).
 *
 * \section UsbMsHostCpLogsAction 3) Copying the logs from the Control Panel to the USB key.
 * \n
 * \image html UsbMsHostCpLogs.gif
 *
 * To copy the data logs the Control Panel has been recording to the USB key,
 * press the joystick. This will create a /LOG directory on the USB key and
 * copy all the log files from the Control Panel's internal file system to that
 * directory.
 * The menu line will display a message while it is performing the requested action.
 * \n
 * \image html UsbMsHostCpLogsRunning.gif
 *
 * \note This will work only if the Control Panel has actually been recording
 * data log files; which can only be the case if the /LOG directory has been
 * created on the internal file system of the Control Panel (More on this in the
 * /ref ShellUsage scenario under the /ref ShellEnableTheLogs section).
 *
 * \section UsbMsHostMvLogsAction 4) Moving the logs from the Control Panel to the USB key.
 * \n
 * \image html UsbMsHostMvLogs.gif
 *
 * To move the data log files from the Control Panel's internal file system to
 * the USB key, press the joystick. This will move the content of the Control
 * Panel /LOG directory to a /LOG directory on the USB key.
 * The menu line will display a message while it is performing the requested
 * action.\n
 * \n
 * \image html UsbMsHostMvLogsRunning.gif
 *
 * \note This will work only if the Control Panel has actually been recording
 * data log files; which can only be the case if the /LOG directory has been
 * created on the internal file system of the Control Panel (More on this in
 * the /ref ShellUsage scenario under the /ref ShellEnableTheLogs section).
 *
 * \section UsbMsHostUploadWebAction 5) Uploading the Web server files.
 * \n
 * \image html UsbMsHostUploadWeb.gif
 *
 * The USB key may hold a /WEB directory holding a version of the web server files.
 * To update or add the WEB server files of the Control Panel, press the joystick.
 * The content of the USB key /WEB directory will be copied over to the Control Panel
 * file system /WEB directory.
 * The menu line will display a message while it is performing the requested
 * action.\n
 * \n
 * \image html UsbMsHostUploadWebRunning.gif
 * \n
 *
 * \section UsbMsHostUploadCfgAction 6) Uploading the configuration files.
 * \n
 * \image html UsbMsHostUploadCfg.gif
 *
 * The USB key may hold a /CFG directory holding sensors & system configuration text files.
 * To update or add configuration files of the Control Panel, press the joystick.
 * The content of the USB key /CFG directory will be copied over to the Control Panel
 * file system /CFG directory. Note that we've reached the end of the menu (no right
 * arrow on the last column of the third line of the LCD).
 * The menu line will display a message while it is performing the requested action.
 * \n
 * \image html UsbMsHostUploadCfgRunning.gif
 * \n
 *
 * <HR>
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.microchip.com/design-centers/32-bit /">Atmel AVR32</A>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
