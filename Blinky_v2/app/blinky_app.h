#pragma once
#include "stm32l4xx_hal.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    uint32_t period_ms;
    uint32_t next_toggle_ms;
} BlinkyApp;

void blinky_app_init(BlinkyApp *app, GPIO_TypeDef *port, uint16_t pin, uint32_t period_ms);
void blinky_app_task(BlinkyApp *app, uint32_t now_ms);