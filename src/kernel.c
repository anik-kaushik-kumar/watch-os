void print(const char* str, int line) {
    volatile char* vga = (volatile char*)0xB8000 + line * 160;
    while (*str) {
        *vga++ = *str++;
        *vga++ = 0x0F; // White on black
    }
}

void int_to_str(int n, char* str) {
    str[0] = '0' + (n / 10);
    str[1] = '0' + (n % 10);
    str[2] = 0;
}

unsigned char get_rtc(int reg) {
    unsigned char result;
    asm volatile ("outb %1, %0" : : "dN"((unsigned short)0x70), "a"(reg));
    asm volatile ("inb %1, %0" : "=a"(result) : "dN"((unsigned short)0x71));
    return result;
}

void kernel_main() {
    char time_str[9] = "00:00:00";
    while (1) {
        unsigned char h = get_rtc(0x04);
        unsigned char m = get_rtc(0x02);
        unsigned char s = get_rtc(0x00);

        time_str[0] = '0' + ((h >> 4) & 0x0F);
        time_str[1] = '0' + (h & 0x0F);
        time_str[3] = '0' + ((m >> 4) & 0x0F);
        time_str[4] = '0' + (m & 0x0F);
        time_str[6] = '0' + ((s >> 4) & 0x0F);
        time_str[7] = '0' + (s & 0x0F);

        print("WatchOS – The Clock-Only OS", 0);
        print(time_str, 2);
    }
}
