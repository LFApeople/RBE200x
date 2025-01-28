// The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"

// The main function that starts the program and is responsible for toggling the LED.
int main() {
	
	// Initializes stdio types that are linked and a counter int.
	stdio_init_all();
	int i;
	
	// A for loop that initializes all output pins.
    for (i = 0; i <= 4; i++) {
	gpio_init(i);
	gpio_set_dir(i, GPIO_OUT);
	}
	gpio_init(0);
	gpio_set_dir(0, GPIO_OUT);
	
// If there was no issue in initialization the program will repeat a while loop that is forever true which is responsible for indefinitely cycling the LEDs at varying intervals.
while(true) {

// A loop to cycle and turn pins 2-6 on and then off after waiting (GPIO 0-4)
    for (i = 0; i <= 4; i++) {
		
		// A function to set the current pin to an on state
		gpio_put (i, 1) ;
		// The chip is set to wait (200 ms) of no activity with an LED on.
		sleep_ms(200);
		// A function to set the current pin to an off state
		gpio_put (i,0);
    }
	
// The chip is set to wait for a full second of no activity.
sleep_ms(1000);

}
return 0;
}