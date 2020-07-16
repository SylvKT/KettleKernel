cmake_minimum_required(VERSION 3.16)
project(KettleKernel C)

set(CMAKE_C_STANDARD 99)

add_library(KettleKernel kernel/kernel.c kernel/sys.h drivers/graphics/vga.h kernel/string.h kernel/stdio.h drivers/ports.c drivers/ports.h kernel/stdio.c drivers/graphics/vga.c kernel/string.c drivers/graphics/intel.c drivers/graphics/intel.h drivers/graphics/screen.c drivers/graphics/screen.h)