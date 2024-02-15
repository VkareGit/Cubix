/*
 * GpioConfig.h
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "GpioTypes.h"

#define GPIO_MODE_MASK 0x3U
#define GPIO_PIN_MULTIPLIER 2
#define GPIO_OUTPUT_TYPE_MASK 0x1U
#define GPIO_RESET_VALUE 0x0U


GPIO_Status GPIO_ConfigureModeStruct(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigureSpeedStruct(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigureOutputTypeStruct(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigurePullStruct(GPIO_InitTypeDef *config);

GPIO_Status GPIO_ConfigureModeDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Mode Mode);
GPIO_Status GPIO_ConfigureSpeedDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Speed Speed);
GPIO_Status GPIO_ConfigureOutputTypeDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Type Type);
GPIO_Status GPIO_ConfigurePullDirect(GPIO_TypeDef* GPIOx, uint16_t Pin, GPIO_Pull Pull);

GPIO_Status GPIO_PinInit(GPIO_InitTypeDef *init);

#endif /* GPIO_CONFIG_H_ */
