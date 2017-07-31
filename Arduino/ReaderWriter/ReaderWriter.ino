
#include "Atlasbuggy.h"

Atlasbuggy robot("my_reader_writer_bot");

uint32_t timer = millis();

void setup() {
    robot.begin();

    // ...checking some values...
    int someMagicalValue = 42;
    int someOtherMagicalValue = 76;

    String someMagicalValueString = String(someMagicalValue);
    String someOtherMagicalValueString = String(someOtherMagicalValue);

    robot.setInitData(someMagicalValueString + "\t" someOtherMagicalValueString);
}

void loop() {
    while (robot.available())
    {
        int status = robot.readSerial();
        if (status == 0) {  // user command
            String command = robot.getCommand();

            if (command == "on") {
                robot.setLed(true);
            }
            else if (command == "off") {
                robot.setLed(false);
            }
            else if (command == "toggle") {
                robot.setLed(!robot.getLed());
            }
        }
        else if (status == 1) {  // stop event

        }
        else if (status == 2) {  // start event

        }
    }

    if (!robot.isPaused()) {
        if (timer > millis())  timer = millis();  // reset the timer if there is overflow
        if ((millis() - ping_timer) > 500) {  // every 0.5 seconds, print the current time in milliseconds
            Serial.print(millis());
            Serial.print('\n');
        }
    }
}
