/*****************************************************************************
 *
 * \file
 *
 * \brief CTRL_ACCESS interface for SD/MMC card.
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
 ******************************************************************************/
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */


#ifndef _SD_MMC_MCI_MEM_H_
#define _SD_MMC_MCI_MEM_H_

/**
 * \defgroup group_avr32_components_memory_sd_mmc_sd_mmc_mci_mem SD/MMC MCI Memory
 *
 * \ingroup group_avr32_components_memory_sd_mmc_sd_mmc_mci
 *
 * \{
 */

#include "conf_access.h"

#if SD_MMC_MCI_0_MEM == DISABLE && SD_MMC_MCI_1_MEM == DISABLE
  #error sd_mmc_mem_mci.h is #included although SD_MMC_MCI_x_MEM are all disabled
#endif


#include "ctrl_access.h"


//_____ D E F I N I T I O N S ______________________________________________

/*! \name SD/MMC Status
 *
 * Status List for the SD/MMC
 *
 */
//! @{
#define   SD_MMC_REMOVED       0
#define   SD_MMC_INSERTED      1
#define   SD_MMC_REMOVING      2
//! @}


//_____ D E C L A R A T I O N S ____________________________________________

/*! \name Control Interface
 */
//! @{

/*! \brief Tests the memory state and initializes the memory if required.
 *
 * The TEST UNIT READY SCSI primary command allows an application client to poll
 * a LUN until it is ready without having to allocate memory for returned data.
 *
 * This command may be used to check the media status of LUNs with removable
 * media.
 *
 * \param slot SD/MMC Slot Card Selected.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_test_unit_ready(uint8_t slot);
//! Instance Declaration for sd_mmc_mci_test_unit_ready Slot O
extern Ctrl_status sd_mmc_mci_test_unit_ready_0(void);
//! Instance Declaration for sd_mmc_mci_test_unit_ready Slot 1
extern Ctrl_status sd_mmc_mci_test_unit_ready_1(void);

/*! \brief Returns the address of the last valid sector in the memory.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param u32_nb_sector Pointer to the address of the last valid sector.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_read_capacity(uint8_t slot,uint32_t *u32_nb_sector);
//! Instance Declaration for sd_mmc_mci_read_capacity Slot O
extern Ctrl_status sd_mmc_mci_read_capacity_0(uint32_t *u32_nb_sector);
//! Instance Declaration for sd_mmc_mci_read_capacity Slot 1
extern Ctrl_status sd_mmc_mci_read_capacity_1(uint32_t *u32_nb_sector);

/*! \brief Returns the write-protection state of the memory.
 *
*  \param slot SD/MMC Slot Card Selected.
 * \return \c true if the memory is write-protected, else \c false.
 *
 * \note Only used by removable memories with hardware-specific write
 *       protection.
 */
extern bool sd_mmc_mci_wr_protect(uint8_t slot);
//! Instance Declaration for sd_mmc_mci_wr_protect Slot O
extern bool sd_mmc_mci_wr_protect_0(void);
//! Instance Declaration for sd_mmc_mci_wr_protect Slot 1
extern bool sd_mmc_mci_wr_protect_1(void);

/*! \brief Tells whether the memory is removable.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \return \c true if the memory is removable, else \c false.
 */
extern bool sd_mmc_mci_removal(uint8_t slot);
//! Instance Declaration for sd_mmc_mci_removal Slot O
extern bool sd_mmc_mci_removal_0(void);
//! Instance Declaration for sd_mmc_mci_removal Slot 1
extern bool sd_mmc_mci_removal_1(void);

//! @}


#if ACCESS_USB == true

/*! \name MEM <-> USB Interface
 */
//! @{

