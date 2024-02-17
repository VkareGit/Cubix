/*
 * Stm32Macros.c
 *
 *  Created on: Feb 17, 2024
 *      Author: pawel
 */

#include "Stm32Macros.h"

bool WaitForConditionWithSysTickTimeout(ConditionCheckFunc condition, uint32_t timeout_ms) {

    SysTick->LOAD = (SystemCoreClock / 1000) * timeout_ms - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    uint32_t startTick = SysTick->VAL;

    while (!condition()) {
        uint32_t currentTick = SysTick->VAL;
        if (currentTick != startTick && (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {
            SysTick->CTRL = 0;
            return false;
        }
    }

    SysTick->CTRL = 0;
    return true;
}

uint32_t CheckBitNumber(uint32_t NewVal)
{
	uint32_t counter = 0;
	while(NewVal)
	{
		counter++;
		NewVal = NewVal >> 1;
	}

	return counter;
}
