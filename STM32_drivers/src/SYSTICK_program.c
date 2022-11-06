#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"

void (*CallBack)(void) = (void *)0;
u8 IntervalState = SYSTICK_PERIODIC_INTERVAL;

void TICK_Init(u8 ClkSRC) {
    switch (ClkSRC) {
    case SYSTICK_AHB_8:
        CLR_BIT(SYSTICK->CTRL, 2);
        break;

    case SYSTICK_AHB:
        SET_BIT(SYSTICK->CTRL, 2);
        break;
    }
}

void TICK_Stop(void) {
    CLR_BIT(SYSTICK->CTRL, 0);
    SYSTICK->VAL = 0;
}

void TICK_Delay(u32 Millis) {
    /* Disable the systick interrupt
     * Set LOAD value
     * start the timer
     * empty loop until the flag is raised
     * reset the flag
     * Reset the LOAD register
     * stop the timer
     */
    u32 TickCount = Millis * 1000;
    CLR_BIT(SYSTICK->CTRL, 1);
    SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
    SYSTICK->VAL = 0;
    SET_BIT(SYSTICK->CTRL, 0);
    while (!(GET_BIT(SYSTICK->CTRL, 16))) {
        __asm("NOP");
    }
    CLR_BIT(SYSTICK->CTRL, 0);
    SYSTICK->VAL = 0;
}

void TICK_PeriodicInterval(u32 Millis, void (*ptr)(void)) {
    /* Set LOAD value
     * assign the callback function to the handler
     * Enable the interrupt
     * start the timer
     */
    u32 TickCount = Millis * 1000;
    IntervalState = SYSTICK_PERIODIC_INTERVAL;
    SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
    CallBack = ptr;
    SET_BIT(SYSTICK->CTRL, 1);
    SET_BIT(SYSTICK->CTRL, 0);
}

void TICK_SingleInterval(u32 Millis, void (*ptr)(void)) {
    /* Set LOAD value
     * assign the callback function to the handler
     * Enable the interrupt
     * start the timer
     */
    u32 TickCount = Millis * 1000;
    IntervalState = SYSTICK_SINGLE_INTERVAL;
    SYSTICK->LOAD = (TickCount - 1) & 0x00FFFFFF;
    CallBack = ptr;
    SET_BIT(SYSTICK->CTRL, 1);
    SET_BIT(SYSTICK->CTRL, 0);
}

void TICK_StartCounting(void){
    IntervalState = SYSTICK_SINGLE_INTERVAL;
    SYSTICK->LOAD = 0xFFFFFF;
    SET_BIT(SYSTICK->CTRL, 1);
    SET_BIT(SYSTICK->CTRL, 0);
}

u32 TICK_RemainingTicks(void) {
    u32 temp1 = 0;
    temp1 = SYSTICK->VAL;
    return temp1;
}

u32 TICK_ElapsedTicks(void) {
    u32 temp1 = 0;
    u32 temp2 = 0;
    u32 result = 0;
    temp1 = SYSTICK->LOAD;
    temp2 = SYSTICK->VAL;
    result = temp1 - temp2;
    return result;
}

void SysTick_Handler(void) {
    CallBack();
    if (IntervalState == SYSTICK_PERIODIC_INTERVAL) {
    } else {
        CLR_BIT(SYSTICK->CTRL, 0);
    }
    SYSTICK->VAL = 0; // Clearing the flag
}
