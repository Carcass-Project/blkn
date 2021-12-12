#include <stdint.h>

int timerCount;
int timerSeconds;

void PIC_TimerSetup()
{
    timerCount = 0;
    timerSeconds = 0;
}

void TimerCountUp()
{
    timerCount++;
}

void TimerSecondUp()
{
    timerSeconds++;
}

