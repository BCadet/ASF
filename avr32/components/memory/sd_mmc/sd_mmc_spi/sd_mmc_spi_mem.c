/*****************************************************************************
 *
 * \file
 *
 * \brief CTRL_ACCESS interface for SD/MMC card.
 *
 * Copyright (c) 2009-2018 Microchip Technology Inc. and its subsidiaries.
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


//_____  I N C L U D E S ___________________________________________________

#include "conf_access.h"


#if SD_MMC_SPI_MEM == ENABLE

#include "conf_sd_mmc_spi.h"
#include "sd_mmc_spi.h"
#include "sd_mmc_spi_mem.h"


//_____ M A C R O S ________________________________________________________

#define Sd_mmc_spi_access_signal_on()
#define Sd_mmc_spi_access_signal_off()


//_____ P R I V A T E    D E C L A R A T I O N _____________________________


//_____ D E F I N I T I O N ________________________________________________

//extern xdata uint32_t sd_mmc_spi_mem_size;
extern            uint32_t SD_MMC_SPI_DISK_SIZE;
extern volatile   uint32_t sd_mmc_spi_last_address;
extern            bool     sd_mmc_spi_init_done;

                  uint8_t  sd_mmc_spi_presence_status = SD_MMC_INSERTED;
extern            bool     sd_mmc_spi_init_done;


//_____ D E C L A R A T I O N ______________________________________________


void sd_mmc_spi_mem_init(void)
{
  sd_mmc_spi_internal_init();        // Restart Init of SD/MMC card after previous first init
}



Ctrl_status sd_mmc_spi_test_unit_ready(void)
{
  Sd_mmc_spi_access_signal_on();
  switch (sd_mmc_spi_presence_status)
  {
    case SD_MMC_REMOVED:
      sd_mmc_spi_init_done = false;
      if (sd_mmc_spi_mem_check())
      {
        sd_mmc_spi_presence_status = SD_MMC_INSERTED;
        Sd_mmc_spi_access_signal_off();
        return CTRL_BUSY;
      }
      Sd_mmc_spi_access_signal_off();
      return CTRL_NO_PRESENT;

    case SD_MMC_INSERTED:
      if (!sd_mmc_spi_mem_check())
      {
        sd_mmc_spi_presence_status = SD_MMC_REMOVING;
        sd_mmc_spi_init_done = false;
        Sd_mmc_spi_access_signal_off();
        return CTRL_BUSY;
      }
      Sd_mmc_spi_access_signal_off();
      return CTRL_GOOD;

    case SD_MMC_REMOVING:
      sd_mmc_spi_presence_status = SD_MMC_REMOVED;
      Sd_mmc_spi_access_signal_off();
      return CTRL_NO_PRESENT;

    default:
      sd_mmc_spi_presence_status = SD_MMC_REMOVED;
      Sd_mmc_spi_access_signal_off();
      return CTRL_BUSY;
  }

/*
  if (sd_mmc_spi_mem_check())
  {
    if (!sd_mmc_spi_status_changed)
    {
      sd_mmc_spi_status_changed = true;
      return CTRL_BUSY;     // BUSY token must be returned to indicate a status change !
    }
    else
      return CTRL_GOOD;     // the 2nd time the host will ask for unit_ready, we can answer GOOD if we have returned BUSY first !
  }
  else
  {
    if (sd_mmc_spi_status_changed)
    {
      sd_mmc_spi_status_changed = false;
      return CTRL_BUSY;     // BUSY token must be returned to indicate a status change !
    }
    else
      return CTRL_NO_PRESENT;
  }
*/
}



Ctrl_status sd_mmc_spi_read_capacity(uint32_t *nb_sector)
{
//   sd_mmc_spi_check_presence();   // omitted because creates interferences with "sd_mmc_spi_test_unit_ready()" function
   Sd_mmc_spi_access_signal_on();

   if (!sd_mmc_spi_init_done)
   {
      sd_mmc_spi_mem_init();
   }

   if (sd_mmc_spi_init_done)
   {
     *nb_sector = sd_mmc_spi_last_block_address+1;
     Sd_mmc_spi_access_signal_off();
     return CTRL_GOOD;
   }
   else
   {
     Sd_mmc_spi_access_signal_off();
     return CTRL_NO_PRESENT;
   }
}


//!
//! @brief This function returns the write protected status of the memory.
//!
//! Only used by memory removal with a HARDWARE SPECIFIC write protected detection
//! ! The user must unplug the memory to change this write protected status,
//! which cannot be for a SD_MMC.
//!
//! @return false  -> the memory is not write-protected (always)
//!/
bool  sd_mmc_spi_wr_protect(void)
{
   return false;
}


//!
//! @brief This function tells if the memory has been removed or not.
//!
//! @return false  -> The memory isn't removed
//!/
bool  sd_mmc_spi_removal(void)
{
  return false;
//  return ((sd_mmc_spi_check_presence()) ? false : true);
}



//------------ STANDARD FUNCTIONS to read/write the memory --------------------

#if ACCESS_USB == true

#include "conf_usb.h"
#ifdef USB_DEVICE_VENDOR_ID
  // USB Device Stack V2
#include "udi_msc.h"
#else
  // USB Device Stack V1
#include "usb_drv.h"
#include "scsi_decoder.h"
#endif

