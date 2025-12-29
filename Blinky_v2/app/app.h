#pragma once
#include "stm32l4xx_hal.h"

typedef struct {
    // LED1 (built-in blinky)
    GPIO_TypeDef *blink_port;
    uint16_t blink_pin;
    uint32_t blink_period_ms;
    uint32_t blink_next_ms;

    // LED2 (external LED controlled by button)
    GPIO_TypeDef *ext_led_port;
    uint16_t ext_led_pin;

    // Button
    GPIO_TypeDef *btn_port;
    uint16_t btn_pin;

    // debounce
    GPIO_PinState btn_raw_last;
    GPIO_PinState btn_stable;
    uint32_t btn_last_change_ms;
} App;

void app_init(App *a,
            GPIO_TypeDef *blink_port, uint16_t blink_pin, uint32_t blink_period_ms,
            GPIO_TypeDef *ext_led_port, uint16_t ext_led_pin,
            GPIO_TypeDef *btn_port, uint16_t btn_pin);

void app_task(App *a, uint32_t now_ms);