#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "EXTI/EXTI_interface.h"
#include "NVIC/NVIC_interface.h"

#include"ULTRASONIC/UltraSonic_config.h"
#include"ULTRASONIC/UltraSonic_interface.h"

u16 Ticks = 0;
u32 Distance;

void UltrSonic_INIT(void){
    RCC_PeripheralClockEnable(RCC_APB2, UltraSonic_PORT_RCC);
    GPIO_SetPinMode(UltraSonic_PORT_GPIO,PIN_Trigger, GPIO_OUTPUT_GP_PP_10MHZ);
}

void UltraSonic_Trigger(void){
    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_HIGH);
    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_LOW);
}

void EXTI0_IRQHandler(void)
{
    static u8 f = 0;
    if (f == 0)
    {
        TIMER_startCounting(TIMER_NUM_3);
        EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_FALLING);
        f = 1;
    }
    else if (f == 1)
    {
        Ticks = TIMER_elapsedTicks(TIMER_NUM_3);
        Distance = ((Ticks / 2) * 34300) / 8000000;
        TIMER_stopCounting(TIMER_NUM_3);
        f = 0;
        EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_RISING);
    }

    EXTI_void_ClearFlag(0);
}