// The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

// The main function that starts the program and is responsible for toggling the LED.
int main() {
	// Initializes stdio types, gpio, and adc pins 
stdio_init_all();

	// Analog pin preparation on pin 31 (GPIO 26, ADC 0)
adc_init();
adc_gpio_init(26);
adc_select_input(0);

	// GPIO pin preparation on pin 26 (GPIO 20) for the LED.
gpio_init(20);
gpio_set_dir(20,  GPIO_OUT);

	// GPIO pin preparation on pin 1 (GPIO 0) for the switch.
gpio_init(0);
gpio_set_dir(0, GPIO_IN);
gpio_set_pulls(0, 1, 0);

	// Initializes variables used to control LED
int i;
bool LED_on = 1;
bool LED_state = 0;

	// Factor used to convert analog reading to voltage value.
const float conversion_factor = 3.3f / (1<<12);
	// percent of wait from 0 to 1.
float percent = (float) (adc_read() * conversion_factor) / 3.3;

	// Main loop repeating forever that has a for loop of variable length for a timer that tracks the switch within before setting the state afterwards.
while(true) {
	
		// Timer loop that adjusts the length based on the potentiometer reading.
	for (i = 0; i <= 10/percent; i++) {
		percent = (float) (adc_read() * conversion_factor) / 3.3;
			
			// Reads the switch and if closed waits .1s to check again before toggling LED state.
		if (gpio_get(0) == 0) {
			sleep_ms(100);
			if( gpio_get(0) == 0)
				LED_on = !LED_on;
				gpio_put(20,LED_on);
		}
		
		// The sleep controls the speed of the loop with increments of 1 every ms up to 10/percent ms.
		sleep_ms(1);
	}
	
	// Checks if the LED can be on and flips the state.
	if (percent > .01 && LED_on) {
		gpio_put(20, LED_state);
		LED_state = !LED_state;
	}
		else
			gpio_put(20,1);
}
}