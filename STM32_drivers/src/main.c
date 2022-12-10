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

u8 USART_DMA_ReceiveArr[1] = {0};
void UART1_DMA_receiveInit()
{
    DMA_SetPeripheralAddress(4, (u32 *)0x40013804);
    DMA_SetMemoryAddress(4, (u32 *)USART_DMA_ReceiveArr);
    DMA_SetDataSize(4, 1); // need to understand
    DMA_ChannelPriority(4);
    DMA_ControlDataTransferDir(4, 0);
    DMA_DisableMemorytoMemoryMode(4);
    DMA_ControlCircularMode(4, 1);
    DMA_ControlPeripheralIncrementMode(4, 0);
    DMA_ControlMemoryIncrementMode(4, 1);
    DMA_SetPeripheralSize(4, DMA_8bits);
    DMA_SetMemorySize(4, DMA_8bits);
    DMA_EnableTransferCompleteInterrupt(4);
    DMA_ActivateChannel(4);
}
int main(void)
{
    RCC_systemInit(); // system clock
    RCC_init();       // general rcc
    GPIO_init();      // general gpio
    MOTORS_init();    // motor driver gpio/clock
    //GPIO_SetPinValue(GPIO_PORTB, PIN4, 0);
    NVIC_voidEnableInterrupt(15);
    UART1_DMA_receiveInit();
    USART_Start(BAUD_RATE_115200, USART_1);
    USART_DMA_Receive_Init(USART_1, BAUD_RATE_115200);
   // MOTORS_setDirection(FORWARD);
   // MOTORS_setSpeed(100);
    while (1)
    {
        if (USART_DMA_ReceiveArr[0] == 's')
        {
            MOTORS_setDirection(STOP);
           // MOTORS_setSpeed(0);
        }
        else if(USART_DMA_ReceiveArr[0]=='f'){
            MOTORS_setDirection(FORWARD);
            MOTORS_setSpeed(100);
        }
        else if(USART_DMA_ReceiveArr[0]=='b'){
            MOTORS_setDirection(BACKWARD);
            MOTORS_setSpeed(100);
        }
        else if (USART_DMA_ReceiveArr[0] == 'r')
        {
            MOTORS_setDirection(RIGHT);
            MOTORS_setSpeed(100);
        }
        else if (USART_DMA_ReceiveArr[0] == 'l')
        {
            MOTORS_setDirection(LEFT);
            MOTORS_setSpeed(100);
        }
    }
    return 0;
}
void RCC_init()
{
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOB);

    RCC_PeripheralClockEnable(RCC_AHB, RCC_DMA1);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOC);
    RCC_PeripheralClockEnable(RCC_APB2, RCC_USART1);
}
void GPIO_init()
{
    GPIO_SetPinMode(GPIO_PORTC, PIN13, GPIO_OUTPUT_GP_PP_10MHZ);
    GPIO_SetPinMode(GPIO_PORTA, USART_TxPin, GPIO_OUTPUT_ALT_OD_2MHZ);
    GPIO_SetPinMode(GPIO_PORTA, PIN10, GPIO_INPUT_FLOATING);
    GPIO_SetPinValue(GPIO_PORTC, PIN13, 1);
}
void DMA1_Channel5_IRQHandler(void)
{
   // GPIO_SetPinValue(GPIO_PORTC, PIN13, 0);
    DMA_Channel5_ClearInterruptStatus();
}
