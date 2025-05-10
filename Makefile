KERNEL=kernel.bin
ISO=watchos.iso
BUILD=build

all: $(ISO)

$(BUILD)/$(KERNEL): src/boot.s src/kernel.c
	mkdir -p $(BUILD)
	nasm -f elf32 src/boot.s -o $(BUILD)/boot.o
	gcc -m32 -ffreestanding -c src/kernel.c -o $(BUILD)/kernel.o
	ld -m elf_i386 -Ttext 0x1000 -o $(BUILD)/$(KERNEL) $(BUILD)/boot.o $(BUILD)/kernel.o --oformat binary

$(ISO): $(BUILD)/$(KERNEL)
	mkdir -p iso/boot/grub
	cp $(BUILD)/$(KERNEL) iso/boot/
	cp boot/grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISO) iso

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

clean:
	rm -rf build iso $(ISO)
