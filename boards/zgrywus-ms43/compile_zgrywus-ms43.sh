#!/bin/bash

export USE_OPENBLT=no
export EXTRA_PARAMS="-DDUMMY -DSHORT_BOARD_NAME=zgrywus-ms43"

bash ../common_make.sh zgrywus-ms43 ARCH_STM32F4
