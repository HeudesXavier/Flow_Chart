#include "mbed.h"

// Initialize digital input pins on p13 and p16
DigitalIn button1(p13);
DigitalIn button2(p16);

// Initialize digital output pins on p23 and p25
DigitalOut led1(p23);
DigitalOut led2(p25);

int main() {
    while(1) {
        if(button1 == 0) {                     // Button 1 pressed, turn off LEDs and stop program
            led1 = 0;
            led2 = 0;
            break;
        }
        else if(button2 == 0) {                // Button 2 pressed, alternate LEDs
            led1 = !led1;
            led2 = !led2;
            wait(0.5);
        }
        else {                                 // Neither button pressed, turn on LEDs in alternating pattern
            led1 = 1;
            led2 = 0;
            wait(0.5);
            led1 = 0;
            led2 = 1;
            wait(0.5);
        }
    }
}
