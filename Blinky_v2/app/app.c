#include "app.h"

static void app_blink_task(App *a, uint32_t now_ms) {
    if ((int32_t)(now_ms - a->blink_next_ms) >= 0) {
        HAL_GPIO_TogglePin(a->blink_port, a->blink_pin);
        a->blink_next_ms += a->blink_period_ms;
    }
}

static void app_button_task(App *a, uint32_t now_ms) {
    // Read raw
    // GPIO_PinState raw = HAL_GPIO_ReadPin(a->btn_port, a->btn_pin);
    GPIO_PinState raw = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (raw == GPIO_PIN_RESET) ? GPIO_PIN_SET : GPIO_PIN_RESET);


    // Debounce: accept new stable state if unchanged for 30ms
    if (raw != a->btn_raw_last) {
        a->btn_raw_last = raw;
        a->btn_last_change_ms = now_ms;
    }
    if ((int32_t)(now_ms - a->btn_last_change_ms) >= 30) {
        a->btn_stable = a->btn_raw_last;
    }
    // With Pull-Up: pressed usually reads LOW
    uint8_t pressed = (a->btn_stable == GPIO_PIN_RESET);

    // Control external LED (active-high module typical)
    HAL_GPIO_WritePin(a->ext_led_port, a->ext_led_pin, pressed ? GPIO_PIN_SET : GPIO_PIN_RESET);
    
}

void app_init(App *a,
            GPIO_TypeDef *blink_port, uint16_t blink_pin, uint32_t blink_period_ms,
            GPIO_TypeDef *ext_led_port, uint16_t ext_led_pin,
            GPIO_TypeDef *btn_port, uint16_t btn_pin) {
    a->blink_port = blink_port;
    a->blink_pin = blink_pin;
    a->blink_period_ms = blink_period_ms;
    a->blink_next_ms = HAL_GetTick() + blink_period_ms;

    a->ext_led_port = ext_led_port;
    a->ext_led_pin = ext_led_pin;

    a->btn_port = btn_port;
    a->btn_pin = btn_pin;

    a->btn_raw_last = HAL_GPIO_ReadPin(btn_port, btn_pin);
    a->btn_stable = a->btn_raw_last;
    a->btn_last_change_ms = HAL_GetTick();

    // Start LEDs OFF
    HAL_GPIO_WritePin(a->blink_port, a->blink_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(a->ext_led_port, a->ext_led_pin, GPIO_PIN_RESET);
}

void app_task(App *a, uint32_t now_ms) {
    app_blink_task(a, now_ms);
    app_button_task(a, now_ms);
}
