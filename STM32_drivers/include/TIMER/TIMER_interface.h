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

#define TIMER_CHANNEL_1 0
#define TIMER_CHANNEL_2 1
#define TIMER_CHANNEL_3 2
#define TIMER_CHANNEL_4 3

#define TIMER_NUM_2 0
#define TIMER_NUM_3 1
#define TIMER_NUM_4 2
#define TIMER_NUM_5 3

/**
 * @brief Initializing the timer2
 *
 */

void TIMER_Init(u8 TIMER_NUMBER, u8 TIMER_CHANNEL);

/**
 * @brief Setting the duty of the PWM for a certain channel in timer2
 *
 */

void TIMER_PWM(u8 PWM_PERCENTAGE, u8 TIMER_NUMBER, u8 TIMER_CHANNEL);

void TIMER_startCounting(u8 TIMER_NUMBER);

u16 TIMER_elapsedTicks(u8 TIMER_NUMBER);

void TIMER_stopCounting(u8 TIMER_NUMBER);


#endif /* TIMER_INTERFACE */
