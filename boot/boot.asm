[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp

mov bx, BOOT_PRINT
call print

; load kernel
call load_kernel
; enter 32-bit mode
call switch_pm

jmp $

%include "../boot/gdt.asm"
%include "../boot/label.asm"

[bits 32]
BEGIN_PM:
	call KERNEL_OFFSET
	jmp $

BOOT_DRIVE db 0x80
BOOT_PRINT db "Loaded in 16-bit real mode", 0
SWITCHING_PM db "Switching to 32-bit protected mode", 0
PM_BEGAN db "Switched to 32-bit protected mode", 0
KERNEL_SWITCH db "Switching to Kernel", 0

; padding & magic
times 510 - ($-$$) db 0
dw 0xaa55
