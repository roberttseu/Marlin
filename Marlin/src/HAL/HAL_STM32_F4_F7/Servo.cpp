/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/Servo.cpp
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
=======
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (c) 2017 Victor Perez
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.cpp
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
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/Servo.cpp
#ifdef __MK20DX256__
=======

#if defined(STM32GENERIC) && (defined(STM32F4) || defined(STM32F7))
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.cpp

#include "../../inc/MarlinConfig.h"

#if HAS_SERVOS

#include "Servo.h"
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/Servo.cpp

uint8_t servoPin[MAX_SERVOS] = { 0 };

int8_t libServo::attach(const int inPin) {
  if (servoIndex >= MAX_SERVOS) return -1;
  if (inPin > 0) servoPin[servoIndex] = inPin;
  return super::attach(servoPin[servoIndex]);
}

int8_t libServo::attach(const int inPin, const int inMin, const int inMax) {
  if (inPin > 0) servoPin[servoIndex] = inPin;
  return super::attach(servoPin[servoIndex], inMin, inMax);
=======

int8_t libServo::attach(const int pin) {
  if (servoIndex >= MAX_SERVOS) return -1;
  return super::attach(pin);
}

int8_t libServo::attach(const int pin, const int min, const int max) {
  return super::attach(pin, min, max);
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.cpp
}

void libServo::move(const int value) {
  constexpr uint16_t servo_delay[] = SERVO_DELAY;
  static_assert(COUNT(servo_delay) == NUM_SERVOS, "SERVO_DELAY must be an array NUM_SERVOS long.");
  if (attach(0) >= 0) {
    write(value);
    safe_delay(servo_delay[servoIndex]);
<<<<<<< HEAD:Marlin/src/HAL/TEENSY31_32/Servo.cpp
    TERN_(DEACTIVATE_SERVOS_AFTER_MOVE, detach());
  }
}

#endif // HAS_SERVOS

#endif // __MK20DX256__
=======
    #if ENABLED(DEACTIVATE_SERVOS_AFTER_MOVE)
      detach();
    #endif
  }
}

#endif // HAS_SERVOS
#endif // STM32GENERIC && (STM32F4 || STM32F7)
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.cpp
