#include <gpio/GpioController.h>

static GPIO_ClockState gpioClockState = {0};

GPIO_Status GPIO_ConfigureMode(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigureSpeed(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigureOutputType(GPIO_InitTypeDef *config);
GPIO_Status GPIO_ConfigurePull(GPIO_InitTypeDef *config);

void GPIO_EnableClock(GPIO_TypeDef* GPIOx) {
    if (GPIOx == GPIOA && !gpioClockState.GPIOA_Enabled) {
        __GPIOA_CLK_ENABLE();
        gpioClockState.GPIOA_Enabled = 1;
    } else if (GPIOx == GPIOB && !gpioClockState.GPIOB_Enabled) {
        __GPIOB_CLK_ENABLE();
        gpioClockState.GPIOB_Enabled = 1;
    } else if (GPIOx == GPIOC && !gpioClockState.GPIOC_Enabled) {
        __GPIOC_CLK_ENABLE();
        gpioClockState.GPIOC_Enabled = 1;
    } else if (GPIOx == GPIOD && !gpioClockState.GPIOD_Enabled) {
        __GPIOD_CLK_ENABLE();
        gpioClockState.GPIOD_Enabled = 1;
    } else if (GPIOx == GPIOE && !gpioClockState.GPIOE_Enabled) {
        __GPIOE_CLK_ENABLE();
        gpioClockState.GPIOE_Enabled = 1;
    } else if (GPIOx == GPIOF && !gpioClockState.GPIOF_Enabled) {
        __GPIOF_CLK_ENABLE();
        gpioClockState.GPIOF_Enabled = 1;
    } else if (GPIOx == GPIOG && !gpioClockState.GPIOG_Enabled) {
        __GPIOG_CLK_ENABLE();
        gpioClockState.GPIOG_Enabled = 1;
    } else if (GPIOx == GPIOH && !gpioClockState.GPIOH_Enabled) {
        __GPIOH_CLK_ENABLE();
        gpioClockState.GPIOH_Enabled = 1;
    } else if (GPIOx == GPIOI && !gpioClockState.GPIOI_Enabled) {
        __GPIOI_CLK_ENABLE();
        gpioClockState.GPIOI_Enabled = 1;
    }
}

GPIO_Status GPIO_PinInit(GPIO_InitTypeDef *init) {
    GPIO_EnableClock(init->port);

    // Configure mode using GPIO_ConfigureMode function
    GPIO_Status status = GPIO_ConfigureMode(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure output type
    status = GPIO_ConfigureOutputType(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure speed
    status = GPIO_ConfigureSpeed(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    // Configure pull-up/pull-down
    status = GPIO_ConfigurePull(init);
    if (status != GPIO_STATUS_OK) {
        return status;
    }

    return GPIO_STATUS_OK;
}

void GPIO_TogglePin(GPIO_InitTypeDef *config) {
    config->port->ODR ^= config->pin_number;
}

uint32_t pinNumberToValue(uint32_t pin) {
	    int pin_number = 0;

	    for (int i = 0; i < 16; i++) {
	        if (pin & (1 << i)) {
	            pin_number = i;
	            break;
	        }
	    }
	    return pin_number;
}

GPIO_Status GPIO_ConfigureMode(GPIO_InitTypeDef *config) {
    if (!IS_GPIO_PIN(config->pin_number)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_MODE(config->mode)) {
        return GPIO_STATUS_INVALID_MODE;
    }

    uint16_t pin_number_value  = pinNumberToValue(config->pin_number);

    uint32_t moder_reg_val = config->port->MODER;

    uint32_t mode_mask = 0x3 << (pin_number_value * 2);
    moder_reg_val &= ~mode_mask;

    moder_reg_val |= ((uint32_t)(config->mode) << (pin_number_value * 2));

    config->port->MODER = moder_reg_val;

    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigureSpeed(GPIO_InitTypeDef *config) {
    if (!IS_GPIO_PIN(config->pin_number)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_SPEED(config->speed)) {
        return GPIO_STATUS_INVALID_SPEED;
    }

    uint16_t pin_number_value  = pinNumberToValue(config->pin_number);

    uint32_t ospeedr_val = config->port->OSPEEDR;
    uint32_t speed_mask = 0x3 << (pin_number_value * 2);
    ospeedr_val &= ~speed_mask;
    ospeedr_val |= ((uint32_t)config->speed << (pin_number_value * 2));
    config->port->OSPEEDR = ospeedr_val;

    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigureOutputType(GPIO_InitTypeDef *config) {
    if (!IS_GPIO_PIN(config->pin_number)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_TYPE(config->output_type)) {
        return GPIO_STATUS_INVALID_TYPE;
    }

    uint16_t pin_number_value  = pinNumberToValue(config->pin_number);

    uint32_t otyper_val = config->port->OTYPER;
    if (config->output_type == GPIO_TYPE_OPEN_DRAIN) {
        otyper_val |= (1U << pin_number_value);
    } else {
        otyper_val &= ~(1U << pin_number_value);
    }
    config->port->OTYPER = otyper_val;

    return GPIO_STATUS_OK;
}

GPIO_Status GPIO_ConfigurePull(GPIO_InitTypeDef *config) {
    if (!IS_GPIO_PIN(config->pin_number)) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (!IS_GPIO_PULL(config->pull)) {
        return GPIO_STATUS_INVALID_PULL;
    }

    uint16_t pin_number_value  = pinNumberToValue(config->pin_number);

    uint32_t pupdr_val = config->port->PUPDR;
    uint32_t pull_mask = 0x3 << (pin_number_value * 2);
    pupdr_val &= ~pull_mask;
    pupdr_val |= ((uint32_t)config->pull << (pin_number_value * 2));
    config->port->PUPDR = pupdr_val;

    return GPIO_STATUS_OK;
}

