cmake_minimum_required(VERSION 3.16)
project(KettleKernel C)

set(CMAKE_C_STANDARD 99)

add_library(KettleKernel kernel/kernel.c kernel/sys.h kernel/vga.h kernel/string.h kernel/stdio.h)