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
    TIM2_PER->CR1_REG |= 0b1 << 0; // Enable timer

    TIM2_PER->CCMR1_REG |= 0b110 << 4; // PWM mode 1 enable upcounting
}
