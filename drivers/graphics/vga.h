#include <stdint.h>
#include "../../kernel/string.h"
#include "../../kernel/sys.h"

#ifndef KETTLEKERNEL_VGA_H
#define KETTLEKERNEL_VGA_H

enum vga_color {
	VGA_BLACK,
	VGA_BLUE,
	VGA_GREEN,
	VGA_CYAN,
	VGA_RED,
	VGA_MAGENTA,
	VGA_BROWN,
	VGA_LIGHT_GREY,
	VGA_DARK_GREY,
	VGA_LIGHT_BLUE,
	VGA_LIGHT_GREEN,
	VGA_LIGHT_CYAN,
	VGA_LIGHT_RED,
	VGA_LIGHT_MAGENTA,
	VGA_LIGHT_BROWN,
	VGA_WHITE
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);

void vga_reset_cursor();

void vga_putcharat(char c, size_t x, size_t y);

void vga_putchar(char c);

void vga_print(const char *str);

void vga_println(const char *str);

void vga_clear();

void vga_init();

#endif //KETTLEKERNEL_VGA_H
