#ifndef STM32F070RB_FUNCTIONS_H
#define STM32F070RB_FUNCTIONS_H


// something similar to a delay of "cycles" cycles
void delay(uint32_t cycles)
{
    while (cycles--)
        asm("nop");
}


#endif