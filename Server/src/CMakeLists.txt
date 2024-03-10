cmake_minimum_required(VERSION 3.22.1)

set(PROGRAM_NAME pico_w_webserver)
set(PICO_BOARD pico_w)

include(pico_sdk_import.cmake)

project(pico_w_webserver C CXX ASM)
set(CMAKE_C_STANDAR 11)
set(CMAKE_CXX_STANDAR 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initilize the SDk
pico_sdk_init()

add_executable(${PROGRAM_NAME} main.c)

target_include_directories(${PROGRAM_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
    ${PROGRAM_NAME}
    pico_cyw43_arch_lwip_threadsafe_background
    pico_stdlib
    pico_lwip_http
    pico_stdlib
    hardware_adc
    )

pico_enable_stdio_usb(${PROGRAM_NAME} 1)
pico_enable_stdio_uart(${PROGRAM_NAME} 0)

pico_add_extra_outputs(${PROGRAM_NAME})
