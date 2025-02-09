// The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

// The main function that starts the program and is responsible for adjusting the PWM based on potentiometer.
int main() {
	// Initializes stdio types, gpio as pwm, and adc pins 
	stdio_init_all();
	int i;
    for (i = 0; i <= 4; i++) {
	gpio_init(i);
	gpio_set_dir(i, GPIO_OUT);
	}
	gpio_set_function(0, GPIO_FUNC_PWM);
		
	// Initializes PWM with base 1000Hz 75% duty cycle
	uint slice = pwm_gpio_to_slice_num(0);
	pwm_set_clkdiv (slice, 125);
	pwm_set_wrap(slice,  1000);
    pwm_set_chan_level(slice, 0, 750);
    pwm_set_enabled(slice, true);
	
	// Analog pin preparation on pin 31 (GPIO 26, ADC 0)
	adc_init();
	adc_gpio_init(26);
	adc_select_input(0);

	// Factor used to convert analog reading to voltage value.
	const float conversion_factor = 3.3f / (1<<12);
	// frequence that will be set later.
	int freq;

	// Main loop repeating forever that has a for loop of variable length for a timer that tracks the switch within before setting the state afterwards.
	while(true) {
	
		// Adjusts the frequency based on the potentiometer reading.
		freq = (1+9*(adc_read() * conversion_factor) / 3.3);
		pwm_set_wrap(slice,  1000/freq);
		// Set channel A output high for 75% of wrap before dropping
		pwm_set_chan_level(slice, 0, 750/freq);
		
		//Conditions that check current frequency and enable corresponding LED output.
		if (freq<2.5) {
			gpio_put(1,1);
			gpio_put(2,0);
			gpio_put(3,0);
			gpio_put(4,0);
		}
		if (freq>2.5&&freq<5) {
			gpio_put(1,0);
			gpio_put(2,1);
			gpio_put(3,0);
			gpio_put(4,0);
		}
		if (freq>5&&freq<7.5) {
			gpio_put(1,0);
			gpio_put(2,0);
			gpio_put(3,1);
			gpio_put(4,0);
		}
		if (freq>7.5) {
			gpio_put(1,0);
			gpio_put(2,0);
			gpio_put(3,0);
			gpio_put(4,1);
		}
	}
}