cmake_minimum_required(VERSION 3.13)

# Default to pico_w board if not specified
if (NOT PICO_BOARD)
    set(PICO_BOARD pico_w)
endif()

include(pico_sdk_import.cmake)

project(bareiron C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(bareiron
    src/crafting.c
    src/globals.c
    src/main.c
    src/packets.c
    src/procedures.c
    src/registries.c
    src/serialize.c
    src/structures.c
    src/tools.c
    src/varnum.c
    src/worldgen.c
)

target_include_directories(bareiron PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(bareiron
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
)

# Enable USB CDC stdout for debugging/logging, disable UART stdout
pico_enable_stdio_usb(bareiron 1)
pico_enable_stdio_uart(bareiron 0)

# Create uf2 and map output files
pico_add_extra_outputs(bareiron)
