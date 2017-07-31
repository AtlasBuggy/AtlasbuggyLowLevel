
#include "Atlasbuggy.h"

Atlasbuggy robot("multibot_robot_1");

uint32_t timer = millis();

void setup() {
    robot.begin();
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
            Serial.print('\t');
            Serial.print(robot.getLed());
            Serial.print('\n');
        }
    }
}
