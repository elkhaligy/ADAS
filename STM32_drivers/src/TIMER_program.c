// libraries
#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"

// own driver files
#include "TIMER/TIMER_interface.h"
#include "TIMER/TIMER_config.h"
#include "TIMER/TIMER_private.h"

void TIMER_Init(u8 TIMER_NUMBER, u8 TIMER_CHANNEL)
{
    switch (TIMER_NUMBER)
    {
    case TIMER_NUM_2:
        TIMER2_PER->CR1_REG |= 0b00 << 5; // Edge Aligned Mode
        TIMER2_PER->CR1_REG |= 0b0 << 4;  // Direction upcounting
        TIMER2_PER->CR1_REG |= 0b1 << 7;  // Auto reload enable
        switch (TIMER_CHANNEL)
        {
        case TIMER_CHANNEL_1:
            TIMER2_PER->CCMR1_REG |= 0b110 << 4; // PWM mode 1 enable upcounting
            TIMER2_PER->CCMR1_REG |= 0b1 << 3;   // Output compare 1 preload enable
            TIMER2_PER->CCER_REG |= 0b1 << 0;    // signal is output on the corresponding output pin.
            break;
        case TIMER_CHANNEL_2:
            TIMER2_PER->CCMR1_REG |= 0b110 << 12;
            TIMER2_PER->CCMR1_REG |= 0b1 << 11;
            TIMER2_PER->CCER_REG |= 0b1 << 4;
            break;
        case TIMER_CHANNEL_3:
            TIMER2_PER->CCMR2_REG |= 0b110 << 4;
            TIMER2_PER->CCMR2_REG |= 0b1 << 3;
            TIMER2_PER->CCER_REG |= 0b1 << 8;
            break;
        case TIMER_CHANNEL_4:
            TIMER2_PER->CCMR2_REG |= 0b110 << 12;
            TIMER2_PER->CCMR2_REG |= 0b1 << 11;
            TIMER2_PER->CCER_REG |= 0b1 << 12;
            break;
        }
        TIMER2_PER->CNT_REG = 0xFFFF;    // Load cnt with maximum value
        TIMER2_PER->DMAR_REG = 0b1;      // DMA Bit
        TIMER2_PER->CR1_REG |= 0b1 << 0; // Enable timer
        break;
    case TIMER_NUM_3:
        CLR_BIT(TIMER3_PER->CR1_REG, 5); // Edge Aligned Mode
        CLR_BIT(TIMER3_PER->CR1_REG, 6);
        CLR_BIT(TIMER3_PER->CR1_REG, 4); // Direction downcounting

        //SET_BIT(TIMER3_PER->CR1_REG, 7); // Auto reload enable

        //TIMER3_PER->PSC_REG = 0x00000007; // Set prescaler to 8
        break;
    }
}

void TIMER_PWM(u8 PWM_PERCENTAGE, u8 TIMER_NUMBER, u8 TIMER_CHANNEL)
{
    u32 PWM = (PWM_PERCENTAGE * 0xFFFF) / 100;
    switch (TIMER_CHANNEL)
    {
    case TIMER_CHANNEL_1:
        TIMER2_PER->CCR1_REG &= 0x0000;
        TIMER2_PER->CCR1_REG |= PWM; // Load the compare value
        break;
    case TIMER_CHANNEL_2:
        TIMER2_PER->CCR2_REG &= 0x0000;
        TIMER2_PER->CCR2_REG |= PWM;
        break;
    case TIMER_CHANNEL_3:
        TIMER2_PER->CCR3_REG &= 0x0000;
        TIMER2_PER->CCR3_REG |= PWM;
        break;
    case TIMER_CHANNEL_4:
        TIMER2_PER->CCR4_REG &= 0x0000;
        TIMER2_PER->CCR4_REG |= PWM;
        break;
    }
}

void TIMER_startCounting(u8 TIMER_NUMBER)
{
    switch (TIMER_NUMBER)
    {
    case TIMER_NUM_3:
        TIMER3_PER->ARR_REG = 0x0000FFFF;
        SET_BIT(TIMER3_PER->CR1_REG, 0); // Enable counter
        break;
    }
}

u16 TIMER_elapsedTicks(u8 TIMER_NUMBER)
{
    u16 ticks = 0;
    ticks = TIMER3_PER->CNT_REG;
    return ticks;
    // switch (TIMER_NUMBER)
    // {
    // case TIMER_NUM_3:
    //     return TIMER3_PER->CNT_REG;
    //     // u16 num1 = 0;
    //     // u16 num2 = 0;
    //     // u16 result = 0;
    //     // num1 = TIMER3_PER->ARR_REG;
    //     // num2 = TIMER3_PER->CNT_REG;
    //     // result = num1 - num2;
    //     // return result;
    //     // break;
    // }
}

void TIMER_stopCounting(u8 TIMER_NUMBER)
{
    switch (TIMER_NUMBER)
    {
    case TIMER_NUM_3:
        CLR_BIT(TIMER3_PER->CR1_REG, 0); // Disable counter
        TIMER3_PER->CNT_REG = 0x00000000;
        break;
    }
}
