#include "BMESPIInterface.h"

bool BMESPIInterface::begin() {
    return bme.begin();
}

void BMESPIInterface::read() {
    temperature = bme.readTemperature();
}

float BMESPIInterface::getTemperature() {
    return temperature;
}
