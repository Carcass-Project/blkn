#include "PIC.h"

void picRemap(int offset1, int offset2)
{
    uint8_t a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    
    outb(PIC1_DATA, offset1); 
   
    outb(PIC2_DATA, offset2); 
    
    outb(PIC1_DATA, 4);  
    
    outb(PIC2_DATA, 2);   
    
    outb(PIC1_DATA, ICW4_8086);
   
    outb(PIC2_DATA, ICW4_8086);
    

    outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

void irqMaskAll() {
  for (int i = 0; i < 16; i++) irqSetMask(i);
}

void picInit()
{
    picRemap(0x20,0x28);

    //irqMaskAll();
    //irqClearMask(0);
    //irqClearMask(2);
}

void irqSetMask(unsigned char IRQline)
{
    //a
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value);  
}

void irqClearMask(unsigned char IRQline)
{
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(port, value); 
}

uint16_t picGetIrqReg(int ocw3)
{
    outb(PIC1_CMD, ocw3);
    outb(PIC2_CMD, ocw3);
    return (inb(PIC2_CMD) << 8) | inb(PIC1_CMD);
}

uint16_t picGetIRR(void)
{
    return picGetIrqReg(PIC_READ_IRR);
}

uint16_t picGetISR(void)
{
    return picGetIrqReg(PIC_READ_ISR);
}

void picSendEOI(unsigned char irq)
{
    if(irq >= 8)
		outb(PIC2_COMMAND, 0x20);
 
	outb(PIC1_COMMAND, 0x20);
}