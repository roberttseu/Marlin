/**
 * Marlin 3D Printer Firmware
<<<<<<< HEAD:Marlin/src/HAL/LINUX/hardware/LinearAxis.h
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
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.h
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

<<<<<<< HEAD:Marlin/src/HAL/LINUX/hardware/LinearAxis.h
#include <chrono>
#include "Gpio.h"

class LinearAxis: public Peripheral {
public:
  LinearAxis(pin_type enable, pin_type dir, pin_type step, pin_type end_min, pin_type end_max);
  virtual ~LinearAxis();
  void update();
  void interrupt(GpioEvent ev);

  pin_type enable_pin;
  pin_type dir_pin;
  pin_type step_pin;
  pin_type min_pin;
  pin_type max_pin;

  int32_t position;
  int32_t min_position;
  int32_t max_position;
  uint64_t last_update;

=======
//#ifdef STM32F7
//  #include <../../libraries/Servo/src/Servo.h>
//#else
  #include <Servo.h>
//#endif

// Inherit and expand on the official library
class libServo : public Servo {
  public:
    int8_t attach(const int pin);
    int8_t attach(const int pin, const int min, const int max);
    void move(const int value);
  private:
    typedef Servo super;
    uint16_t min_ticks, max_ticks;
    uint8_t servoIndex;               // index into the channel data for this servo
>>>>>>> 384da308fd33ad4eda83f2355ba88a23c87bb274:Marlin/src/HAL/HAL_STM32_F4_F7/Servo.h
};