Ctrl_status sd_mmc_spi_usb_read_10(uint32_t addr, uint16_t nb_sector)
{
   if (!sd_mmc_spi_init_done)
   {
      sd_mmc_spi_mem_init();
   }

   if (!sd_mmc_spi_init_done)
     return CTRL_NO_PRESENT;

   Sd_mmc_spi_access_signal_on();

   if( !sd_mmc_spi_read_open(addr) )
     goto sd_mmc_spi_usb_read_10_fail;

   if( !sd_mmc_spi_read_multiple_sector(nb_sector) )
     goto sd_mmc_spi_usb_read_10_fail;

   if( !sd_mmc_spi_read_close() )
     goto sd_mmc_spi_usb_read_10_fail;

   Sd_mmc_spi_access_signal_off();
   return CTRL_GOOD;

sd_mmc_spi_usb_read_10_fail:
   Sd_mmc_spi_access_signal_off();
   return CTRL_FAIL;
}


void sd_mmc_spi_read_multiple_sector_callback(const void *psector)
{
#ifdef USB_DEVICE_VENDOR_ID
   // USB Device Stack V2
   udi_msc_trans_block( true, (uint8_t*)psector, MMC_SECTOR_SIZE, NULL);
#else
  // USB Device Stack V1
  uint16_t data_to_transfer = MMC_SECTOR_SIZE;

  while (data_to_transfer)
  {
    while (!Is_usb_in_ready(g_scsi_ep_ms_in));

    Usb_reset_endpoint_fifo_access(g_scsi_ep_ms_in);
    data_to_transfer = usb_write_ep_txpacket(g_scsi_ep_ms_in, psector,
                                             data_to_transfer, &psector);
    Usb_ack_in_ready_send(g_scsi_ep_ms_in);
  }
#endif
}



Ctrl_status sd_mmc_spi_usb_write_10(uint32_t addr, uint16_t nb_sector)
{
  bool status;

   if (!sd_mmc_spi_init_done)
   {
      sd_mmc_spi_mem_init();
   }

   if (sd_mmc_spi_init_done)
   {
     Sd_mmc_spi_access_signal_on();
     sd_mmc_spi_write_open(addr);
     status = sd_mmc_spi_write_multiple_sector(nb_sector);
     sd_mmc_spi_write_close();
     Sd_mmc_spi_access_signal_off();
     if (status)
       return CTRL_GOOD;
     else
       return CTRL_NO_PRESENT;
   }
   else
     return CTRL_NO_PRESENT;
}


void sd_mmc_spi_write_multiple_sector_callback(void *psector)
{
#ifdef USB_DEVICE_VENDOR_ID
   // USB Device Stack V2
   udi_msc_trans_block( false, (uint8_t*)psector, MMC_SECTOR_SIZE, NULL);
#else
  // USB Device Stack V1
  uint16_t data_to_transfer = MMC_SECTOR_SIZE;

  while (data_to_transfer)
  {
    while (!Is_usb_out_received(g_scsi_ep_ms_out));

    Usb_reset_endpoint_fifo_access(g_scsi_ep_ms_out);
    data_to_transfer = usb_read_ep_rxpacket(g_scsi_ep_ms_out, psector,
                                            data_to_transfer, &psector);
    Usb_ack_out_received_free(g_scsi_ep_ms_out);
  }
#endif
}

#endif // ACCESS_USB == true


//------------ Standard functions for read/write 1 sector to 1 sector ram buffer -----------------

#if ACCESS_MEM_TO_RAM == true

Ctrl_status sd_mmc_spi_mem_2_ram(uint32_t addr, void *ram)
{
   Sd_mmc_spi_access_signal_on();
   sd_mmc_spi_check_presence();

   if (!sd_mmc_spi_init_done)
   {
      sd_mmc_spi_mem_init();
   }

   if (!sd_mmc_spi_init_done)
     return CTRL_NO_PRESENT;

   if( !sd_mmc_spi_read_open(addr) )
     goto sd_mmc_spi_mem_2_ram_fail;

   if( !sd_mmc_spi_read_sector_to_ram(ram))
     goto sd_mmc_spi_mem_2_ram_fail;

   if( !sd_mmc_spi_read_close() )
     goto sd_mmc_spi_mem_2_ram_fail;

   Sd_mmc_spi_access_signal_off();
   return CTRL_GOOD;

sd_mmc_spi_mem_2_ram_fail:
   Sd_mmc_spi_access_signal_off();
   return CTRL_FAIL;
}


//! This function initializes the memory for a write operation
//! from ram buffer to SD/MMC (1 sector)
//!
//!         DATA FLOW is: RAM => SD/MMC
//!
//! (sector = 512B)
//! @param addr         Sector address to write
//! @param ram          Ram buffer pointer
//!
//! @return                Ctrl_status
//!   It is ready      ->    CTRL_GOOD
//!   An error occurs  ->    CTRL_FAIL
//!
Ctrl_status    sd_mmc_spi_ram_2_mem(uint32_t addr, const void *ram)
{
   Sd_mmc_spi_access_signal_on();
   sd_mmc_spi_check_presence();

   if (!sd_mmc_spi_init_done)
   {
      sd_mmc_spi_mem_init();
   }

   if (sd_mmc_spi_init_done)
   {
     sd_mmc_spi_write_open(addr);
     if (!sd_mmc_spi_write_sector_from_ram(ram))
     {
       sd_mmc_spi_write_close();
       Sd_mmc_spi_access_signal_off();
       return CTRL_NO_PRESENT;
     }
     sd_mmc_spi_write_close();
     Sd_mmc_spi_access_signal_off();
     return CTRL_GOOD;
   }
   Sd_mmc_spi_access_signal_off();

   return CTRL_NO_PRESENT;
}


#endif // ACCESS_MEM_TO_RAM == true


#endif  // SD_MMC_SPI_MEM == ENABLE
