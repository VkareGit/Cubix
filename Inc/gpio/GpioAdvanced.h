/*
 * GpioAdvanced.h
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#ifndef GPIO_ADVANCED_H_
#define GPIO_ADVANCED_H_

#include "GpioTypes.h"
#include "stm32/stm32f407xx.h"

#define GPIO_LOCK_KEY           0x00010000U
#define GPIO_AFRL_MASK          0xFU
#define GPIO_AFRH_OFFSET        8
#define GPIO_BSRR_RESET_OFFSET  16
#define GPIO_AFR_LOW_INDEX      0
#define GPIO_AFR_HIGH_INDEX     1
#define GPIO_AFR_SHIFT_MULTIPLIER 4

GPIO_Status GPIO_LockPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin);
GPIO_Status GPIO_LockPinStruct(GPIO_InitTypeDef *config);
void GPIO_SetAlternateFunctionDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, uint8_t AF);
void GPIO_SetAlternateFunctionStruct(GPIO_InitTypeDef *config);

#endif /* GPIO_ADVANCED_H_ */
