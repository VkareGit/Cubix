/*
 * GpioOperations.C
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#include "gpio/GpioOperations.h"

void GPIO_TogglePinStruct(GPIO_InitTypeDef *config) {
    config->port->ODR ^= config->pin_number;
}

void GPIO_TogglePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin) {
	GPIOx->ODR ^= Pin;
}

GPIO_PinState GPIO_ReadPinStruct(GPIO_InitTypeDef *config) {
    return (config->port->IDR & config->pin_number) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

GPIO_PinState GPIO_ReadPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin) {
    return (GPIOx->IDR & Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void GPIO_WritePinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState) {
    if (PinState == GPIO_PIN_SET) {
        GPIOx->ODR |= Pin;
    } else {
        GPIOx->ODR &= ~Pin;
    }
}

void GPIO_WritePinStruct(GPIO_InitTypeDef *config) {
    GPIO_WritePinDirect(config->port,config->pin_number,config->state);
}

void GPIO_SetResetPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_PinState PinState) {
    if (PinState == GPIO_PIN_SET) {
        GPIOx->BSRR = (uint32_t)Pin;
    } else {
        GPIOx->BSRR = (uint32_t)Pin << GPIO_BSRR_RESET_OFFSET;
    }
}

void GPIO_SetResetPinStruct(GPIO_InitTypeDef *config) {
    GPIO_SetResetPinDirect(config->port,config->pin_number,config->state);
}
