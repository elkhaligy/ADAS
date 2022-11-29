// libraries
#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"

// own driver files
#include "TIMER/TIMER_interface.h"
#include "TIMER/TIMER_config.h"
#include "TIMER/TIMER_private.h"

void TIM2_Init(u8 TIM_CHANNEL){

    TIM2_PER->CR1_REG |= 0b00 << 5;            // Edge Aligned Mode
    TIM2_PER->CR1_REG |= 0b0 << 4;             // Direction upcounting
    TIM2_PER->CR1_REG |= 0b1 << 7;             // Auto reload enable



    switch (TIM_CHANNEL) {
	case TIM_CHANNEL_1:
        TIM2_PER->CCMR1_REG |= 0b110 << 4;     // PWM mode 1 enable upcounting
        TIM2_PER->CCMR1_REG |= 0b1 << 3;       // Output compare 1 preload enable
        TIM2_PER->CCER_REG |= 0b1 << 0;        // signal is output on the corresponding output pin.
		break;
	case TIM_CHANNEL_2:
        TIM2_PER->CCMR1_REG |= 0b110 << 12;
        TIM2_PER->CCMR1_REG |= 0b1 << 11; 
        TIM2_PER->CCER_REG |= 0b1 << 4;
		break;
	case TIM_CHANNEL_3:
        TIM2_PER->CCMR2_REG |= 0b110 << 4;
        TIM2_PER->CCMR2_REG |= 0b1 << 3; 
        TIM2_PER->CCER_REG |= 0b1 << 8;
		break;
	case TIM_CHANNEL_4:
        TIM2_PER->CCMR2_REG |= 0b110 << 12;
        TIM2_PER->CCMR2_REG |= 0b1 << 11; 
        TIM2_PER->CCER_REG |= 0b1 << 12;
		break;
	}

    TIM2_PER->CNT_REG = 0xFFFF;        // Load cnt with maximum value

    TIM2_PER->DMAR_REG = 0b1;          //DMA Bit

    TIM2_PER->CR1_REG |= 0b1 << 0;     // Enable timer
}

void TIM2_PWMSet(u32 PWM, u8 TIM_CHANNEL){
    switch (TIM_CHANNEL) {
	case TIM_CHANNEL_1:
        TIM2_PER->CCR1_REG &= 0x0000;
        TIM2_PER->CCR1_REG |= PWM;  //Load the compare value
		break;
	case TIM_CHANNEL_2:
        TIM2_PER->CCR2_REG &= 0x0000;
        TIM2_PER->CCR2_REG |= PWM;
		break;
	case TIM_CHANNEL_3:
        TIM2_PER->CCR3_REG &= 0x0000;
        TIM2_PER->CCR3_REG |= PWM;
		break;
	case TIM_CHANNEL_4:
        TIM2_PER->CCR4_REG &= 0x0000;
        TIM2_PER->CCR4_REG |= PWM;
		break;
	}
}
