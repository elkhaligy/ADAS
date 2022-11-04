/*
 * SYSTICK_program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: omar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

void (*CallBack)(void) = (void *) 0;
u8 IntervalState = SYSTICK_PERIODIC_INTERVAL;

/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */

void STK_Init(u8 ClkSRC)
{
	switch(ClkSRC)
	{
	case SYSTICK_AHB_8:
		CLR_BIT(SYSTICK->CTRL,2);
	break;

	case SYSTICK_AHB:
		SET_BIT(SYSTICK->CTRL,2);
	break;
	}
}

/*
 * STK_voidStopTimer
 * description: Stops the Timer
 */

void STK_StopTimer(void)
{
	CLR_BIT(SYSTICK->CTRL,0);
	SYSTICK->VAL = 0;
}

/*
 * STK_voidSetBusyWait
 * description: Starts a synchronous wait (delay)
 */

void STK_SetBusyWait(u32 MillisecCount)
{
	/* Disable the systick interrupt
	 * Set LOAD value
	 * start the timer
	 * empty loop until the flag is raised
	 * reset the flag
	 * Reset the LOAD register
	 * stop the timer
	 */
	u32 TickCount = MillisecCount*1000;
	CLR_BIT(SYSTICK->CTRL, 1);
	SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
	SYSTICK->VAL = 0;
	SET_BIT(SYSTICK->CTRL, 0);
	while(!(GET_BIT(SYSTICK->CTRL, 16)))
	{
		__asm("NOP");
	}
	CLR_BIT(SYSTICK->CTRL, 0);
	SYSTICK->VAL = 0;
}

/*
 * STK_voidSetPeriodicInterval
 * description: Starts a periodic interval asynchronous wait
 */

void STK_SetPeriodicInterval(u32 MillisecCount, void (*ptr)(void))
{
	/* Set LOAD value
	 * assign the callback function to the handler
	 * Enable the interrupt
	 * start the timer
	 */
	u32 TickCount = MillisecCount*1000;
	IntervalState = SYSTICK_PERIODIC_INTERVAL;
	SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
	CallBack = ptr;
	SET_BIT(SYSTICK->CTRL, 1);
	SET_BIT(SYSTICK->CTRL, 0);
}

/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 */

void STK_SetSingleInterval(u32 MillisecCount, void (*ptr)(void))
{
	/* Set LOAD value
	 * assign the callback function to the handler
	 * Enable the interrupt
	 * start the timer
	 */
	u32 TickCount = MillisecCount*1000;
	IntervalState = SYSTICK_SINGLE_INTERVAL;
	SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
	CallBack = ptr;
	SET_BIT(SYSTICK->CTRL, 1);
	SET_BIT(SYSTICK->CTRL, 0);
}

/*
 * STK_u32GetRemainingTicks
 * description: Gets the number of ticks remaining until we reach zero
 */

u32 STK_GetRemainingTicks(void)
{
	u32 temp1 = 0;
	temp1 = SYSTICK->VAL;
	return temp1;
}

/*
 * STK_u32GetElapsedTicks
 * description: Gets the number of ticks elapsed since we started counting
 */

u32 STK_GetElapsedTicks(void)
{
	u32 temp1 = 0;
    u32 temp2 = 0;
    u32 result = 0;
    temp1 = SYSTICK->LOAD;
    temp2 = SYSTICK->VAL;
    result = temp1 - temp2;
    return result;
}

void SysTick_Handler(void)
{
	CallBack();
	if(IntervalState == SYSTICK_PERIODIC_INTERVAL)
	{}
	else
	{
		CLR_BIT(SYSTICK->CTRL, 0);
	}
	SYSTICK->VAL = 0; // Clearing the flag
}
