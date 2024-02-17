#ifndef STM32MACROS_H_
#define STM32MACROS_H_

#include <stdint.h>
#include <stdbool.h>
#include "stm32/stm32f407xx.h"

// Reset and Set Operations
#define STM_RESET 0
#define STM_SET(WANTED_BIT) (1U << (WANTED_BIT))

// Bit Manipulation
#define BIT_SET(REG, BIT) ((REG) |= (1U << (BIT)))
#define BIT_CLEAR(REG, BIT) ((REG) &= ~(1U << (BIT)))
#define BIT_TOGGLE(REG, BIT) ((REG) ^= (1U << (BIT)))
#define BIT_READ(REG, BIT) (((REG) >> (BIT)) & 1U)


// Bit Mask Operations
#define BITMASK_SET(REG, MASK) ((REG) |= (MASK))
#define BITMASK_CLEAR(REG, MASK) ((REG) &= ~(MASK))
#define BITMASK_TOGGLE(REG, MASK) ((REG) ^= (MASK))
#define BITMASK_CHECK(REG, MASK) (((REG) & (MASK)) == (MASK))

// Low and High Byte Operations
#define LOW_BYTE(VALUE) ((uint8_t)(VALUE & 0xFF))
#define HIGH_BYTE(VALUE) ((uint8_t)((VALUE >> 8) & 0xFF))

// Safe Division (returns 0 for a 0 divisor)
#define SAFE_DIV(NUMERATOR, DENOMINATOR) (((DENOMINATOR) == 0) ? 0 : ((NUMERATOR) / (DENOMINATOR)))

// Swap two values
#define SWAP(a, b) do { typeof(a) tmp = a; a = b; b = tmp; } while (0)

// Array Size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Static Assert
#define STATIC_ASSERT(CONDITION, MSG) typedef char static_assertion_##MSG[(CONDITION)?1:-1]

typedef bool (*ConditionCheckFunc)(void);

bool WaitForConditionWithSysTickTimeout(ConditionCheckFunc condition, uint32_t timeout_ms);

uint32_t CheckBitNumber(uint32_t NewVal);

#endif /* STM32MACROS_H_ */
