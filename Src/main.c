#include "gpio/GpioController.h"

void delay(int time)
{
	int i;
	for(i = 0 ; i < time * 570; i++) {}
}


int main(void) {

	GPIO_InitTypeDef pin12Config = {GPIOD, GPIO_PIN_12, GPIO_MODE_OUTPUT, GPIO_TYPE_PUSH_PULL,GPIO_SPEED_MEDIUM,GPIO_PUPDR_NO_PULL_UP_NO_PULL_DOWN};

	GPIO_PinInit(&pin12Config);

    while (1) {
        GPIO_TogglePin(&pin12Config);
        delay(400);
    }
}


