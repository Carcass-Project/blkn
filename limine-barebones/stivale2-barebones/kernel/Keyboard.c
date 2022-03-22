#include "Keyboard.h"
#include "libc/stdio.h"

uint64_t inputBufUsed = 0;

void clearBuffer()
{
    for(int i=0; i<sizeof(buffer)/sizeof(char); i++)
    {
        buffer[i] = '\0';
    }
}

void KeyboardHandler0(uint8_t key)
{
    switch(key)
    {
        case VK_A: buffer[inputBufUsed++] = 'a'; break;
        case VK_B: buffer[inputBufUsed++] = 'b'; break;
        case VK_C: buffer[inputBufUsed++] = 'c'; break;
        case VK_D: buffer[inputBufUsed++] = 'd'; break;
        case VK_E: buffer[inputBufUsed++] = 'e'; break;
        case VK_F: buffer[inputBufUsed++] = 'f'; break;
        case VK_G: buffer[inputBufUsed++] = 'g'; break;
        case VK_H: buffer[inputBufUsed++] = 'h'; break;
        case VK_I: buffer[inputBufUsed++] = 'i'; break;
        case VK_J: buffer[inputBufUsed++] = 'j'; break;
        case VK_K: buffer[inputBufUsed++] = 'k'; break;
        case VK_L: buffer[inputBufUsed++] = 'l'; break;
        case VK_M: buffer[inputBufUsed++] = 'm'; break;
        case VK_N: buffer[inputBufUsed++] = 'n'; break;
        case VK_O: buffer[inputBufUsed++] = 'o'; break;
        case VK_P: buffer[inputBufUsed++] = 'p'; break;
        case VK_Q: buffer[inputBufUsed++] = 'q'; break;
        case VK_R: buffer[inputBufUsed++] = 'r'; break;
        case VK_S: buffer[inputBufUsed++] = 's'; break;
        case VK_T: buffer[inputBufUsed++] = 't'; break;
        case VK_U: buffer[inputBufUsed++] = 'u'; break;
        case VK_V: buffer[inputBufUsed++] = 'v'; break;
        case VK_W: buffer[inputBufUsed++] = 'w'; break;
        case VK_X: buffer[inputBufUsed++] = 'x'; break;
        case VK_Y: buffer[inputBufUsed++] = 'y'; break;
        case VK_Z: buffer[inputBufUsed++] = 'z'; break;
        case VK_DOT: buffer[inputBufUsed++] = '.'; break;
        case VK_SPACE: buffer[inputBufUsed++] = ' '; break;
        case VK_ENTER: printf("%s", buffer); inputBufUsed=0; clearBuffer();  break;
    }
    
}