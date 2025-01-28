cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(lab2q9 C CXX ASM)
project(lab2q10 C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(lab2q9
  lab2q9.c
)

target_link_libraries(lab2q9
	pico_stdlib
	pico_cyw43_arch_none
	)

pico_add_extra_outputs(lab2q9)

add_executable(lab2q10
  lab2q10.c
)

target_link_libraries(lab2q10
	pico_stdlib
	pico_cyw43_arch_none
	)

pico_add_extra_outputs(lab2q10)
