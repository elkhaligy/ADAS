#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

// Macros

#define SYSTICK_AHB_8 0
#define SYSTICK_AHB 1

/**
 * @brief Selects the clock source of the SysTick (AHB, AHB/8)
 *
 * @param ClkSRC
 */
void TICK_Init(u8 ClkSRC);

/**
 * @brief Stops the timer
 *
 */
void TICK_Stop(void);

/**
 * @brief Starts synchronous busy wait
 *
 * @param Millis
 */
void TICK_Delay(u32 Millis);

/**
 * @brief Starts a periodic wait (asynchronous)
 *
 * @param Millis
 * @param ptr
 */
void TICK_PeriodicInterval(u32 Millis, void (*ptr)(void));

/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 */

/**
 * @brief Stats a single interval wait (asynchronous)
 *
 * @param Millis
 * @param ptr
 */
void TICK_SingleInterval(u32 Millis, void (*ptr)(void));

/**
 * @brief Gets the number of ticks remaining until we reach zero
 *
 * @return u32
 */
u32 TICK_RemainingTicks(void);

/**
 * @brief Gets the number of ticks elapsed since we started counting
 *
 * @return u32
 */
u32 TICK_ElapsedTicks(void);

#endif /* SYSTICK_INTERFACE_H_ */
