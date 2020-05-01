/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/eeprom.cpp
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
=======
 *
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/STM32F1/persistent_store_eeprom.cpp
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/eeprom.cpp
#ifdef __MK20DX256__

#include "../../inc/MarlinConfig.h"

#if USE_WIRED_EEPROM

#include "../shared/eeprom_api.h"
=======

#ifdef __STM32F1__

#include "../../inc/MarlinConfig.h"

#if ENABLED(EEPROM_SETTINGS) && EITHER(SPI_EEPROM, I2C_EEPROM)
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/STM32F1/persistent_store_eeprom.cpp

#include "../shared/persistent_store_api.h"

bool PersistentStore::access_start() {
  #if ENABLED(SPI_EEPROM)
    #if SPI_CHAN_EEPROM1 == 1
      SET_OUTPUT(BOARD_SPI1_SCK_PIN);
      SET_OUTPUT(BOARD_SPI1_MOSI_PIN);
      SET_INPUT(BOARD_SPI1_MISO_PIN);
      SET_OUTPUT(SPI_EEPROM1_CS);
    #endif
    spiInit(0);
  #endif
  return true;
}
bool PersistentStore::access_finish() { return true; }

bool PersistentStore::write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc) {
  while (size--) {
    uint8_t * const p = (uint8_t * const)pos;
    uint8_t v = *value;
    // EEPROM has only ~100,000 write cycles,
    // so only write bytes that have changed!
    if (v != eeprom_read_byte(p)) {
      eeprom_write_byte(p, v);
      if (eeprom_read_byte(p) != v) {
        SERIAL_ECHO_MSG(STR_ERR_EEPROM_WRITE);
        return true;
      }
    }
    crc16(crc, &v, 1);
    pos++;
    value++;
  };
  return false;
}

bool PersistentStore::read_data(int &pos, uint8_t* value, size_t size, uint16_t *crc, const bool writing/*=true*/) {
  do {
    uint8_t c = eeprom_read_byte((uint8_t*)pos);
    if (writing && value) *value = c;
    crc16(crc, &c, 1);
    pos++;
    value++;
  } while (--size);
  return false;
}

<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/eeprom.cpp
#endif // USE_WIRED_EEPROM
#endif // __MK20DX256__
=======
size_t PersistentStore::capacity() { return E2END + 1; }

#endif // EEPROM_SETTINGS && EITHER(SPI_EEPROM, I2C_EEPROM)
#endif // __STM32F1__
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/STM32F1/persistent_store_eeprom.cpp
