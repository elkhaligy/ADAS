#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "H_BRIDGE/H_BRIDGE_interface.h"

int main(void)
{
    RCC_Init(); // system internal clock
    USART_Start(BAUD_RATE_115200, USART_1);
    u8 a = 0x00;
    while (1)
    {
        USART_SendByte(USART_1, a);
        a++;
        TICK_Delay(1000);
    }
    return 0;
}
