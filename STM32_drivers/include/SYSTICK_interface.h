/*
 * SYSTICK_interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: omar
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

//Macros

#define SYSTICK_AHB_8 		0
#define SYSTICK_AHB 		1

/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */

void STK_Init(u8 ClkSRC);

/*
 * STK_voidStopTimer
 * description: Stops the Timer
 */

void STK_StopTimer(void);

/*
 * STK_voidSetBusyWait
 * description: Starts a synchronous wait (delay)
 */

void STK_SetBusyWait(u32 MillisecCount);

/*
 * STK_voidSetPeriodicInterval
 * description: Starts a periodic interval asynchronous wait
 */

void STK_SetPeriodicInterval(u32 MillisecCount, void (*ptr)(void));

/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 */

void STK_SetSingleInterval(u32 MillisecCount, void (*ptr)(void));

/*
 * STK_u32GetRemainingTicks
 * description: Gets the number of ticks remaining until we reach zero
 */

u32 STK_GetRemainingTicks(void);

/*
 * STK_u32GetElapsedTicks
 * description: Gets the number of ticks elapsed since we started counting
 */

u32 STK_GetElapsedTicks(void);




#endif /* SYSTICK_INTERFACE_H_ */
