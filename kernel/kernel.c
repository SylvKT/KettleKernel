#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "sys.h"
#include "string.h"
#include "stdio.h"
#include "../drivers/graphics/vga.h"

#ifndef __i686__
#warning "Current cross-compiler:"
#ifdef __linux__
#warning "linux"
#elif defined(__i386__)
#warning "i386"
#else
#warning "Unknown"
#endif
#error "Incorrect cross-compiler; use i686 cross-compiler"
#endif

void main() {
	vga_init();
	vga_println("Kernel Initialized");
}
