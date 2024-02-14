/*
 *  GpioTypes.h
 *
 *  Created on: Feb 14, 2024
 *      Author: vkare
 */

#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET = 1
} GPIO_PinState;

typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_ALTERNATE = 2,
    GPIO_MODE_ANALOG = 3
} GPIO_Mode;

typedef enum {
	GPIO_TYPE_PUSH_PULL = 0,
	GPIO_TYPE_OPEN_DRAIN = 1
} GPIO_Type;

typedef enum {
	GPIO_SPEED_LOW = 0,
	GPIO_SPEED_MEDIUM = 1,
	GPIO_SPEED_HIGH = 2,
	GPIO_SPEED_VERY_HIGH = 3
} GPIO_Speed;

typedef enum {
	GPIO_PUPDR_NO_PULL_UP_NO_PULL_DOWN = 0,
	GPIO_PUPDR_PULL_UP = 1,
	GPIO_PUPDR_PULL_DOWN = 2,
	GPIO_PUPDR_RESERVED = 3
} GPIO_Pupdr;

typedef enum {
    GPIO_AF0 = 0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15
} GPIO_Af;

#endif // GPIO_TYPES_H
