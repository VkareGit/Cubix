/*
 * gpioController.h
 *
 *  Created on: Feb 14, 2024
 *      Author: vkare
 */

#ifndef GPIO_GPIOCONTROLLER_H_
#define GPIO_GPIOCONTROLLER_H_

typedef enum {
    GPIO_MODE_INPUT = 0,          // 00: Input mode
    GPIO_MODE_OUTPUT = 1,         // 01: General purpose output mode
    GPIO_MODE_ALTERNATE = 2,      // 10: Alternate function mode
    GPIO_MODE_ANALOG = 3          // 11: Analog mode
} GPIO_Mode;


typedef struct {
	GPIO_TypeDef* port;
    uint8_t pin_number;
    GPIO_Mode mode;
}GPIO_MODER_Config;


void GPIO_ConfigureMode(GPIO_MODER_Config *config) {

    uint32_t moder_reg_val = config->port->MODER;

    uint32_t mode_mask = 0x3 << (config->pin_number * 2);

    moder_reg_val &= ~mode_mask;

    moder_reg_val |= ((uint32_t)(config->mode) << (config->pin_number * 2));

    config->port->MODER = moder_reg_val;
}


#endif /* GPIO_GPIOCONTROLLER_H_ */
