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
#include "Stm32Macros.h"


#define PLLM_BIT_WIDTH  (6)
#define PLLN_BIT_WIDTH  (9)
#define PLLP_BIT_WIDTH  (2)  // Considering the encoding, this might need additional handling.
#define PLLQ_BIT_WIDTH  (4)

#define RCC_PLLCFGR_PLLM_MASK ((1U << PLLM_BIT_WIDTH) - 1)
#define RCC_PLLCFGR_PLLN_MASK ((1U << PLLN_BIT_WIDTH) - 1)
#define RCC_PLLCFGR_PLLP_MASK ((1U << PLLP_BIT_WIDTH) - 1)
#define RCC_PLLCFGR_PLLQ_MASK ((1U << PLLQ_BIT_WIDTH) - 1)

// Since PLLP has encoded values, you might need to define the allowable codes directly.
#define PLLP_VALID_CODE_2  (0U)
#define PLLP_VALID_CODE_4  (1U)
#define PLLP_VALID_CODE_6  (2U)
#define PLLP_VALID_CODE_8  (3U)

typedef enum {
    RCC_CLOCK_SOURCE_HSI = 0,
    RCC_CLOCK_SOURCE_HSE,
    RCC_CLOCK_SOURCE_PLL
} RCC_ClockSource;

typedef enum {
    RCC_PLL_SOURCE_HSI = 0,
    RCC_PLL_SOURCE_HSE = 1
} RCC_PLLSource;

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
    RCC_PLL_PLLM_BIT = 0,
	RCC_PLL_PLLN_BIT = 6,
	RCC_PLL_PLLP_BIT = 16,
	RCC_PLL_PLLSRC_BIT = 22,
	RCC_PLL_PLLQ_BIT = 24
} RCC_PLL_Fields;



typedef enum {
    RCC_DISABLED = 0,
    RCC_ENABLED = 1
} RCC_State;

typedef struct
{
	uint32_t HSEState;
	uint32_t LSEState;
	uint32_t HSIState;
	uint32_t LSIState;
	uint32_t PLLState;
	uint32_t SYSCLKSource;
	uint32_t AHBCLKDivider;
	uint32_t APB1CLKDivider;
	uint32_t APB2CLKDivider;
	uint32_t PLLM;
	uint32_t PLLN;
	uint32_t PLLP;
	uint32_t PLLQ;
}RCC_InitTypeDef;

typedef enum {
    RCC_STATUS_ERROR = 0,
    RCC_STATUS_OK,
    RCC_STATUS_TIMEOUT
} RCC_Status;

#endif /* RCC_RCCTYPES_H_ */
