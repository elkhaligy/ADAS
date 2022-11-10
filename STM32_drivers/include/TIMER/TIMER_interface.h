#ifndef TIMER_INTERFACE
#define TIMER_INTERFACE

/*
CR1  DIR Bit When Low then upcounting (done)
ARR  Sets the freq ()
CCR  Sets the duty cycle () 
CCMR by writing 110 in OCxM bits for Mode 1 (done) 
CCMR Setting OCxPE bit and eventually the auto-reload preload register by setting the ARPE bit in the TIMx_CR1 register(done)
CCER CCxP bit for OCx polarity is software programmable (done)
In PWM mode (1 or 2),TIMx_CNT and TIMx_CCRx are always compared to determine whether TIMx_CCRx≤TIMx_CNT or TIMx_CNT≤TIMx_CCRx
(depending on the direction of the counter).
*/

#define    TIM_CHANNEL_1    0
#define    TIM_CHANNEL_2    1
#define    TIM_CHANNEL_3    2
#define    TIM_CHANNEL_4    3

/**
 * @brief Initializing the timer2
 * 
 */

void TIM2_Init(u8 TIM_CHANNEL);

/**
 * @brief Setting the duty of the PWM for a certain channel in timer2
 * 
 */

void TIM2_PWMSet(u32 PWM, u8 TIM_CHANNEL);

#endif /* TIMER_INTERFACE */
