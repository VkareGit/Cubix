#include <gpio/GpioController.h>

GPIO_Status GPIO_ConfigureMode(GPIO_InitTypeDef *config) {
    if (config->pin_number >= 16) {
        return GPIO_STATUS_INVALID_PIN;
    }
    if (config->mode > GPIO_MODE_ANALOG) {
        return GPIO_STATUS_INVALID_MODE;
    }

    uint32_t moder_reg_val = config->port->MODER;

    uint32_t mode_mask = 0x3 << (config->pin_number * 2);
    moder_reg_val &= ~mode_mask;

    moder_reg_val |= ((uint32_t)(config->mode) << (config->pin_number * 2));

    config->port->MODER = moder_reg_val;

    return GPIO_STATUS_OK;
}
