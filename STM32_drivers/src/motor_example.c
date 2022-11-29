#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "H_BRIDGE/H_BRIDGE_interface.h"

int main2(void)
{
    RCC_Init(); // system internal clock
    H_BRIDGE_Initialize(); // initialize H-Bridge 

    while (1)
    {
        // A program to run the motor in forward direction speed 0 to 100
        // and then in reverse direction speed 0 to 100
        H_BRIDGE_SetDirection(Forward);
        for (u8 i = 0; i <= 100; i++)
        {
            H_BRIDGE_SetSpeed(i);
            TICK_Delay(100);
        }
        H_BRIDGE_SetDirection(Reverse);
        for (u8 i = 0; i <= 100; i++)
        {
            H_BRIDGE_SetSpeed(i);
            TICK_Delay(100);
        }
    }
    return 0;
}
