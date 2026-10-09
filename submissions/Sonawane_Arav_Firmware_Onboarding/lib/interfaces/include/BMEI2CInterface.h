#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface {
public:
    BMEI2CInterface() = default;
    bool begin();
    void read();
    float getTemperature();
private:
    Adafruit_BME280 bme;
    float temperature = NAN;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
