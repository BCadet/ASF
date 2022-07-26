/*****************************************************************************
 *
 * \file
 *
 * \brief Hamming ECC software implementation.
 *
 * This file contains a software Hamming ECC implementation.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "nand.h"
#include "ecc-sw.h"

/*! \brief Pre-calculated parity table
 *
 *  This table is a pre-calculation of the 256 possible parities used when
 *  calculating ECC. Each value in this table represents a 6-bit value of
 *  the column parity and a 1-bit value of the row parity.
 *
 *  Storage form: null [7], row parity [6], column parity [5:0]
 */
static const unsigned char ecc_parity_table[] = {
	0x00, 0x55, 0x56, 0x03, 0x59, 0x0c, 0x0f, 0x5a, 0x5a, 0x0f,
	0x0c, 0x59, 0x03, 0x56, 0x55, 0x00, 0x65, 0x30, 0x33, 0x66,
	0x3c, 0x69, 0x6a, 0x3f, 0x3f, 0x6a, 0x69, 0x3c, 0x66, 0x33,
	0x30, 0x65, 0x66, 0x33, 0x30, 0x65, 0x3f, 0x6a, 0x69, 0x3c,
	0x3c, 0x69, 0x6a, 0x3f, 0x65, 0x30, 0x33, 0x66, 0x03, 0x56,
	0x55, 0x00, 0x5a, 0x0f, 0x0c, 0x59, 0x59, 0x0c, 0x0f, 0x5a,
	0x00, 0x55, 0x56, 0x03, 0x69, 0x3c, 0x3f, 0x6a, 0x30, 0x65,
	0x66, 0x33, 0x33, 0x66, 0x65, 0x30, 0x6a, 0x3f, 0x3c, 0x69,
	0x0c, 0x59, 0x5a, 0x0f, 0x55, 0x00, 0x03, 0x56, 0x56, 0x03,
	0x00, 0x55, 0x0f, 0x5a, 0x59, 0x0c, 0x0f, 0x5a, 0x59, 0x0c,
	0x56, 0x03, 0x00, 0x55, 0x55, 0x00, 0x03, 0x56, 0x0c, 0x59,
	0x5a, 0x0f, 0x6a, 0x3f, 0x3c, 0x69, 0x33, 0x66, 0x65, 0x30,
	0x30, 0x65, 0x66, 0x33, 0x69, 0x3c, 0x3f, 0x6a, 0x6a, 0x3f,
	0x3c, 0x69, 0x33, 0x66, 0x65, 0x30, 0x30, 0x65, 0x66, 0x33,
	0x69, 0x3c, 0x3f, 0x6a, 0x0f, 0x5a, 0x59, 0x0c, 0x56, 0x03,
	0x00, 0x55, 0x55, 0x00, 0x03, 0x56, 0x0c, 0x59, 0x5a, 0x0f,
	0x0c, 0x59, 0x5a, 0x0f, 0x55, 0x00, 0x03, 0x56, 0x56, 0x03,
	0x00, 0x55, 0x0f, 0x5a, 0x59, 0x0c, 0x69, 0x3c, 0x3f, 0x6a,
	0x30, 0x65, 0x66, 0x33, 0x33, 0x66, 0x65, 0x30, 0x6a, 0x3f,
	0x3c, 0x69, 0x03, 0x56, 0x55, 0x00, 0x5a, 0x0f, 0x0c, 0x59,
	0x59, 0x0c, 0x0f, 0x5a, 0x00, 0x55, 0x56, 0x03, 0x66, 0x33,
	0x30, 0x65, 0x3f, 0x6a, 0x69, 0x3c, 0x3c, 0x69, 0x6a, 0x3f,
	0x65, 0x30, 0x33, 0x66, 0x65, 0x30, 0x33, 0x66, 0x3c, 0x69,
	0x6a, 0x3f, 0x3f, 0x6a, 0x69, 0x3c, 0x66, 0x33, 0x30, 0x65,
	0x00, 0x55, 0x56, 0x03, 0x59, 0x0c, 0x0f, 0x5a, 0x5a, 0x0f,
	0x0c, 0x59, 0x03, 0x56, 0x55, 0x00,
};

/*! \brief Generate ECC for a 256 byte block.
 *
 *  This function will generate a 3 byte ECC for a 256 byte data block.
 *
 *  \param ecc Pointer to a variable to store the calculated ECC.
 *  \param data Pointer to a 256 byte large buffer to calculate the ECC
 *              value of.
 */
