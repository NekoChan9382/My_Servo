//main.cpp
#include "drivers/include/drivers/BufferedSerial.h"
#include "mbed.h"
#include "Servo.hpp"


CAN can1(PA_11, PA_12, (int)1e6);
BufferedSerial serial(USBTX, USBRX, 115200);


int main()
{
ServoController servoController(can1);
servoController.servo_can_id = 141;

while (1) {
    char data;
    int deg;

    serial.read(&data, sizeof(data));
    if (data == '1') {
        deg = 0;
    } else if (data == '2') {
        deg = 128;
    } else if (data == '3') {
        deg = 255;
    }

    servoController.run(deg,3);
}



}