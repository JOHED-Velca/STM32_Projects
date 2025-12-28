#include "blinky_app.h"

void blinky_app_init(BlinkyApp *app, GPIO_TypeDef *port, uint16_t pin, uint32_t period_ms) {
	app->port = port;
	app->pin = pin;
	app->period_ms = period_ms;
	app->next_toggle_ms = HAL_GetTick() + period_ms;

	//Active-high LED: start OFF (LOW)
	HAL_GPIO_WritePin(app->port, app->pin, GPIO_PIN_RESET);
}

void blinky_app_task(BlinkyApp *app, uint32_t now_ms) {
	//handles uint32 wrap correctly using signed diff trick
	if ((int32_t)(now_ms - app->next_toggle_ms) >= 0) {
		HAL_GPIO_TogglePin(app->port, app->pin);
		app->next_toggle_ms += app->period_ms;
	}
}
