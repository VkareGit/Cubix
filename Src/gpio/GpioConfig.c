/*
 * GpioConfig.c
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#include "gpio/GpioConfig.h"

GPIO_Status GPIO_PinInit(GPIO_InitTypeDef *init) {
    GPIO_EnableClock(init->port);

    // Configure mode using GPIO_ConfigureMode function
    GPIO_Status status = GPIO_ConfigureModeStruct(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure output type
    status = GPIO_ConfigureOutputTypeStruct(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure speed
    status = GPIO_ConfigureSpeedStruct(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure pull-up/pull-down
    status = GPIO_ConfigurePullStruct(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    return GPIO_STATUS_OK;
}

uint32_t pinNumberToValue(uint32_t pin) {
	    int pin_number = 0;

	    for (int i = 0; i < 16; i++) {
	        if (pin & (1 << i)) {
	            pin_number = i;
	            break;
	        }
	    }
	    return pin_number;
}

void GPIO_ModifyRegister(GPIO_TypeDef* GPIOx, uint32_t* reg, uint16_t Pin, uint32_t NewVal, uint32_t Mask) {
    uint16_t pin_number_value = pinNumberToValue(Pin);
    uint32_t reg_val = *reg;
    uint32_t mode_mask = Mask << (pin_number_value * GPIO_PIN_MULTIPLIER);
    reg_val &= ~mode_mask;
    reg_val |= (NewVal << (pin_number_value * GPIO_PIN_MULTIPLIER));
    *reg = reg_val;
}

GPIO_Status GPIO_ConfigureModeDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Mode Mode) {
    if (!IS_GPIO_PIN(Pin)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_MODE(Mode)) {
        return GPIO_STATUS_INVALID_MODE;
    }

    GPIO_ModifyRegister(GPIOx, &GPIOx->MODER, Pin, Mode, GPIO_MODE_MASK);
    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigureModeStruct(GPIO_InitTypeDef *config) {
    return GPIO_ConfigureModeDirect(config->port,config->pin_number,config->mode);
}

GPIO_Status GPIO_ConfigureSpeedDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Speed Speed) {
    if (!IS_GPIO_PIN(Pin)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_SPEED(Speed)) {
        return GPIO_STATUS_INVALID_SPEED;
    }

    GPIO_ModifyRegister(GPIOx, &GPIOx->OSPEEDR, Pin, Speed, GPIO_MODE_MASK);
    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigureSpeedStruct(GPIO_InitTypeDef *config) {
    return GPIO_ConfigureSpeedDirect(config->port,config->pin_number,config->speed);
}

GPIO_Status GPIO_ConfigureOutputTypeDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Type Type) {
    if (!IS_GPIO_PIN(Pin)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_TYPE(Type)) {
        return GPIO_STATUS_INVALID_TYPE;
    }

    uint32_t newVal = (Type == GPIO_TYPE_OPEN_DRAIN) ? GPIO_OUTPUT_TYPE_MASK : GPIO_RESET_VALUE;

    GPIO_ModifyRegister(GPIOx, &GPIOx->OTYPER, Pin, newVal, GPIO_OUTPUT_TYPE_MASK);
    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigureOutputTypeStruct(GPIO_InitTypeDef *config) {
    return GPIO_ConfigureOutputTypeDirect(config->port,config->pin_number,config->output_type);
}

GPIO_Status GPIO_ConfigurePullDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Pull Pull) {
    if (!IS_GPIO_PIN(Pin)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_PULL(Pull)) {
        return GPIO_STATUS_INVALID_PULL;
    }

    GPIO_ModifyRegister(GPIOx, &GPIOx->PUPDR, Pin, Pull, GPIO_MODE_MASK);
    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigurePullStruct(GPIO_InitTypeDef *config) {
    return GPIO_ConfigurePullDirect(config->port,config->pin_number,config->pull);
}
