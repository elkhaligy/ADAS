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

/**
 * @brief Initializing the timer
 * 
 */
void TIM_Init(void);
void TIM_PWMSet(u32 PWM);
#endif /* TIMER_INTERFACE */
