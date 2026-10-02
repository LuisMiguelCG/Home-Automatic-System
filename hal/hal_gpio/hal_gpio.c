/**
 * @file hal_gpio.c
 * @author LuisMiguelCG
 * @brief HAL GPIO Implementation.
 * @version 0.1
 * @date 2026-10-02
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "hal_gpio.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

typedef struct {
    uint32_t periph;
    uint32_t base;
    uint8_t mask;
    bool locked;
} gpio_map_t;

static const gpio_map_t s_gpioMap[HAL_GPIO_PIN_COUNT] = {
    [HAL_GPIO_PA5] = {SYSCTL_PERIPH_GPIOA, GPIO_PORTA_BASE, GPIO_PIN_5, false},
};

static bool isValidPin(hal_gpio_pin_t pin);
static void enablePeriph(uint32_t periph);

hal_gpio_status_t HAL_GPIO_Init(hal_gpio_pin_t pin, hal_gpio_type_t type, hal_gpio_pull_t pull) 
{

    if(!isValidPin(pin)) {
        return HAL_GPIO_ERR_PARAM;
    }

    const gpio_map_t *map = &s_gpioMap[pin];

    enablePeriph(map->periph);

    switch (type) {
        
        case HAL_GPIO_TYPE_OUTPUT:
            GPIOPinTypeGPIOOutput(map->base, map->mask);
            break;

        default: 
            break;
    }

    return HAL_GPIO_OK;
}

hal_gpio_status_t HAL_GPIO_Write(hal_gpio_pin_t pin, uint32_t value) 
{

    if (!isValidPin(pin)) {
        return HAL_GPIO_ERR_PARAM;
    }

    const gpio_map_t *map = &s_gpioMap[pin];
    GPIOPinWrite(map->base, map->mask, value);

    return HAL_GPIO_OK;
}


hal_gpio_status_t HAL_GPIO_Read(hal_gpio_pin_t pin, uint32_t *value) 
{

    if(!isValidPin(pin) || value == NULL) {
        return HAL_GPIO_ERR_PARAM;
    }

    const gpio_map_t *map = &s_gpioMap[pin];
    *value = GPIOPinRead(map->base, map->mask);

    return HAL_GPIO_OK;
}

hal_gpio_status_t HAL_GPIO_Toggle(hal_gpio_pin_t pin) 
{

    if (!isValidPin(pin)) {
        return HAL_GPIO_ERR_PARAM;
    }

    const gpio_map_t *map = &s_gpioMap[pin];
    uint32_t value = GPIOPinRead(map->base, map->mask);
    GPIOPinWrite(map->base, map->mask, (uint8_t)value ^ map->mask);

    return HAL_GPIO_OK;
}


static bool isValidPin(hal_gpio_pin_t pin) 
{
    return ((uint32_t)pin < (uint32_t)HAL_GPIO_PIN_COUNT);
}

static void enablePeriph(uint32_t periph)
{
    if(!SysCtlPeripheralReady(periph)) {
        SysCtlPeripheralEnable(periph);
        while (!SysCtlPeripheralReady(periph)) {
            
        }
    }
}