#include "kernel.h"

void early_boot(void) {
    console_init();
    kprintf("\n");
    kprintf("╔════════════════════════════════════╗\n");
    kprintf("║     LavaDev OS Kernel v0.1.0       ║\n");
    kprintf("║   Multi-Architecture (x86/x64/ARM) ║\n");
    kprintf("╚════════════════════════════════════╝\n");
    kprintf("\n");
}

void kernel_main(void) {
    early_boot();
    
    /* Stage 1: Memory Management */
    kprintf("[Stage 1] Memory Management\n");
    mm_init();
    
    /* Stage 2: Interrupt Handling */
    kprintf("[Stage 2] Interrupt Handling\n");
    irq_init();
    
    /* Stage 3: Process Management */
    kprintf("[Stage 3] Process Management\n");
    process_init();
    
    /* Stage 4: File System */
    kprintf("[Stage 4] File System\n");
    vfs_init();
    
    /* Stage 5: Device Drivers */
    kprintf("[Stage 5] Device Drivers\n");
    drivers_init();
    
    kprintf("\n");
    kprintf("╔════════════════════════════════════╗\n");
    kprintf("║   Kernel Boot Complete!            ║\n");
    kprintf("║   Ready to accept user input       ║\n");
    kprintf("╚════════════════════════════════════╝\n");
    kprintf("\n");
    
    /* Main loop */
    while (1) {
        asm volatile("hlt");
    }
}