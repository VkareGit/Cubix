/*
 * RccController.c
 *
 *  Created on: Feb 17, 2024
 *      Author: pawel
 */

#include "rcc/RccController.h"

bool PLLIsOn(void) {
    return BIT_READ(RCC->CR, RCC_CR_PLLON_BIT);
}

RCC_Status RCC_ModifyRegister(volatile uint32_t* reg, uint32_t NewVal, uint32_t Mask, uint32_t BitPos){
    if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // PLL is already on
    }

    uint32_t clearmask = ~(Mask << BitPos);
    BITMASK_CLEAR(*reg, clearmask);

    uint32_t setmask = (NewVal << BitPos);
    BITMASK_SET(*reg, setmask);

    return RCC_STATUS_OK;
}

bool PLLIsReady(void) {
    return BIT_READ(RCC->CR, RCC_CR_PLLRDY_BIT);
}


RCC_Status RCC_EnablePLL(uint32_t PLLM) {
	RCC_Status status = RCC_STATUS_ERROR;
    if (PLLIsOn()) {
        return status; // PLL is already on
    }


    status =  RCC_ModifyRegister(&(RCC->PLLCFGR), PLLM, RCC_PLLCFGR_PLLM_MASK, RCC_PLL_PLLM_BIT);

    if (status != RCC_STATUS_OK) {
        return status;
    }

    BIT_SET(RCC->CR, RCC_CR_PLLON_BIT);

    if (!WaitForConditionWithSysTickTimeout(PLLIsReady, 500)) {
        return RCC_STATUS_TIMEOUT;
    }

    return status;
}

bool PLLIsOff(void) {
    return !BIT_READ(RCC->CR, RCC_CR_PLLRDY_BIT);
}

RCC_Status RCC_DisablePLL(void) {
    if (!PLLIsOn()) {
        return RCC_STATUS_ERROR; // PLL is already off
    }

    BIT_CLEAR(RCC->CR, RCC_CR_PLLON_BIT);

    if (!WaitForConditionWithSysTickTimeout(PLLIsOff, 500)) {
        return RCC_STATUS_TIMEOUT;
    }

    return RCC_STATUS_OK;
}

RCC_Status RCC_SetPLLSource(RCC_PLLSource source) {
    if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // PLL is already on
    }

    if (source == RCC_PLL_SOURCE_HSE) {
        BIT_SET(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC);
    } else{
        BIT_CLEAR(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC);
    }

    return RCC_STATUS_OK;
}


RCC_Status RCC_SetPLLN(uint32_t PLLN) {
	if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // Modification not allowed when PLL is on
    }

    if (PLLN > RCC_PLLCFGR_PLLN_MASK) {
        return RCC_STATUS_ERROR;
    }


    return RCC_ModifyRegister(&(RCC->PLLCFGR), PLLN, RCC_PLLCFGR_PLLN_MASK, RCC_PLL_PLLN_BIT);
}

RCC_Status RCC_SetPLLM(uint32_t PLLM) {
	if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // Modification not allowed when PLL is on
    }

    if (PLLM > RCC_PLLCFGR_PLLM_MASK) {
        return RCC_STATUS_ERROR;
    }

    return RCC_ModifyRegister(&(RCC->PLLCFGR), PLLM, RCC_PLLCFGR_PLLM_MASK, RCC_PLL_PLLM_BIT);
}

RCC_Status RCC_SetPLLP(uint32_t PLLP) {
	if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // PLL is already on
    }

    if (PLLP > RCC_PLLCFGR_PLLP_MASK) {
        return RCC_STATUS_ERROR;
    }

    uint32_t encodedPLLP = (PLLP >> 1) - 1;
    return RCC_ModifyRegister(&(RCC->PLLCFGR), encodedPLLP, RCC_PLLCFGR_PLLP_MASK, RCC_PLL_PLLP_BIT);
}

RCC_Status RCC_SetPLLQ(uint32_t PLLQ) {
	if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // PLL is already on
    }

    if (PLLQ > RCC_PLLCFGR_PLLQ_MASK) {
        return RCC_STATUS_ERROR;
    }

    return RCC_ModifyRegister(&(RCC->PLLCFGR), PLLQ, RCC_PLLCFGR_PLLQ_MASK, RCC_PLL_PLLQ_BIT);
}

RCC_Status RCC_ConfigurePLL(RCC_PLLSource PLLSource, uint32_t PLLN, uint32_t PLLP, uint32_t PLLQ) {
	if (PLLIsOn()) {
        return RCC_STATUS_ERROR; // Error if PLL is already on
    }

    RCC_Status status = RCC_STATUS_ERROR;
    if ((status = RCC_SetPLLSource(PLLSource)) != RCC_STATUS_OK) return status;
    if ((status = RCC_SetPLLN(PLLN)) != RCC_STATUS_OK) return status;
    if ((status = RCC_SetPLLP(PLLP)) != RCC_STATUS_OK) return status;
    if ((status = RCC_SetPLLQ(PLLQ)) != RCC_STATUS_OK) return status;

    BIT_SET(RCC->CR, RCC_CR_PLLON_BIT);
    while (!BIT_READ(RCC->CR, RCC_CR_PLLRDY_BIT)) {
        //TODO: Implement timeout
    }

    return RCC_STATUS_OK;
}




