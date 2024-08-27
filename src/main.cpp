//main.cpp
#include "mbed.h"
#include "Servo.hpp"


CAN can1(PA_11, PA_12, (int)1e6);
BufferedSerial serial(USBTX, USBRX, 115200);


int main()
{
ServoController servoController(can1,140);

while (1) {
    char data;
    int deg;

    serial.read(&data, sizeof(data));
    if (data == '1') {
        deg = 0;
        printf("0\n");
    } else if (data == '2') {
        deg = 128;
        printf("128\n");
    } else if (data == '3') {
        deg = 255;
        printf("255\n");
    }

    servoController.run(deg,1);
}



}