/*! \brief Transfers data from the memory to USB.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr      Address of first memory sector to read.
 * \param nb_sector Number of sectors to transfer.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_usb_read_10(uint8_t slot,uint32_t addr, uint16_t nb_sector);
//! Instance Declaration for sd_mmc_mci_usb_read_10 Slot O
extern Ctrl_status sd_mmc_mci_usb_read_10_0(uint32_t addr, uint16_t nb_sector);
//! Instance Declaration for sd_mmc_mci_usb_read_10 Slot 1
extern Ctrl_status sd_mmc_mci_usb_read_10_1(uint32_t addr, uint16_t nb_sector);

/*! \brief Transfers data from USB to the memory.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr      Address of first memory sector to write.
 * \param nb_sector Number of sectors to transfer.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_usb_write_10(uint8_t slot,uint32_t addr, uint16_t nb_sector);
//! Instance Declaration for sd_mmc_mci_usb_write_10 Slot O
extern Ctrl_status sd_mmc_mci_usb_write_10_0(uint32_t addr, uint16_t nb_sector);
//! Instance Declaration for sd_mmc_mci_usb_write_10 Slot 1
extern Ctrl_status sd_mmc_mci_usb_write_10_1(uint32_t addr, uint16_t nb_sector);

//! @}

#endif


#if ACCESS_MEM_TO_RAM == true

/*! \name MEM <-> RAM Interface
 */
//! @{

/*! \brief Copies 1 data sector from the memory to RAM.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr  Address of first memory sector to read.
 * \param ram   Pointer to RAM buffer to write.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_mem_2_ram(uint8_t slot, uint32_t addr, void *ram);
extern Ctrl_status sd_mmc_mci_dma_mem_2_ram(uint8_t slot, uint32_t addr, void *ram);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot O
extern Ctrl_status sd_mmc_mci_mem_2_ram_0(uint32_t addr, void *ram);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot 1
extern Ctrl_status sd_mmc_mci_mem_2_ram_1(uint32_t addr, void *ram);

/*! \brief Copies 1 data sector from RAM to the memory.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr  Address of first memory sector to write.
 * \param ram   Pointer to RAM buffer to read.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_ram_2_mem(uint8_t slot, uint32_t addr, const void *ram);
extern Ctrl_status sd_mmc_mci_dma_ram_2_mem(uint8_t slot, uint32_t addr, const void *ram);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot O
extern Ctrl_status sd_mmc_mci_ram_2_mem_0(uint32_t addr, const void *ram);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot 1
extern Ctrl_status sd_mmc_mci_ram_2_mem_1(uint32_t addr, const void *ram);

/*! \brief Copies nb_sectors data sector from the memory to RAM.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr         Address of first memory sector to read.
 * \param ram          Pointer to RAM buffer to write.
 * \param nb_sectors   Number of sectors to read.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_multiple_mem_2_ram(uint8_t slot,uint32_t addr, void *ram, uint32_t nb_sectors);
extern Ctrl_status sd_mmc_mci_dma_multiple_mem_2_ram(uint8_t slot,uint32_t addr, void *ram, uint32_t nb_sectors);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot O
extern Ctrl_status sd_mmc_mci_multiple_mem_2_ram_0(uint32_t addr, void *ram, uint32_t nb_sectors);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot 1
extern Ctrl_status sd_mmc_mci_multiple_mem_2_ram_1(uint32_t addr, void *ram, uint32_t nb_sectors);

/*! \brief Copies nb_sectors data sector from RAM to the memory.
 *
 * \param slot SD/MMC Slot Card Selected.
 * \param addr         Address of first memory sector to write.
 * \param ram          Pointer to RAM buffer to read.
 * \param nb_sectors   Number of sectors to write.
 *
 * \return Status.
 */
extern Ctrl_status sd_mmc_mci_multiple_ram_2_mem(uint8_t slot, uint32_t addr, const void *ram, uint32_t nb_sectors);
extern Ctrl_status sd_mmc_mci_dma_multiple_ram_2_mem(uint8_t slot, uint32_t addr, const void *ram, uint32_t nb_sectors);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot O
extern Ctrl_status sd_mmc_mci_multiple_ram_2_mem_0(uint32_t addr, const void *ram, uint32_t nb_sectors);
//! Instance Declaration for sd_mmc_mci_mem_2_ram Slot 1
extern Ctrl_status sd_mmc_mci_multiple_ram_2_mem_1(uint32_t addr, const void *ram, uint32_t nb_sectors);

//! @}

#endif

/**
 * \}
 */

#endif  // _SD_MMC_MCI_MEM_H_
