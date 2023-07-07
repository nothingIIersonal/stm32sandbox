#include <stm32f070rb_base.h>


void setup()
{
    // I/O Port A and Port C enable (set 17th and 19th bits to 1)
    SET_BIT(*RCC_AHBENR, 17);
    SET_BIT(*RCC_AHBENR, 19);

    // set GPIOA Port PA5 mode to 'general purpose output mode'
    SET_BIT(*GPIOA_MODER, 10);

    // set GPIOC Port PC13 mode to 'input mode (reset state)'
    UNSET_BIT(*GPIOC_MODER, 26);
    UNSET_BIT(*GPIOC_MODER, 27);

    // set PA5 bit for enable LED
    SET_BIT(*GPIOA_BSRR, 5);
}


int work()
{
    delay(2000000); // wait a some time to simulate a big deal

    uint32_t cycles = 500000;

    for (;;)
    {
        SET_BIT(*GPIOA_BSRR, 5 + 16); // disable LED

        delay(cycles);

        SET_BIT(*GPIOA_BSRR, 5); // enable LED

        delay(cycles);

        while ( !CHECK_BIT(*GPIOC_IDR, 13) ); // if the 'B2' button is pressed do nothing
    }

    return 0;
}


int main()
{
    setup();
    
    if ( !work() )
        return -1;

    return 0;
}
