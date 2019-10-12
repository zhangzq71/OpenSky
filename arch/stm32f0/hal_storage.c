/*
    Copyright 2017 fishpepper <AT> gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http:// www.gnu.org/licenses/>.

   author: fishpepper <AT> gmail.com
*/

#include <string.h>
#include "hal_storage.h"
#include "delay.h"
#include "debug.h"
#include "timeout.h"
#include "storage.h"
#include "stm32f0xx_hal.h"

#define FLASH_PAGE_SIZE 0x400U
#define FLASH_ROW_SIZE (FLASH_PAGE_SIZE)        // defined in the datasheet as 4x page size
#define FLASH_ERASE_VALUE (0xFF)                // value of flash after an erase

#define FLASH_ALLOCATE(name, size) \
    __attribute__((__aligned__(FLASH_ROW_SIZE))) \
    const uint8_t name[(size+(FLASH_ROW_SIZE-1))/FLASH_ROW_SIZE*FLASH_ROW_SIZE] = { 0xFFFF };


#define HAL_STORAGE_I2C_DEBUG 1

#define EEPROM_I2C_TIMEOUT      20
#define EEPROM_I2C_FLAG_TIMEOUT 10

// __attribute__((__aligned__(FLASH_ROW_SIZE))) const uint16_t NVM_flash[256] = {      // allocates 512 bytes
//     0xFFFF
// };

FLASH_ALLOCATE(NVM_flash, sizeof(storage));

static inline uint32_t read_unaligned_uint32(const void *data)
{
	union {
		uint32_t u32;
		uint8_t u8[4];
	} res;
	const uint8_t *d = (const uint8_t *)data;
	res.u8[0] = d[0];
	res.u8[1] = d[1];
	res.u8[2] = d[2];
	res.u8[3] = d[3];
	return res.u32;
}

static void flashWritePage(const volatile void *flash_ptr, const void *data, uint32_t size)
{
	// // Calculate data boundaries
	// size = (size + 3) / 4; //convert bytes to words with rounding

	// volatile uint32_t *dst_addr = (volatile uint32_t *)flash_ptr;
	// const uint8_t *src_addr = (uint8_t *)data;

	// if (0 != ((uint32_t)flash_ptr)%(FLASH_PAGE_SIZE))
	// {
	// 	debug("Flash page write must be on boundry\n");
	// 	return;
	// }

	// // Do writes in pages
	// while (size)
	// {
	// 	// Fill page buffer
	// 	uint32_t i;
	// 	for (i=0; i<(FLASH_PAGE_SIZE/4) && size; i++) //we write 4 bytes at a time
	// 	{
    //         FLASH_ProgramWord((uint32_t)dst_addr, read_unaligned_uint32(src_addr));
	// 		// *dst_addr = read_unaligned_uint32(src_addr);
	// 		src_addr += 4;
	// 		dst_addr++;
	// 		size--; //size is set to number of 32bit words in first line above
	// 	}
	// }
}

void hal_storage_init(void) {

}

void hal_storage_write(uint8_t *data, uint16_t size) {
	// uint32_t *ptrPage;
	// uint8_t *destPtr;
	// uint8_t *srcPtr;
	// uint32_t bytesInBlock;
	// __attribute__((__aligned__(4))) uint8_t buffer[FLASH_PAGE_SIZE];
	// uint32_t offset;

	// destPtr = (uint8_t *)NVM_flash;
	// srcPtr = (uint8_t *)data;

    // FLASH_Unlock();

	// while (size > 0)
	// {
	// 	uint32_t i, j;

	// 	// calculate the maximum number of bytes we can write in page
	// 	offset = ((uint32_t)destPtr) % (FLASH_PAGE_SIZE); // offset into page
	// 	bytesInBlock = FLASH_PAGE_SIZE - offset;		  // this is how many bytes we need to overwrite in this page

	// 	// get pointer to start of page
	// 	ptrPage = (uint32_t *)((((uint32_t)destPtr) / (FLASH_PAGE_SIZE)) * FLASH_PAGE_SIZE);

	// 	// fill page buffer with data from flash
	// 	memcpy(buffer, ptrPage, FLASH_PAGE_SIZE);

	// 	// now fill buffer with new data that needs changing
	// 	i = bytesInBlock;
	// 	if (size < i)
	// 		i = size;

	// 	memcpy(&buffer[offset], srcPtr, i);

	// 	//erase page
	// 	// flashErase(ptrPage, FLASH_PAGE_SIZE);
	// 	FLASH_ErasePage((uint32_t)ptrPage);
	// 	//write new data to flash
	// 	flashWritePage(ptrPage, buffer, FLASH_PAGE_SIZE);

	// 	size = size - i; // decrease number of bytes to write
	// 	srcPtr += i;	 // increase pointer to next bytes to read
	// 	destPtr += i;	//increment destination pointer
	// }

	// FLASH_Lock();
}


void hal_storage_read(uint8_t *storage_ptr, uint16_t len) {
    // memcpy(storage_ptr, NVM_flash, len);
}
