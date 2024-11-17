/* Enumeration of CAN IDs as provided in the CAN DBC file:
 * CAN1-INDY-V17.dbc
 *
 * THIS FILE IS AUTOMATICALLY GENERATED. ANY DIRECT MODIFICATION TO THIS FILE IS
 * STRONGLY DISCOURAGED. YOUR CHANGES TO THIS FILE MAY BE LOST UPON RE-GENERATION.
 *
 * Copyright (c) 2024 Alvin Ye, All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RAPTOR_DBW_CAN__CANID_ENUM_HPP_
#define RAPTOR_DBW_CAN__CANID_ENUM_HPP_

#include <stdint.h>

namespace bridge
{
#undef BUILD_ASSERT

/** \brief Enumeration of CAN message IDs */
enum class MessageID : uint32_t
{

MYLAPS_REPORT_2 = 0xE2,
MYLAPS_REPORT_1 = 0xE4,
BASE_TO_CAR_SUMMARY = 0x4B0,
BASE_TO_CAR_TIMING = 0x4B8,
REST_OF_FIELD = 0x4B9,
MARELLI_REPORT_1 = 0x4E2,
MARELLI_REPORT_2 = 0x4E3,
WHEEL_SPEED_REPORT = 0x514,
BRAKE_PRESSURE_REPORT = 0x515,
ACCELERATOR_REPORT = 0x516,
STEERING_REPORT = 0x517,
MISC_REPORT = 0x518,
WHEEL_STRAIN_GAUGE = 0x51E,
WHEEL_POTENTIOMETER_DATA = 0x51F,
STEERING_REPORT_EXTD = 0x520,
STEERING_REPORT_EXTD_2 = 0x521,
BRAKE_REPORT_EXTD = 0x522,
BRAKE_REPORT_EXTD_2 = 0x523,
TIRE_PRESSURE_FL = 0x528,
TIRE_PRESSURE_FR = 0x529,
TIRE_PRESSURE_RL = 0x52A,
TIRE_PRESSURE_RR = 0x52B,
TIRE_TEMP_FL_1 = 0x52C,
TIRE_TEMP_FL_2 = 0x52D,
TIRE_TEMP_FL_3 = 0x52E,
TIRE_TEMP_FL_4 = 0x52F,
TIRE_TEMP_FR_1 = 0x530,
TIRE_TEMP_FR_2 = 0x531,
TIRE_TEMP_FR_3 = 0x532,
TIRE_TEMP_FR_4 = 0x533,
TIRE_TEMP_RL_1 = 0x534,
TIRE_TEMP_RL_2 = 0x535,
TIRE_TEMP_RL_3 = 0x536,
TIRE_TEMP_RL_4 = 0x537,
TIRE_TEMP_RR_1 = 0x538,
TIRE_TEMP_RR_2 = 0x539,
TIRE_TEMP_RR_3 = 0x53A,
TIRE_TEMP_RR_4 = 0x53B,
PT_REPORT_1 = 0x53C,
PT_REPORT_2 = 0x53D,
DIAGNOSTIC_REPORT = 0x53E,
PT_REPORT_3 = 0x53F,
NOVATEL_REPORT = 0x546,
BRAKE_PRESSURE_CMD = 0x578,
ACCELERATOR_CMD = 0x579,
STEERING_CMD = 0x57A,
GEAR_SHIFT_CMD = 0x57B,
CT_REPORT = 0x57C,
CT_REPORT_2 = 0x57D,
DASH_SWITCHES_CMD = 0x57E,
CT_VEHICLE_ACC_FEEDBACK = 0x5AA,
VECTOR__INDEPENDENT_SIG_MSG = 0xC0000000,

};

}       // namespace bridge

#endif  // RAPTOR_DBW_CAN__CANID_ENUM_HPP_

