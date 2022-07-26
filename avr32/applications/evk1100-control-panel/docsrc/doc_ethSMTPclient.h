/*****************************************************************************
 *
 * \file
 *
 * \brief EVK1100 Control Panel SMTP client scenario.
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

/*! \page EthSMTPClient Configuring and using the Control Panel SMTP client
 * In this scenario, you are a local user who wishes to use the Control Panel
 * to send mail upon alarms or with periodic logs. You are equipped with a PC.
 *
 * \note This scenario assumes you already have set up your local area network to access the Control Panel web server.
 * See \ref EthWebServer for further informations on the network configuration.
 *
 * \section EthPcConfig 1) SMTP server set up [Windows XP]
 * You will need a SMTP server. There are several configurations, so we assume your EVK1100 is plugged to your PC, as described in the web server section.\n
 * You can use Windows XP SMTP server or download a free one.\n
 * See also \ref SmtpServerCygwin for details on installing and configuring a GNU(GPL) SMTP server included with Cygwin(exim).\n
 * Once you have a SMTP server configured, you will need to set up the Control Panel to have it sending mails.\n
 *
 * \section EthSMTPCompilation 2) Compile the Control Panel with the SMTP client.
 * Default Control Panel application does not come with the SMTP client compiled.\n
 * If you want to know if SMTP is embedded in your Control Panel version, use the web server and browse for the <i><b>"System Configuration"</b></i> web page.\n
 * If the SMTP fields are filled with <i><b>NotCompiled</b></i> text, then you will have to add SMTP client to your version.\n
 * Otherwise, you should directly go to chapter \ref EthSMTPConfiguration.\n
 * You will have to turn it on in your favorite compilation environment.\n
 *
 * \subsection EthSMTPCompilationGCC 2.1) Using GCC.
 * Edit the file <i><b>"config.mk"</b></i>  and replace SMTP_USED=0 with SMTP_USED=1 in the definitions.\n
 * Then build the Control Panel and program your EVK1100 with this new version.\n
 *
 * \subsection EthSMTPCompilationIAR 2.2) Using IAR.
 * Right click on the project and select options. In the new window, choose C/C++ compilers item and go to the preprocessor tab.\n
 * In the section <i><b>Defined symbols: (one per line)</b></i>, edit SMTP_USED field and set SMTP_USED=1 to enable SMTP compilation.\n
 * \image html PreprocessorOptions.gif
 * Then build the Control Panel and program your EVK1100 with this new version.\n
 *
 * \section EthSMTPConfiguration 3) Configure the SMTP client.
 * You now have to configure your SMTP client to have it deliver mails to the SMTP server.\n
 * Use the web server and browse for the <i><b>"System Configuration"</b></i> web page.\n
 * Fill the SMTP section fields with :\n
 * <ul>
 * <li>Server TCP port : enter the SMTP server port, default should be 25.</li>
 * <li>Outgoing server address : enter the SMTP server IP address :
 *   <ul>
 *     <li>If you are using a SMTP server installed on your PC, use the PC IP address (default should be <em>192.168.0.54</em>)</li>
 *     <li>If you don't know the IP address of your SMTP server, you can use <i>tracert your.smtp.server.name</i> commands to get it, where your.smtp.server.name is the name of a SMTP server you are able to use.</li>
 *   </ul>
 * <li>Mail recipient : enter the recipient of the mails. Fill with a valid email address.</li>
 * <li>Mail sender : enter the sender of the mails. Fill with a valid email address, that SMTP server would allow to access.</li>
 * </ul>
 *
 * \section EthMailConfiguration 4) Configure the Control Panel to send mail.
 * The Control Panel will send mail  to the recipient previously configured upon several actions :
 * - each time a log file is definitely closed, the Control Panel should sent the file content.
 * - each time an alarm is triggered, the Control Panel should sent an email to inform of this occurrence.
 *
 * \subsection EthMailConfigurationLog 4.1) Log files.
 * You do not have to set up anything to allow the Control Panel to send mail upon this event.\n
 * Once a log file has reached the maximum file size, it is written on the file system.\n
 * Then an email will be sent with this file content.\n
 * \note In order to receive log files, you MUST have a LOG folder on your file system.\n
 *
 * \subsection EthMailConfigurationAlarm 4.2) Configure the Control Panel to send mail.
 * In order to trigger an alarm on a sensor, you will have to allow it for this sensor.\n
 * Browse the <i><b>"Sensors Configuration"</b></i> web page, and set the alarm field for this sensor to value <i><b>"on"</b></i>. Submit this change by clicking the <i><b>"submit"</b></i> button.\n
 * Trigger an alarm for the configured sensor, and check your mailbox, you should have a new message.\n
 *
 * <HR>
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.microchip.com/design-centers/32-bit">Atmel AVR32</A>.\n
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
