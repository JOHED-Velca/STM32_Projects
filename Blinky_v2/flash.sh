#!/usr/bin/env bash
set -e

cmake --build cube/cube_blinky_v2/build/Debug
arm-none-eabi-objcopy -O binary cube/cube_blinky_v2/build/Debug/cube_blinky_v2.elf cube/cube_blinky_v2/build/Debug/cube_blinky_v2.bin
st-flash write cube/cube_blinky_v2/build/Debug/cube_blinky_v2.bin 0x08000000
st-flash reset || true

