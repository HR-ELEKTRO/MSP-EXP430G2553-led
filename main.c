#include <msp430.h> 

/*
 * testprogramma voor leds
 * toggled rode en groene led om de beurt met een frequentie van 0,5 Hz
 */

int main(void) {
    // stop watchdog timer
    WDTCTL= WDTPW | WDTHOLD;

    // Pin 1.0 = rode led
    // Pin 1.6 = groene led
    P1DIR= 1<<6 | 1<<0;
    P1OUT= 1<<6;

    // loop forever
    while (1) 
    {
        // toggle bit 0 of P1
        P1OUT ^= 1<<6 | 1<<0;
        // delay for about one second when clock is about 1.1 MHz
        __delay_cycles(1100000);
    }
}
