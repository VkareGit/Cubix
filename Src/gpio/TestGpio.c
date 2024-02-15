/*
 * TestGpio.c
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */


#include "gpio/GpioController.h"

#include <stdio.h>

void delay(int time)
{
	int i;
	for(i = 0 ; i < time * 570; i++) {}
}


void printTestResult(char* testName, GPIO_PinState expected, GPIO_PinState actual) {
    if(expected == actual) {
        printf("%s: PASSED\n", testName);
    } else {
        printf("%s: FAILED\n", testName);
    }
}

void test_GPIO_PinInit() {
    GPIO_InitTypeDef gpioInit;

    gpioInit.port = GPIOA;
    gpioInit.pin_number = GPIO_PIN_0;
    gpioInit.mode = GPIO_MODE_OUTPUT;
    gpioInit.output_type = GPIO_TYPE_PUSH_PULL;
    gpioInit.pull = GPIO_PUPDR_NO_PULL_UP_NO_PULL_DOWN;
    gpioInit.speed = GPIO_SPEED_MEDIUM;
    GPIO_Status status = GPIO_PinInit(&gpioInit);

    if (status == GPIO_STATUS_OK) {
        printf("test_GPIO_PinInit: PASSED\n");
    } else {
        printf("test_GPIO_PinInit: FAILED\n");
    }
}

void test_GPIO_WriteReadPin() {
    GPIO_WritePinDirect(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    GPIO_PinState state = GPIO_ReadPinDirect(GPIOA, GPIO_PIN_0);
    printTestResult("test_GPIO_WriteReadPin SET", GPIO_PIN_SET, state);

    GPIO_WritePinDirect(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    state = GPIO_ReadPinDirect(GPIOA, GPIO_PIN_0);
    printTestResult("test_GPIO_WriteReadPin RESET", GPIO_PIN_RESET, state);
}

void test_GPIO_TogglePin() {
    GPIO_TogglePinDirect(GPIOA, GPIO_PIN_0);
    delay(400);
    GPIO_TogglePinDirect(GPIOA, GPIO_PIN_0);
}

void runTests() {
    test_GPIO_PinInit();
    test_GPIO_WriteReadPin();
    test_GPIO_TogglePin();
}
