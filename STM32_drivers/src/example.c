#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"

#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "EXTI/EXTI_interface.h"
#include "NVIC/NVIC_interface.h"

#include "H_BRIDGE/H_BRIDGE_interface.h"
#include "ULTRASONIC/UltraSonic_interface.h"
u32 Ticks = 0;
u8 seconds = 0;
float Time;
float Distance;
int main(void)
{
    RCC_Init(); // system internal clock
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOC);
    USART_Start(BAUD_RATE_115200, USART_1);
    GPIO_SetPinMode(GPIO_PORTC, PIN13, GPIO_OUTPUT_GP_PP_10MHZ); // built-in LED
    GPIO_SetPinValue(GPIO_PORTC, PIN13, GPIO_HIGH);

    GPIO_SetPinMode(GPIO_PORTA, 0, GPIO_INPUT_PULLING); // pin A0 (interrupt) as input
    GPIO_SetPinValue(GPIO_PORTA, 0, GPIO_LOW);

    EXTI_void_ControlInterruptLine(0, EXTI_LINE_ENABLE);         // enable external interrupt line 0 (EXTI0) (A0)
    EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_RISING); // select trigger type (rising edge)
    NVIC_voidEnableInterrupt(6);                                 // enable interrupt 6 (EXTI0)

    UltrSonic_INIT();

    while (1)
    {
        UltraSonic_Trigger();
        if (Distance < 5)
        {
            GPIO_SetPinValue(GPIO_PORTC, PIN13, 0);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTC, PIN13, 1);
        }
        // USART_SendByte(USART_1,Time);
    }
    return 0;
}

void EXTI0_IRQHandler(void)
{
    static u8 x = 0;

    static u8 f = 0;
    if (f == 0)
    {
        TICK_StartCounting();
        EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_FALLING);

        f = 1;
    }
    else if (f == 1)
    {

        Ticks = TICK_ElapsedTicks();
        Time = (float)Ticks / 1000000;
        Distance = (Time / 2) * 34300;
        TICK_Stop();
        f = 0;
        EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_RISING);
        // GPIO_SetPinValue(GPIO_PORTC, PIN13, x);
    }

    EXTI_void_ClearFlag(0);
}
