#pragma once
#include <Arduino.h>
#include <etl/singleton.h>

class LEDController {
public:
    LEDController() = default;
    int calculate(float temperature);
};

using LEDControllerInstance = etl::singleton<LEDController>;
