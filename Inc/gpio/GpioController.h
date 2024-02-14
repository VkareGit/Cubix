/*
 * GpioController.h
 *
 *  Created on: Feb 14, 2024
 *      Author: vkare
 */

#ifndef GPIO_GPIOCONTROLLER_H_
#define GPIO_GPIOCONTROLLER_H_

#include "gpio/GpioTypes.h"

#define GPIO_PIN_MASK            ((uint32_t)0x0000FFFF)

#define IS_GPIO_PIN_STATE(STATE) (((STATE) == GPIO_PIN_RESET) || ((STATE) == GPIO_PIN_SET))

#define IS_GPIO_PIN(PIN)           (((PIN) & GPIO_PIN_MASK ) != (uint32_t)0x00)

#define IS_GPIO_TYPE(TYPE) (((TYPE) == GPIO_TYPE_PUSH_PULL) || ((TYPE) == GPIO_TYPE_OPEN_DRAIN))

#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_SPEED_LOW) || \
                              ((SPEED) == GPIO_SPEED_MEDIUM) || ((SPEED) == GPIO_SPEED_HIGH) || \
							  ((SPEED) == GPIO_SPEED_VERY_HIGH))

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT) ||\
                            ((MODE) == GPIO_MODE_OUTPUT) ||\
                            ((MODE) == GPIO_MODE_ALTERNATE) ||\
                            ((MODE) == GPIO_MODE_ANALOG))

#define IS_GPIO_PUPDR(PUPDR) (((PUPDR) == GPIO_PUPDR_NO_PULL_UP_NO_PULL_DOWN) ||\
                              ((PUPDR) == GPIO_PUPDR_PULL_UP) ||\
                              ((PUPDR) == GPIO_PUPDR_PULL_DOWN) ||\
                              ((PUPDR) == GPIO_PUPDR_RESERVED))


#define IS_GPIO_AFR(AFR) 	 (((AFR) == GPIO_AF0) || \
                              ((AFR) == GPIO_AF1) || ((AFR) == GPIO_AF2) || \
							  ((AFR) == GPIO_AF3) || ((AFR) == GPIO_AF4) || \
							  ((AFR) == GPIO_AF5) || ((AFR) == GPIO_AF6) || \
							  ((AFR) == GPIO_AF7) || ((AFR) == GPIO_AF8) || \
							  ((AFR) == GPIO_AF9) || ((AFR) == GPIO_AF10) || \
							  ((AFR) == GPIO_AF11) || ((AFR) == GPIO_AF12) || \
							  ((AFR) == GPIO_AF13) || ((AFR) == GPIO_AF14) || \
							  ((AFR) == GPIO_AF15))


typedef struct {
    GPIO_TypeDef* port;
    uint8_t pin_number;
    GPIO_Mode mode;
    GPIO_Type output_type;
    GPIO_Speed speed;
    GPIO_Pupdr pull;
}GPIO_InitTypeDef;

typedef enum {
    GPIO_STATUS_OK = 0,
    GPIO_STATUS_ERROR,
    GPIO_STATUS_INVALID_PIN,
    GPIO_STATUS_INVALID_MODE,
} GPIO_Status;

#endif /* GPIO_GPIOCONTROLLER_H_ */
