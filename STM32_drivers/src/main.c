#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"

#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "SYSTICK/SYSTICK_interface.h"
#include "USART/USART_interface.h"
#include "TIMER/TIMER_interface.h"
#include "EXTI/EXTI_interface.h"
#include "NVIC/NVIC_interface.h"
#include "DMA/DMA_interface.h"

#include "MOTORS/MOTORS_interface.h"
#include "ULTRASONIC/UltraSonic_interface.h"

void RCC_init();
void GPIO_init();
u8 receiveBuffer[1] = {0};
u8 count = 0;
int main(void)
{
    
    RCC_systemInit(); // system clock
    RCC_init();       // general clock enable
    GPIO_init();      // general gpio enable
    MOTORS_init();    // motor driver gpio/clock

    DMA_UART1_receive(receiveBuffer, 1);    // enable DMA processor for UART1 receive
    USART_enableReceiveWithDMA(USART_1);    // enable UART1 receive DMA bit
    USART_enableTransmitWithDMA(USART_1);   // enable UART1 transmit DMA bit
    USART_Start(BAUD_RATE_115200, USART_1); // start UART1

    while (1)
    {
        if (receiveBuffer[0] == 's')
        {
            DMA_UART1_transmit((u8 *)"Motors: stopped\n", 17); // send status
            DMA_UART1_transmit(&count, 1);
            count++;
            MOTORS_setDirection(STOP);                         // stop motors
            receiveBuffer[0] = '0';                            // reset buffer
        }
        else if (receiveBuffer[0] == 'f')
        {
            DMA_UART1_transmit((u8 *)"Motors: forward\n", 17);
            MOTORS_setDirection(FORWARD);
            MOTORS_setSpeed(100);
            receiveBuffer[0] = '0';
        }
        else if (receiveBuffer[0] == 'b')
        {
            DMA_UART1_transmit((u8 *)"Motors: backward\n", 18);
            MOTORS_setDirection(BACKWARD);
            MOTORS_setSpeed(100);
            receiveBuffer[0] = '0';
        }
        else if (receiveBuffer[0] == 'r')
        {
            DMA_UART1_transmit((u8 *)"Motors: right\n", 15);
            MOTORS_setDirection(RIGHT);
            MOTORS_setSpeed(100);
            receiveBuffer[0] = '0';
        }
        else if (receiveBuffer[0] == 'l')
        {
            DMA_UART1_transmit((u8 *)"Motors: left\n", 14);
            MOTORS_setDirection(LEFT);
            MOTORS_setSpeed(100);
            receiveBuffer[0] = '0';
        }
    }
    return 0;
}
void RCC_init()
{
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOB);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOC);
    RCC_PeripheralClockEnable(RCC_AHB, RCC_DMA1);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_USART1);
}
void GPIO_init()
{
    GPIO_SetPinMode(GPIO_PORTC, PIN13, GPIO_OUTPUT_GP_PP_10MHZ);
    GPIO_SetPinMode(GPIO_PORTA, USART_TxPin, GPIO_OUTPUT_ALT_OD_2MHZ);
    GPIO_SetPinMode(GPIO_PORTA, USART_RxPin, GPIO_INPUT_FLOATING);
    GPIO_SetPinValue(GPIO_PORTC, PIN13, 1);
}
