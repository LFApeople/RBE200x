cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(lab4q10 C CXX ASM)
project(lab4q9 C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(lab4q10
  lab4q10.c
)

target_link_libraries(lab4q10
	pico_stdlib
	hardware_adc
	hardware_gpio
	hardware_pwm
	)

pico_add_extra_outputs(lab4q10)

add_executable(lab4q9
  lab4q9.c
)

target_link_libraries(lab4q9
	pico_stdlib
	hardware_adc
	hardware_gpio
	hardware_pwm
	)

pico_add_extra_outputs(lab4q9)