void ecc_make_block_256b(unsigned long *ecc, unsigned char *data)
{
	unsigned int i;
	unsigned char *data_p = data;

	unsigned char row_parity0;
	unsigned char row_parity1;
	unsigned char col_parity = 0;
	unsigned char row_parity_odd = 0;
	unsigned char row_parity_even = 0;

	for (i = 0; i < NAND_ECC_CHUNK_SIZE; i++) {
		/* Fetch pre-calculated ECC value from table. */
		unsigned char byte_parity = ecc_parity_table[*data_p++];

		/* Only 6 LSB are related to column parity. */
		col_parity ^= byte_parity & 0x3f;

		/* If the row parity is 1 we toggle the value for related
		 * rows. Even rows have the inverted value of odd rows.
		 */
		if (byte_parity & 0x40) {
			row_parity_odd  ^=  i;
			row_parity_even ^= ~i;
		}
	}

	/* Move the even and odd bits into proper ECC form. */
	row_parity0 = ((row_parity_even     & 0x01) << 0)
			| ((row_parity_odd  & 0x01) << 1)
			| ((row_parity_even & 0x02) << 1)
			| ((row_parity_odd  & 0x02) << 2)
			| ((row_parity_even & 0x04) << 2)
			| ((row_parity_odd  & 0x04) << 3)
			| ((row_parity_even & 0x08) << 3)
			| ((row_parity_odd  & 0x08) << 4);
	row_parity1 = ((row_parity_even     & 0x10) >> 4)
			| ((row_parity_odd  & 0x10) >> 3)
			| ((row_parity_even & 0x20) >> 3)
			| ((row_parity_odd  & 0x20) >> 2)
			| ((row_parity_even & 0x40) >> 2)
			| ((row_parity_odd  & 0x40) >> 1)
			| ((row_parity_even & 0x80) >> 1)
			| ((row_parity_odd  & 0x80) >> 0);

	*ecc = row_parity0 | (row_parity1 << 8) | (0x03 << 16)
			| (col_parity << 18);
}

/*! \brief Compare two ECCs for a 256 byte block.
 *
 *  This function will compare two 3 byte ECC for a 256 byte data block.
 *  If an error is found the compare function will provide a fix if a single
 *  one bit error is found. Multiple errors are not possible to fix.
 *
 *  \param ecc1 Pointer to a variable for ECC value to compare against ecc2.
 *  \param ecc2 Pointer to a variable for ECC value to compare against ecc1.
 *  \param data Pointer to a 256 byte large buffer used when calculating the
 *              ecc1 and ecc2 ECC values.
 *  \param error_offset Pointer to a variable to store the byte offset of a
 *                      detected single bit error.
 *  \param corrected_value Pointer to a variable to store the corrected byte
 *                         if a single bit error was detected.
 *
 *  \return 0 on success, an error number otherwise.
 */
int ecc_compare_block_256b(unsigned long *ecc1, unsigned long *ecc2,
				unsigned char *data,
				unsigned long *error_offset,
				unsigned char *corrected_value)
{
	unsigned int i;
	unsigned int bit_index;
	unsigned int ecc_xored;
	unsigned int byte_index;
	unsigned int bit_count = 0;

	if (*ecc1 == *ecc2) {
		return SUCCESS;
	}

	ecc_xored = *ecc1 ^ *ecc2;

	for (i = 0; i < 24; i++) {
		bit_count += ((ecc_xored >> i) & 0x1);
	}

	switch (bit_count) {
	case 0:
		return SUCCESS;
	case 1:
		return -ENANDECC_BADECC;
	case 11:
		/* Check if ECC is damaged. */
		if (((ecc_xored & 0x02) >> 1) + (ecc_xored & 0x01) != 1) {
			return -ENANDECC_BADECC;
		}

		bit_index = ((ecc_xored >> 19)       & 0x01)
				| ((ecc_xored >> 20) & 0x02)
				| ((ecc_xored >> 21) & 0x04);

		byte_index = ((ecc_xored >> 1)      & 0x01)
				| ((ecc_xored >> 2) & 0x02)
				| ((ecc_xored >> 3) & 0x04)
				| ((ecc_xored >> 4) & 0x08)
				| ((ecc_xored >> 5) & 0x10)
				| ((ecc_xored >> 6) & 0x20)
				| ((ecc_xored >> 7) & 0x40)
				| ((ecc_xored >> 8) & 0x80);

		*error_offset = byte_index;
		*corrected_value = (data[byte_index] ^ (1 << bit_index));

		return -ENANDECC_CORRECTABLE;
	default:
		return -ENANDECC_UNCORRECTABLE;
	}
}
