/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/STM32_F4_F7/watchdog.cpp
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
=======
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/watchdog.cpp
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
<<<<<<< HEAD:Marlin/src/HAL/STM32_F4_F7/watchdog.cpp
=======

>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/watchdog.cpp
#if defined(STM32GENERIC) && (defined(STM32F4) || defined(STM32F7))

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

  #include "watchdog.h"

  IWDG_HandleTypeDef hiwdg;

  void watchdog_init() {
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32; //32kHz LSI clock and 32x prescalar = 1024Hz IWDG clock
    hiwdg.Init.Reload = 4095;           //4095 counts = 4 seconds at 1024Hz
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
      //Error_Handler();
    }
    else {
<<<<<<< HEAD:Marlin/src/HAL/STM32_F4_F7/watchdog.cpp
      #if PIN_EXISTS(LED) && DISABLED(PINS_DEBUGGING)
=======
      #if PIN_EXISTS(LED) && !ENABLED(PINS_DEBUGGING)
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/watchdog.cpp
        TOGGLE(LED_PIN);  // heartbeat indicator
      #endif
    }
  }

  void HAL_watchdog_refresh() {
    /* Refresh IWDG: reload counter */
    if (HAL_IWDG_Refresh(&hiwdg) != HAL_OK) {
      /* Refresh Error */
      //Error_Handler();
    }
  }

#endif // USE_WATCHDOG
#endif // STM32GENERIC && (STM32F4 || STM32F7)
