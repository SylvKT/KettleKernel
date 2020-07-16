#include "vga.h"

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t vga_row;
size_t vga_column;
uint8_t terminal_color;
uint16_t *terminal_buffer;

void vga_reset_cursor() {
	vga_row = 0;
	vga_column = 0;
}

void vga_putcharat(char c, size_t x, size_t y) {
	size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = c | terminal_color << 8;
}

void vga_putchar(char c) {
	vga_putcharat(c, vga_row, vga_column);
	if (vga_row++ == VGA_HEIGHT) {
		vga_row = 0;
		if (vga_column++ == VGA_WIDTH)
			vga_column = 0;
	}
}

void vga_print(const char *str) {
	for (int i = 0; i < strlen(str); i++) {
		vga_putchar(str[i]);
	}
}

void vga_println(const char *str) {
	vga_print(str);
	vga_column++;
	vga_row = 0;
}

void vga_clear() {
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			vga_putcharat(' ', x, y);
		}
	}
	vga_reset_cursor();
}

void vga_init() {
	vga_reset_cursor();
	terminal_color = vga_entry_color(VGA_WHITE, VGA_BLACK);
	terminal_buffer = (uint16_t*)0xb8000;
	vga_clear();
}
