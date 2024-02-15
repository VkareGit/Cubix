/*
 * GpioOperations.h
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#ifndef GPIO_OPERATIONS_H_
#define GPIO_OPERATIONS_H_

#include "GpioTypes.h"
#include "stm32/stm32f407xx.h"

#define GPIO_BSRR_RESET_OFFSET  16

void GPIO_TogglePinStruct(GPIO_InitTypeDef *config);
void GPIO_TogglePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin);
GPIO_PinState GPIO_ReadPinStruct(GPIO_InitTypeDef *config);
GPIO_PinState GPIO_ReadPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin);
void GPIO_WritePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState);
void GPIO_WritePinStruct(GPIO_InitTypeDef *config);
void GPIO_SetResetPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState);
void GPIO_SetResetPinStruct(GPIO_InitTypeDef *config);

#endif /* GPIO_OPERATIONS_H_ */
