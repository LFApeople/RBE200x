cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(lab3q9 C CXX ASM)
project(lab3q8 C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(lab3q9
  lab3q9.c
)

target_link_libraries(lab3q9
	pico_stdlib
	hardware_adc
	hardware_gpio
	)

pico_add_extra_outputs(lab3q9)

add_executable(lab3q8
  lab3q8.c
)

target_link_libraries(lab3q8
	pico_stdlib
	hardware_adc
	hardware_gpio
	)

pico_add_extra_outputs(lab3q8)
