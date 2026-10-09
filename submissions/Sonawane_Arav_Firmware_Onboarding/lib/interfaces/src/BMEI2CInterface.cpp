#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin() {
    return bme.begin(BMEConstants::I2C_ADDRESS);
}

void BMEI2CInterface::read() {
    temperature = bme.readTemperature();
}

float BMEI2CInterface::getTemperature() {
    return temperature;
}
