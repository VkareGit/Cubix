/*
 * RccTypes.h
 *
 *  Created on: Feb 15, 2024
 *      Author: vkare
 */

#ifndef RCC_RCCTYPES_H_
#define RCC_RCCTYPES_H_

#include "stm32/stm32f407xx.h"
#include <stdint.h>

#define __RESET 0
#define __SET(WANTED_BIT) (1U << (WANTED_BIT))

typedef enum {
    RCC_CLOCK_SOURCE_HSI = 0,
    RCC_CLOCK_SOURCE_HSE,
    RCC_CLOCK_SOURCE_PLL
} RCC_ClockSource;

typedef enum {
    RCC_CR_HSION_BIT = 0,       // Internal High-Speed clock enable
    RCC_CR_HSIRDY_BIT = 1,      // Internal High-Speed clock ready flag
    RCC_CR_HSEON_BIT = 16,      // External High-Speed clock enable
    RCC_CR_HSERDY_BIT = 17,     // External High-Speed clock ready flag
    RCC_CR_HSEBYP_BIT = 18,     // External High-Speed clock Bypass
    RCC_CR_CSSON_BIT = 19,      // Clock Security System enable
    RCC_CR_PLLON_BIT = 24,      // Main PLL (PLL) enable
    RCC_CR_PLLRDY_BIT = 25,     // Main PLL (PLL) ready flag
    RCC_CR_PLLI2SON_BIT = 26,   // PLLI2S enable
    RCC_CR_PLLI2SRDY_BIT = 27,  // PLLI2S ready flag
    RCC_CR_PLLSAION_BIT = 28,   // PLLSAI enable
    RCC_CR_PLLSAIRDY_BIT = 29   // PLLSAI ready flag
} RCC_CR_Fields;


typedef enum {
    RCC_DISABLED = 0,
    RCC_ENABLED = 1
} RCC_State;

#endif /* RCC_RCCTYPES_H_ */
