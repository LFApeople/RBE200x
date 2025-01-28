//10.	[10 Points] For this question you are to design and implement an extension to the circuit you implemented in question 9 above.  For this question, you are to drive an LED circuit similar to that shown in lecture 5 slide 13.  In your circuit you must drive a Green LED using GPIO0, a Red LED using GPIO1, a Blue LED using GPIO2, a Yellow LED using GPIO3, and a White LED using GPIO4.  Your program must scan from GPIO0 to GPIO4, turning each LED on for 200ms before turning that LED off and turning the next LED on.  Once the last LED (GPIO4) has been lit for 200ms, all LEDs must remain dark for 1 second.  Once 1 second has elapsed, the process must begin again at GPIO0, so that there is a pattern of lights that appears to move from GPIO0 to GPIO4, stops for a moment, and starts again at GPIO0. 
 // The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"
// The main function that starts the program and is responsible for toggling the LED.
int main() {
		// Initializes stdio types that are linked and a counter int 
stdio_init_all();
	int i;
    for (i = 0; i <= 4; i++) {
	gpio_init(i);
	gpio_set_dir(i, GPIO_OUT);
	}
	gpio_init(0);
	gpio_set_dir(0, GPIO_OUT);
// If there was no issue in initialization the program will repeat a while loop that is forever true which is responsible for indefinitely blinking the LED at varying intervals.

while(true) {

// A loop to cycle and turn pins 2-6 on and then off after waiting (GPIO 0-4)
    for (i = 0; i <= 4; i++) {
// A function to set the current pin to an on state
  	gpio_put (i, 1) ;
// The chip is set to wait (200 ms) of no activity.
sleep_ms(200);
		// A function to set the current pin to an off state
gpio_put (i,0);

    }
// The chip is set to wait for a full second of no activity.
sleep_ms(1000);

}
return 0;
}