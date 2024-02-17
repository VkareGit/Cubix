/*
 * GpioOperations.C
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#include "gpio/GpioOperations.h"

void GPIO_TogglePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin) {
	BIT_TOGGLE(GPIOx->ODR,Pin);
}

void GPIO_TogglePinStruct(GPIO_InitTypeDef *config) {
	GPIO_TogglePinDirect(config->port->ODR,config->pin_number);
}

GPIO_PinState GPIO_ReadPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin) {
    return GPIO_READ_PIN(GPIOx,Pin);
}

GPIO_PinState GPIO_ReadPinStruct(GPIO_InitTypeDef *config) {
	return GPIO_ReadPinDirect(config->port,config->pin_number);
}

void GPIO_WritePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState) {
    if (PinState == GPIO_PIN_SET) {
    	BITMASK_SET(GPIOx->ODR,Pin);
    } else {
    	BITMASK_CLEAR(GPIOx->ODR,Pin);
    }
}

void GPIO_WritePinStruct(GPIO_InitTypeDef *config) {
    GPIO_WritePinDirect(config->port,config->pin_number,config->state);
}

void GPIO_SetResetPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState) {
	GPIO_SET_RESET_PIN(GPIOx,Pin,PinState);
}

void GPIO_SetResetPinStruct(GPIO_InitTypeDef *config) {
    GPIO_SetResetPinDirect(config->port,config->pin_number,config->state);
}
