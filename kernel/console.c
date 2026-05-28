#include <kernel/types.h>
#include <kernel/config.h>

#define VGA_BUFFER ((volatile u8*)(0xB8000))
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static u32 cursor_x = 0;
static u32 cursor_y = 0;

void console_init(void) {
    cursor_x = 0;
    cursor_y = 0;
    
    /* Clear screen */
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2) {
        VGA_BUFFER[i] = ' ';
        VGA_BUFFER[i + 1] = 0x07;  /* Light gray on black */
    }
}

void console_clear(void) {
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2) {
        VGA_BUFFER[i] = ' ';
        VGA_BUFFER[i + 1] = 0x07;
    }
    cursor_x = 0;
    cursor_y = 0;
}

void console_putchar(char c) {
    volatile u8 *vga = VGA_BUFFER + (cursor_y * VGA_WIDTH + cursor_x) * 2;
    
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else if (c == '\r') {
        cursor_x = 0;
    } else if (c == '\t') {
        cursor_x += 4;
    } else {
        vga[0] = (u8)c;
        vga[1] = 0x07;
        cursor_x++;
    }
    
    /* Handle line wrap */
    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    
    /* Handle screen scroll */
    if (cursor_y >= VGA_HEIGHT) {
        /* Scroll up */
        for (int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH * 2; i += 2) {
            VGA_BUFFER[i] = VGA_BUFFER[i + VGA_WIDTH * 2];
            VGA_BUFFER[i + 1] = VGA_BUFFER[i + VGA_WIDTH * 2 + 1];
        }
        
        /* Clear last line */
        for (int i = (VGA_HEIGHT - 1) * VGA_WIDTH * 2; 
             i < VGA_HEIGHT * VGA_WIDTH * 2; i += 2) {
            VGA_BUFFER[i] = ' ';
            VGA_BUFFER[i + 1] = 0x07;
        }
        cursor_y = VGA_HEIGHT - 1;
    }
}

void console_puts(const char *str) {
    while (*str) {
        console_putchar(*str++);
    }
}

/* Simple printf implementation */
void kprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    const char *p = fmt;
    while (*p) {
        if (*p == '%' && *(p + 1)) {
            p++;
            switch (*p) {
                case 's': {
                    const char *s = va_arg(args, const char*);
                    console_puts(s);
                    break;
                }
                case 'd': {
                    s32 n = va_arg(args, s32);
                    char buf[20];
                    itoa(n, buf, 10);
                    console_puts(buf);
                    break;
                }
                case 'x': {
                    u32 n = va_arg(args, u32);
                    char buf[20];
                    itoa(n, buf, 16);
                    console_puts("0x");
                    console_puts(buf);
                    break;
                }
                case 'c': {
                    char c = va_arg(args, int);
                    console_putchar(c);
                    break;
                }
                case '%':
                    console_putchar('%');
                    break;
            }
        } else if (*p == '\n') {
            console_putchar('\r');
            console_putchar('\n');
        } else {
            console_putchar(*p);
        }
        p++;
    }
    
    va_end(args);
}