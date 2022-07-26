/**
 * \file multilink_central_app.h
 *
 * \brief Multilink central application
 *
 * Copyright (c) 2018 Microchip Technology Inc. and its subsidiaries.
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
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef __MULTILINK_MULTIROLE_H__
#define __MULTILINK_MULTIROLE_H__

/* Length of event buffer */
#define EVENT_BUFFER_LENGTH		512

/* UUID for service and characteristics */
#define ACCE_GYRO_SENSOR_SERVICE_UUID	0x1b, 0xc5, 0xd5, 0xa5, 0x02, 0x00, 0xa6, 0x87, 0xe5, 0x11, 0x36, 0x39, 0xc1, 0xba, 0x5a, 0xf0
#define ACCE_UUID						0x1b, 0xc5, 0xd5, 0xa5, 0x02, 0x00, 0xa6, 0x87, 0xe5, 0x11, 0x36, 0x39, 0xd7, 0xba, 0x5a, 0xf0
#define GYRO_UUID						0x1b, 0xc5, 0xd5, 0xa5, 0x02, 0x00, 0xa6, 0x87, 0xe5, 0x11, 0x36, 0x39, 0xd4, 0xba, 0x5a, 0xf0

/* This application supports two sensor function, accelerometer and gyroscope */
#define NUMBER_OF_SENSORS		2

/* Total number of remote device supported */
#define MAX_REMOTE_DEVICE				4
/* Maximum remote peripheral device supported */
#define MAX_REMOTE_PERIPHERAL_DEVICE	4
/* Maximum remote central device supported */
#define MAX_REMOTE_CENTRAL_DEVICE		0


enum
{
	APP_DEVICE_ROLE_PERIPHERAL = 0x00,
	APP_DEVICE_ROLE_CENTRAL,
};

enum
{
	APP_STATE_DISCOVERY_PENDING = 0x01,
	APP_STATE_READY,
};

typedef enum
{
	SENSOR_1_ACCELEROMETER,
	SENSOR_2_GYROSCOPE,
}sensor_list_t;

typedef struct acc_sensor_value_t_
{
	uint16_t handle;
	int16_t x;
	int16_t y;
	int16_t z;
}acc_sensor_value_t;

typedef struct PACKED
{
	ble_handle_t char_attr_handle;
	uint8_t property;
	ble_handle_t char_value_attr_handle;
	ble_uuid_t	uuid;
	ble_handle_t cccd_handle;
	uint16_t cccd_value;
}sensor_char_t;

typedef struct PACKED
{
	ble_uuid_t service_uuid;
	uint8_t num_of_sensor_chars;
	sensor_char_t sensor_char_list[2];
}sensor_service_t;

typedef struct PACKED
{
	uint8_t in_use;
	uint8_t conn_handle;
	uint8_t dev_role;
	uint8_t state;
	ble_addr_t peer_addr;
	ble_conn_param_t conn_param;
	sensor_service_t sensor_service;
}app_ble_remote_device_info_t;


#endif /* __MULTILINK_MULTIROLE_H__ */
