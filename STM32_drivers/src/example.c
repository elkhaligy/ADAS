#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "H_BRIDGE/H_BRIDGE_interface.h"
#include "ULTRASONIC/UltraSonic_interface.h"
int main(void)
{
    RCC_Init(); // system internal clock
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOC);

    GPIO_SetPinMode(GPIO_PORTC, PIN13, GPIO_OUTPUT_GP_PP_10MHZ);
    //GPIO_SetPinMode(GPIO_PORTB, PIN1, GPIO_OUTPUT_GP_PP_10MHZ);

    //GPIO_SetPinValue(GPIO_PORTB, PIN11, GPIO_LOW);
    //GPIO_SetPinValue(GPIO_PORTB, PIN1, GPIO_LOW);

    UltrSonic_INIT();
    //UltraSonic_StartECHO();

    while (1)
    {
        UltraSonic_Trigger();
       // u32 dist = UltrSonic_GetDistance();
        // if(dist<5){
        //     GPIO_SetPinValue(GPIO_PORTC, PIN13, GPIO_HIGH);
        // }
        // else{
        //     GPIO_SetPinValue(GPIO_PORTC, PIN13, GPIO_LOW);
        // }
        TICK_Delay(1000);
    }
    return 0;
}
