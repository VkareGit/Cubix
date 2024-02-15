/*
 * GpioClock.c
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#include "gpio/GpioClock.h"

static GPIO_ClockState gpioClockState = {0};

void GPIO_EnableClock(GPIO_TypeDef* GPIOx) {
    if (GPIOx == GPIOA && !gpioClockState.GPIOA_Enabled) {
        __GPIOA_CLK_ENABLE();
        gpioClockState.GPIOA_Enabled = 1;
    } else if (GPIOx == GPIOB && !gpioClockState.GPIOB_Enabled) {
        __GPIOB_CLK_ENABLE();
        gpioClockState.GPIOB_Enabled = 1;
    } else if (GPIOx == GPIOC && !gpioClockState.GPIOC_Enabled) {
        __GPIOC_CLK_ENABLE();
        gpioClockState.GPIOC_Enabled = 1;
    } else if (GPIOx == GPIOD && !gpioClockState.GPIOD_Enabled) {
        __GPIOD_CLK_ENABLE();
        gpioClockState.GPIOD_Enabled = 1;
    } else if (GPIOx == GPIOE && !gpioClockState.GPIOE_Enabled) {
        __GPIOE_CLK_ENABLE();
        gpioClockState.GPIOE_Enabled = 1;
    } else if (GPIOx == GPIOF && !gpioClockState.GPIOF_Enabled) {
        __GPIOF_CLK_ENABLE();
        gpioClockState.GPIOF_Enabled = 1;
    } else if (GPIOx == GPIOG && !gpioClockState.GPIOG_Enabled) {
        __GPIOG_CLK_ENABLE();
        gpioClockState.GPIOG_Enabled = 1;
    } else if (GPIOx == GPIOH && !gpioClockState.GPIOH_Enabled) {
        __GPIOH_CLK_ENABLE();
        gpioClockState.GPIOH_Enabled = 1;
    } else if (GPIOx == GPIOI && !gpioClockState.GPIOI_Enabled) {
        __GPIOI_CLK_ENABLE();
        gpioClockState.GPIOI_Enabled = 1;
    }
}
