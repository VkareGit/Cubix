/*
 * RccController.h
 *
 *  Created on: Feb 17, 2024
 *      Author: pawel
 */

#ifndef RCC_RCCCONTROLLER_H_
#define RCC_RCCCONTROLLER_H_

#include "RccTypes.h"
#include "Stm32Macros.h"

RCC_Status RCC_ModifyRegister(volatile uint32_t* reg, uint32_t NewVal, uint32_t Mask, uint32_t BitPos);
RCC_Status RCC_EnablePLL(uint32_t PLLM);
RCC_Status RCC_DisablePLL(void);
RCC_Status RCC_SetPLLSource(RCC_PLLSource source);
RCC_Status RCC_SetPLLN(uint32_t PLLN);
RCC_Status RCC_SetPLLP(uint32_t PLLP);
RCC_Status RCC_SetPLLQ(uint32_t PLLQ);
RCC_Status RCC_ConfigurePLL(RCC_PLLSource PLLSource, uint32_t PLLN, uint32_t PLLP, uint32_t PLLQ);

#endif /* RCC_RCCCONTROLLER_H_ */
