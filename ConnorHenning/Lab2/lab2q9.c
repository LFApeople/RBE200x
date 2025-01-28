// The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"

// The main function that starts the program and is responsible for toggling the LED.
int main() {
	// Initializes stdio types that are linked and a counter int 
	stdio_init_all();
	int i;

	// Sets and initializes the pin as a constant output.
	const int IO_PIN = 22;
	gpio_init(IO_PIN);
	gpio_set_dir(IO_PIN, GPIO_OUT);
	
	// If there was no issue in initialization the program will repeat a while loop that is forever true which is responsible for indefinitely blinking the LED at varying intervals. 
	while(true) {

		// A simple for loop that repeats five times for the LED to blink at 1Hz across a total of 5 seconds.
		for (i = 1; i <= 5; i++) {
			
			// A basic function to set GPIO22 to an on state
			gpio_put (IO_PIN, 1) ;
			// The chip is set to wait for half a second (500 ms) of no activity.
			sleep_ms(500);
			// A function to set pin GPIO22 to an off state
			gpio_put (IO_PIN,0);
			// The chip is set to wait for half a second (500 ms) of no activity.
			sleep_ms(500);
		}

		// A for loop that repeats five times for the LED to blink at 5Hz across a total of 1 second.
		for (i = 1; i <= 5; i++) {
		
			// A function to set GPIO22 to an on state
			gpio_put (IO_PIN, 1) ;
			// The chip is set to wait for a tenth of a second (100 ms) of no activity.
			sleep_ms(100);
			// A function to set GPIO22 to an off state
			gpio_put (IO_PIN,0);
			// The chip is set to wait for a tenth of a second (100 ms) of no activity.
			sleep_ms(100);
		}

	}
	return 0;
}