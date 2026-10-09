#pragma once
#include <Arduino.h>

namespace BMEConstants {
    constexpr uint8_t I2C_ADDRESS = 0x77;
    constexpr uint8_t CS_PIN = 10;
    constexpr uint8_t MOSI_PIN = 11;
    constexpr uint8_t MISO_PIN = 12;
    constexpr uint8_t SCLK_PIN = 13;
    constexpr uint8_t LED_PIN = 7;
}
