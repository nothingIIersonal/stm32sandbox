#ifndef STM32F070RB_DEFINES_H
#define STM32F070RB_DEFINES_H


// GPIO base
#define GPIOA_BASE 0x48000000
#define GPIOB_BASE 0x48000400
#define GPIOC_BASE 0x48000800
#define GPIOD_BASE 0x48000C00
#define GPIOF_BASE 0x48001400

// GPIO offsets
#define GPIOx_MODER_OFFSET 0x00
#define GPIOx_IDR_OFFSET   0x10
#define GPIOx_BSRR_OFFSET  0x18


// RCC base
#define RCC_BASE 0x40021000 

// RCC offsets
#define RCC_AHBENR_OFFSET 0x14


// AHB interconnect clock register
#define RCC_AHBENR (reg32_t *)(RCC_BASE + RCC_AHBENR_OFFSET) // AHB peripheral clock enable register address


// GPIOA registers
#define GPIOA       (reg32_t *)(GPIOA_BASE)                      // GPIOA base register address
#define GPIOA_MODER (reg32_t *)(GPIOA_BASE + GPIOx_MODER_OFFSET) // GPIOA mode register address
#define GPIOA_BSRR  (reg32_t *)(GPIOA_BASE + GPIOx_BSRR_OFFSET)  // GPIOA bit set/reset register address


// GPIOC register
#define GPIOC       (reg32_t *)(GPIOC_BASE)                      // GPIOC base register address
#define GPIOC_MODER (reg32_t *)(GPIOC_BASE + GPIOx_MODER_OFFSET) // GPIOC mode register address
#define GPIOC_IDR   (reg32_t *)(GPIOC_BASE + GPIOx_IDR_OFFSET)   // GPIOC input data register address


// bit manipulation
#define SHIFT_BIT(BIT)      ( 0b1 << (BIT) )         // shift 1 to "BIT" bits
#define SET_BIT(REG, BIT)   (REG |=  SHIFT_BIT(BIT)) // set "REG"s "BIT" bit to 1 
#define UNSET_BIT(REG, BIT) (REG &= ~SHIFT_BIT(BIT)) // set "REG"s "BIT" bit to 0
#define CHECK_BIT(REG, BIT) (REG &   SHIFT_BIT(BIT)) // check "REG"s "BIT" is 1


#endif