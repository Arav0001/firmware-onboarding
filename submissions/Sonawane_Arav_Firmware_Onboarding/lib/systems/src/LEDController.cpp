#include "LEDController.h"

const float MIN_TEMPERATURE = 20.0f;
const float MAX_TEMPERATURE = 35.0f;
const int SLOW_DELAY = 500;
const int FAST_DELAY = 50;

int LEDController::calculate(float temperature) {
    if (isnan(temperature) || temperature <= MIN_TEMPERATURE) {
        return SLOW_DELAY;
    }

    if (temperature >= MAX_TEMPERATURE) {
        return FAST_DELAY;
    }

    return SLOW_DELAY - (temperature - MIN_TEMPERATURE) * (SLOW_DELAY - FAST_DELAY) / (MAX_TEMPERATURE - MIN_TEMPERATURE);
}
