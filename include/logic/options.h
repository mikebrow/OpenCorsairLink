/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017-2019  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _OPTIONS_H
#define _OPTIONS_H

#define _XOPEN_SOURCE 500

#include <getopt.h>
#include <stdint.h>

#include "logic/support.h"
#include "logic/suboptions.h"

struct option_flags {
  // flags
  // unsigned int debug_messages:1;
  unsigned int set_led : 1;
  unsigned int set_temperature : 1;
  unsigned int set_fan : 1;
  unsigned int set_pump : 1;
};

struct option_parse_return {
  struct led_control led_ctrl;
  struct fan_control fan_ctrl;
  struct pump_control pump_ctrl;
};

enum {
  OPTION_HELP = 0,
  OPTION_VERSION,
  OPTION_DEBUG,
  OPTION_DUMP,
  OPTION_MACHINE,
  OPTION_DEVICE,
  OPTION_FAN,
  OPTION_LED,
  OPTION_PUMP,
};

static struct option long_options[] = {
    {"help", no_argument, 0, OPTION_HELP},
    {"version", no_argument, 0, OPTION_VERSION},
    {"debug", no_argument, 0, OPTION_DEBUG},
    {"dump", no_argument, 0, OPTION_DUMP},
    {"machine", no_argument, 0, OPTION_MACHINE},
    {"device", required_argument, 0, OPTION_DEVICE},
    {"led", required_argument, 0, OPTION_LED},
    {"fan", required_argument, 0, OPTION_FAN},
    {"pump", required_argument, 0, OPTION_PUMP},
    {0, 0, 0, 0}};

#define INIT_WARNING_LED(xx)                                                   \
  xx.red = 0xFF;                                                               \
  xx.green = 0x00;                                                             \
  xx.blue = 0x00;

#define INIT_DEFAULT_LED(xx)                                                   \
  xx.red = 0xFF;                                                               \
  xx.green = 0xFF;                                                             \
  xx.blue = 0x00;

#define INIT_RAINBOW_LED(xx)                                                   \
  xx[0].red = 0xff;                                                            \
  xx[0].green = 0x00;                                                          \
  xx[0].blue = 0x00;                                                           \
  xx[1].red = 0xff;                                                            \
  xx[1].green = 0x80;                                                          \
  xx[1].blue = 0x00;                                                           \
  xx[2].red = 0xff;                                                            \
  xx[2].green = 0xff;                                                          \
  xx[2].blue = 0x00;                                                           \
  xx[3].red = 0x00;                                                            \
  xx[3].green = 0xff;                                                          \
  xx[3].blue = 0x00;                                                           \
  xx[4].red = 0x00;                                                            \
  xx[4].green = 0x00;                                                          \
  xx[4].blue = 0xff;                                                           \
  xx[5].red = 0x4b;                                                            \
  xx[5].green = 0x00;                                                          \
  xx[5].blue = 0x82;                                                           \
  xx[6].red = 0x7f;                                                            \
  xx[6].green = 0x00;                                                          \
  xx[6].blue = 0xff;

void options_print(void);

int options_parse(int argc, char **argv, struct option_flags *flags,
                  int8_t *device_number, struct option_parse_return *settings);

#endif
