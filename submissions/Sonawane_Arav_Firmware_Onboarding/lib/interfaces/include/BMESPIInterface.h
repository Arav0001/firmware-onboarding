#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface {
public:
    BMESPIInterface() = default;
    bool begin();
    void read();
    float getTemperature();
private:
    Adafruit_BME280 bme{BMEConstants::CS_PIN, BMEConstants::MOSI_PIN, BMEConstants::MISO_PIN, BMEConstants::SCLK_PIN};
    float temperature = NAN;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
