// libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// own driver files
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void TIM_Init(void){
    TIM2_PER->CR1_REG |= 0b00 << 5; // Edge Aligned Mode
    TIM2_PER->CR1_REG |= 0b0 << 4; // Direction upcounting
    TIM2_PER->CR1_REG |= 0b1 << 7; // Auto reload enable

    TIM2_PER->CCMR1_REG |= 0b110 << 4; // PWM mode 1 enable upcounting
    TIM2_PER->CCMR1_REG |= 0b1 << 3; // preload registr on ccr1 enable

    TIM2_PER->CCER_REG |= 0b1 << 0; // capture compare output 1 enabled

    TIM2_PER->CNT_REG = 0xFFFF; // Load cnt with maxmum value
    TIM2_PER->DMAR_REG = 0b1;
    TIM2_PER->CR1_REG |= 0b1 << 0; // Enable timer
}

void TIM_PWMSet(u32 PWM){
    TIM2_PER->CCR1_REG |= 0x00FF;
}
