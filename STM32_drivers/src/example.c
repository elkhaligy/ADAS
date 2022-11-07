// Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"
// Interfaces of MCAL
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"



int main(void) {
    // System clock initialize to high speed external clock
    RCC_Init();
    // Enable port GPIOA clock on APB2 bus
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    // Enable USART 1 clock
    RCC_PeripheralClockEnable(RCC_APB2, RCC_USART1);
    
    GPIO_SetPinMode(GPIO_PORTA, USART_Tx, GPIO_OUTPUT_ALT_OD_2MHZ);
    GPIO_SetPinMode(GPIO_PORTA, PIN0, GPIO_INPUT_PULLING);
    GPIO_SetPinMode(GPIO_PORTA, PIN1, GPIO_OUTPUT_GP_PP_2MHZ);

    GPIO_SetPinValue(GPIO_PORTA, PIN0, 0);
    GPIO_SetPinValue(GPIO_PORTA, PIN1, 0);

    // Interrupt line 0 (PIN A0)
    EXTI_void_ControlInterruptLine(0, EXTI_LINE_ENABLE);
    // Interrupt trigger type
    EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_RISING);
    // Enable EXTI0 interrupt
    NVIC_voidEnableInterrupt(6);

    USART_SetBaudRate(BAUD_RATE_9600);
    USART_EnableUSART(USART_1);

    u8 a = 0;
    while (1){
        GPIO_SetPinValue(GPIO_PORTA, PIN1, 1);
        TICK_Delay(1000);
        USART_SendByte(USART_1, a);
        a++;
        GPIO_SetPinValue(GPIO_PORTA, PIN1, 0);
        TICK_Delay(1000);
        USART_SendByte(USART_1, a);
        a++;
    }
    return 0;
}
// Comment this because it is defined in ultrasonic program.c
// void EXTI0_IRQHandler(void)
// {
//     static u8 x = 1;
//     GPIO_SetPinValue(GPIO_PORTA, PIN2, x);
//     // NVIC_voidSetPendingFlag(7);
//     // while(1);
//     x = 1 - x;
// }