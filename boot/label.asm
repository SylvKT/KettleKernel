[bits 16]
load_kernel:
	mov bx, KERNEL_OFFSET
	mov dh, 2
	mov dl, [BOOT_DRIVE]
	call disk_load
	ret

disk_load:
	pusha
	push dx

	mov ah, 0x02
	mov al, dh
	mov cl, 0x02

	mov ch, 0x00
	mov dh, 0x00

	int 0x13

	pop dx
	popa
	ret

print:
	pusha
	jmp print_loop
print_loop:
	mov al, [bx]
	cmp al, 0
	je done

	mov ah, 0x0e
	int 0x10
	add bx, 1
	jmp print_loop
done:
	mov al, 0x0a
	int 0x10
	mov al, 0x0d
	int 0x10
	popa
	ret

pmprint:
	pusha
	mov edx, 0xb8000
	jmp pmprint_loop
pmprint_loop:
	mov al, [ebx]
	cmp al, 0
    je pmprint_done
	mov ah, 0x0f

	mov [edx], ax
	add ebx, 1
	add edx, 2

	jmp pmprint_loop
pmprint_done:
	popa
	ret
