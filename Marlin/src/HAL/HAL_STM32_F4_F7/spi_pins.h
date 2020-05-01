/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/STM32_F4_F7/spi_pins.h
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
=======
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/spi_pins.h
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
#pragma once

/**
 * Define SPI Pins: SCK, MISO, MOSI, SS
 */
#ifndef SCK_PIN
  #define SCK_PIN   PA5
#endif
#ifndef MISO_PIN
  #define MISO_PIN  PA6
#endif
#ifndef MOSI_PIN
  #define MOSI_PIN  PA7
#endif
#ifndef SS_PIN
  #define SS_PIN    PA8
#endif
