#include "stm32/stm32f407xx.h"

#define __GPIOD_CLK_ENABLE() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN)

#define GPIO_MODE_OUTPUT_PP (0x01)
#define GPIO_NOPULL (0x00)
#define GPIO_SPEED_FREQ_MEDIUM (0x01)
#define GPIO_PIN_RESET (0x00)

#define GPIO_PIN_12 ((uint16_t)0x1000)
#define GPIO_PIN_13 ((uint16_t)0x2000)
#define GPIO_PIN_14 ((uint16_t)0x4000)
#define GPIO_PIN_15 ((uint16_t)0x8000)

typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
    uint32_t mode;
    uint32_t pull;
    uint32_t speed;
    uint32_t type;
} GPIO_PinConfig_t;


void delay(int time)
{
	int i;
	for(i = 0 ; i < time * 570; i++) {}
}

void GPIO_Init(GPIO_PinConfig_t* pinConfig) {
    if(pinConfig->port == GPIOD) {
    	__GPIOD_CLK_ENABLE();
    }

    pinConfig->port->MODER &= ~(0x3U << (2 * pinConfig->pin));
    pinConfig->port->MODER |= (pinConfig->mode << (2 * pinConfig->pin));

    pinConfig->port->OTYPER &= ~(0x1U << pinConfig->pin);
    pinConfig->port->OTYPER |= (pinConfig->type << pinConfig->pin);

    pinConfig->port->OSPEEDR &= ~(0x3U << (2 * pinConfig->pin));
    pinConfig->port->OSPEEDR |= (pinConfig->speed << (2 * pinConfig->pin));

    pinConfig->port->PUPDR &= ~(0x3U << (2 * pinConfig->pin));
    pinConfig->port->PUPDR |= (pinConfig->pull << (2 * pinConfig->pin));
}

void GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    GPIOx->ODR ^= GPIO_Pin;
}

int main(void) {
    GPIO_PinConfig_t pin12Config = {GPIOD, 12, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_MEDIUM, GPIO_PIN_RESET};
    GPIO_PinConfig_t pin13Config = {GPIOD, 13, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_MEDIUM, GPIO_PIN_RESET};
    GPIO_PinConfig_t pin14Config = {GPIOD, 14, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_MEDIUM, GPIO_PIN_RESET};
    GPIO_PinConfig_t pin15Config = {GPIOD, 15, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_MEDIUM, GPIO_PIN_RESET};

    GPIO_Init(&pin12Config);
    GPIO_Init(&pin13Config);
    GPIO_Init(&pin14Config);
    GPIO_Init(&pin15Config);

    while (1) {
        GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        delay(400);
        GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        delay(400);
        GPIO_TogglePin(GPIOD, GPIO_PIN_14);
        delay(400);
        GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        delay(400);
    }
}


