#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup() {
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    while (!BMESPIInterfaceInstance::instance().begin()) {
        delay(1000);
    }
}

void loop() {
    BMESPIInterfaceInstance::instance().read();

    int blinkDelay = LEDControllerInstance::instance().calculate(BMESPIInterfaceInstance::instance().getTemperature());
    
    digitalWrite(BMEConstants::LED_PIN, HIGH);
    delay(blinkDelay);
    digitalWrite(BMEConstants::LED_PIN, LOW);
    delay(blinkDelay);
}
