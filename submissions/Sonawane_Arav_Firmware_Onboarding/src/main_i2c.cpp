#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup() {
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    while (!BMEI2CInterfaceInstance::instance().begin()) {
        delay(1000);
    }
}

void loop() {
    BMEI2CInterfaceInstance::instance().read();
    
    int blinkDelay = LEDControllerInstance::instance().calculate(BMEI2CInterfaceInstance::instance().getTemperature());

    digitalWrite(BMEConstants::LED_PIN, HIGH);
    delay(blinkDelay);
    digitalWrite(BMEConstants::LED_PIN, LOW);
    delay(blinkDelay);
}
