#ifndef idt_h_
#define idt_h_

#include <stdint.h>
#include <stddef.h>
#include "libc/stdio.h"
#include "PIC.h"
#include "Timer.h"

typedef struct __attribute__((packed))
{
    uint64_t r15, r14, r13, r12, r11, r10, r9, r8;
    uint64_t rbp, rdi, rsi, rdx, rcx, rbx, rax;
    uint64_t int_no, error_code, rip, cs, rflags, rsp, ss;
} Registers;

typedef struct  __attribute__((packed)){
   uint16_t offset_1; 
   uint16_t selector; 
   uint8_t  ist;            
   uint8_t  type_attributes; 
   uint16_t offset_2;   
   uint32_t offset_3;  
   uint32_t zero;     
} idtdesc;

const char *exception_str[] = {
"Divide By Zero",
"Debug",
"Non-maskable Interrupt",
"Breakpoint",
"Overflow",
"Bound Range Exceeded",
"Invalid Opcode",
"Device Not Available",
"Double Fault",
"Coprocessor Segment Overrun",
"Invalid TSS",
"Segment Not Present",
"Stack-Segment Fault",
"General Protection Fault",
"Page Fault",
"RESERVED",
"x87 Floating-Point",
"Alignment Check",
"Machine Check",
"SIMD Floating-Point",
"Virtualization",
"Security Exception"
};

typedef struct __attribute__((packed))
{
    uint16_t size;
    uint64_t addr;
} idtr;

static idtdesc entries[256] = {0};
static idtr idtptr = {0};
extern void* isr_stub_table[];

void idt_setdesc(uint64_t vec, void* isr, uint8_t flgs)
{
    idtdesc* desc = &entries[vec];

    desc->offset_1 = (uint64_t)isr & 0xFFFF;
    desc->selector = 0x28;
    desc->ist = 0;
    desc->type_attributes = flgs;
    desc->offset_2 = ((uint64_t)isr >> 16) & 0xFFFF;
    desc->offset_3 =  ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    desc->zero = 0;
}
//a

void idt_init()
{
    idtptr.size = (uint16_t)sizeof(entries)-1;
    idtptr.addr = (uintptr_t)&entries[0];

    for(uint64_t v = 0; v < 256; v++)
    {
        idt_setdesc(v, isr_stub_table[v], 0x8E);
    }
    
    asm volatile ("lidt %0" :: "m"(idtptr));
    
    asm volatile ("sti");

    picInit();
}


void inthandler(Registers *regs);
// EXCEPTION STUFF:
void inthandler(Registers *regs)
{
    if(regs->int_no < 0x20){
        printf("Exception Caught: RIP -> %x || %s - %d : %x", regs->rip, exception_str[regs->int_no], regs->int_no, regs->error_code);
        asm volatile("cli; hlt");
    }
    else
    {
        switch(regs->int_no)
        {
            case 0x20:
                CountTimerUp();
                picSendEOI(0); 
                break;
        }
    }
    
}
#endif