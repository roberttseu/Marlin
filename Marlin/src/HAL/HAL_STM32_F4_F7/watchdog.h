/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/STM32_F4_F7/watchdog.h
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
=======
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/watchdog.h
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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

extern IWDG_HandleTypeDef hiwdg;

void watchdog_init();
void HAL_watchdog_refresh();
