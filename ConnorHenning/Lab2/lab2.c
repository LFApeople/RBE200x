// The program starts off with the inclusion of libraries referenced for functions and pin positions. 
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// The main function that starts the program and is responsible for toggling the LED.
int main() {
		// Initializes stdio types that are linked
stdio_init_all();

/* A condition that initializes the CYW43 architecture for the CYW43 driver and IwIP which is required for using the on-board LED. If the architecture loads successfully then a 0 is returned which would be recognized as a false for the condition, otherwise an error code would be given. */

if (cyw43_arch_init()) {
// If it fails to load and the condition is triggered then that is printed and the program exits -1.
  printf("Wi-Fi init failed");
  return -1;
}

/* If there was no issue in initialization the program will repeat a while loop that is forever true which is responsible for indefinitely blinking the LED. */

while(true) {
// A function for the driver is called to set the wireless chip LED on.
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
// The chip is set to wait for half a second (500 ms) of no activity.
  sleep_ms(500);

// A function for the driver is called to set the wireless chip LED off.
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
// The chip is set to wait for half a second (500 ms) of no activity.
  sleep_ms(500);
}
}
 
