/*
 * GpioController.h
 *
 *  Created on: Feb 14, 2024
 *      Author: vkare
 */

#ifndef GPIO_GPIOCONTROLLER_H_
#define GPIO_GPIOCONTROLLER_H_

#include "stm32/stm32f407xx.h"
#include "gpio/GpioTypes.h"

#define __GPIOA_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN)
#define __GPIOB_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN)
#define __GPIOC_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN)
#define __GPIOD_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN)
#define __GPIOE_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN)
#define __GPIOF_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN)
#define __GPIOG_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN)
#define __GPIOH_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN)
#define __GPIOI_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN)

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

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

#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_PUPDR_NO_PULL_UP_NO_PULL_DOWN) ||\
                              ((PULL) == GPIO_PUPDR_PULL_UP) ||\
                              ((PULL) == GPIO_PUPDR_PULL_DOWN) ||\
                              ((PULL) == GPIO_PUPDR_RESERVED))


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
    uint8_t GPIOA_Enabled;
    uint8_t GPIOB_Enabled;
    uint8_t GPIOC_Enabled;
    uint8_t GPIOD_Enabled;
    uint8_t GPIOE_Enabled;
    uint8_t GPIOF_Enabled;
    uint8_t GPIOG_Enabled;
    uint8_t GPIOH_Enabled;
    uint8_t GPIOI_Enabled;
} GPIO_ClockState;

typedef struct {
    GPIO_TypeDef* port;
    uint8_t pin_number;
    GPIO_Mode mode;
    GPIO_Type output_type;
    GPIO_Speed speed;
    GPIO_Pull pull;
}GPIO_InitTypeDef;

typedef enum {
    GPIO_STATUS_OK = 0,
    GPIO_STATUS_ERROR,
    GPIO_STATUS_INVALID_PIN,
    GPIO_STATUS_INVALID_MODE,
	GPIO_STATUS_INVALID_TYPE,
	GPIO_STATUS_INVALID_SPEED,
	GPIO_STATUS_INVALID_PULL
} GPIO_Status;

#endif /* GPIO_GPIOCONTROLLER_H_ */
