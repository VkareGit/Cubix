/*
 * GpioAdvanced.c
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#include "gpio/GpioAdvanced.h"

GPIO_Status GPIO_LockPinDirect(GPIO_TypeDef* GPIOx, uint16_t Pin) {
    uint32_t temp = GPIO_LOCK_KEY | Pin; // LCKK [16] + Pin
    GPIOx->LCKR = temp;                // Write 1
    GPIOx->LCKR = Pin;                 // Write 0
    GPIOx->LCKR = temp;                // Write 1
    temp = GPIOx->LCKR;                // Read
    temp = GPIOx->LCKR;                // Read again
    if (GPIOx->LCKR & GPIO_LOCK_KEY) {   // Confirm lock
        return GPIO_STATUS_OK;
    }
    return GPIO_STATUS_ERROR;
}

GPIO_Status GPIO_LockPinStruct(GPIO_InitTypeDef *config) {
    return GPIO_LockPinDirect(config->port,config->pin_number);
}

void GPIO_SetAlternateFunctionDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, uint8_t AF) {
    uint32_t afrIndex, afrShift;
    if (Pin < GPIO_PIN_8) {
        afrIndex = GPIO_AFR_LOW_INDEX; // Low register
    } else {
        afrIndex = GPIO_AFR_HIGH_INDEX; // High register
        Pin -= GPIO_AFRH_OFFSET;
    }
    afrShift = (uint32_t)Pin * GPIO_AFR_SHIFT_MULTIPLIER;
    GPIOx->AFR[afrIndex] &= ~(GPIO_AFRL_MASK << afrShift); // Clear AF selection
    GPIOx->AFR[afrIndex] |= ((uint32_t)AF << afrShift); // Set new AF
}

void GPIO_SetAlternateFunctionStruct(GPIO_InitTypeDef *config) {
    GPIO_SetAlternateFunctionDirect(config->port,config->pin_number,config->af);
}
