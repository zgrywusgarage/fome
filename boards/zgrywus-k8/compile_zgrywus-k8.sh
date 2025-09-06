#!/bin/bash

export USE_OPENBLT=no
export EXTRA_PARAMS="-DDUMMY -DSHORT_BOARD_NAME=zgrywus-k8"

bash ../common_make.sh zgrywus-k8 ARCH_STM32F4
