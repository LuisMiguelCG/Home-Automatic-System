/**
 * @file hal_gpio.h
 * @author LuisMiguelCG
 * @brief GPIO HAL Interface.
 * @version 0.1
 * @date 2026-10-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef enum{
    HAL_GPIO_PA5 = 0,
    HAL_GPIO_PIN_COUNT
} hal_gpio_pin_t;

typedef enum {
    HAL_GPIO_TYPE_OUTPUT = 0
} hal_gpio_type_t;

typedef enum {
    HAL_GPIO_PULL_NONE = 0,
    HAL_GPIO_PULL_UP,
    HAL_GPIO_PULL_DOWN
} hal_gpio_pull_t;

typedef enum{
    HAL_GPIO_OK = 0,
    HAL_GPIO_ERR_PARAM
} hal_gpio_status_t;

/**
 * @brief Confgure a pin.
 * 
 * @param pin Pin to be configure.
 * @param type Pin type.
 * @param pull Internal resistance.
 * @return hal_gpio_status_t 
 */
hal_gpio_status_t HAL_GPIO_Init(hal_gpio_pin_t pin, hal_gpio_type_t type, hal_gpio_pull_t pull);

/**
 * @brief Write on a pin.
 *  
 */
hal_gpio_status_t HAL_GPIO_Write(hal_gpio_pin_t pin, uint32_t value);

/**
 * @brief Read a pin.
 * 
 */
hal_gpio_status_t HAL_GPIO_Read(hal_gpio_pin_t pin, uint32_t *value);

/**
 * @brief Toggle logical pin state. (Only logical pins)
 * 
 */
hal_gpio_status_t HAL_GPIO_Toggle(hal_gpio_pin_t pin);


#ifdef __cplusplus
}
#endif

#endif /* HAL_GPIO_H */