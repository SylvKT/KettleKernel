cd bin || return
nasm ../boot/boot.asm -f bin -o boot.bin
nasm ../boot/kernel_entry.asm -f elf -o kernel_entry.o
i686-elf-gcc -ffreestanding -c ../kernel/kernel.c -o kernel.o
i686-elf-ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary
cat boot.bin kernel.bin > os.bin
