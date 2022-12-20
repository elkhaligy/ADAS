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
u32 data = 0;
u32 receive_data()
{
	while (!GPIO_GetPinValue(GPIO_PORTA, PIN1))
		;
	while (GPIO_GetPinValue(GPIO_PORTA, PIN1))
		;

	for (int i = 0; i < 24; i++)
	{
		count = 0;
		while (!(GPIO_GetPinValue(GPIO_PORTA, PIN1)))
			; // wait for pin to go high.. this is 562.5us LOW

		while ((GPIO_GetPinValue(GPIO_PORTA, PIN1))) // count the space length while the pin is high
		{
			count++;
			TICK_DelayUS(100);
		}

		if (count > 12) // if the space is more than 1.2 ms
		{
			// SET_BIT(code, 31 - i);
			data |= (1 << (31 - i)); // write 1
		}

		else
		{
			// CLR_BIT(code, 31 - i);
			data &= ~(1 << (31 - i)); // write 0
		}
	}
	return data;
}

int main(void)
{

	RCC_systemInit(); // system clock
	RCC_init();		  // general clock enable
	GPIO_init();	  // general gpio enable
	MOTORS_init();	  // motor driver gpio/clock

	NVIC_voidEnableInterrupt(NVIC_DMA1_Channel4); // enable DMA1 channel4 interrupt
	DMA_UART1_receive(receiveBuffer, 1);		  // enable DMA processor for UART1 receive
	USART_enableReceiveWithDMA(USART_1);		  // enable UART1 receive DMA bit
	USART_enableTransmitWithDMA(USART_1);		  // enable UART1 transmit DMA bit
	USART_Start(BAUD_RATE_115200, USART_1);		  // start UART1

	
	MOTORS_setSpeed(100);
	MOTORS_setDirection(FORWARD);
	TICK_Delay(2000);
	MOTORS_setDirection(STOP);
	TICK_Delay(1000);
	MOTORS_setDirection(BACKWARD);
	TICK_Delay(2000);
	MOTORS_setDirection(STOP);
	TICK_Delay(1000);
	MOTORS_setDirection(RIGHT);
	TICK_Delay(1000);
	MOTORS_setDirection(STOP);
	TICK_Delay(1000);
	MOTORS_setDirection(LEFT);
	TICK_Delay(1000);
	MOTORS_setDirection(STOP);
	while (1)
	{

		// if (data == 0xff3800)
		// {
		// 	MOTORS_setDirection(STOP); // stop motors
		// }
		// else if (data == 0xff1800)
		// {
		// 	MOTORS_setDirection(FORWARD);
		// }
		// else if (data == 0xff4a00)
		// {
		// 	MOTORS_setDirection(BACKWARD);
		// }
		// else if (data == 0xff5a00)
		// {
		// 	MOTORS_setDirection(RIGHT);
		// }
		// else if (data == 0xff1000)
		// {
		// 	MOTORS_setDirection(LEFT);
		// }
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
	//GPIO_SetPinMode(GPIO_PORTC, PIN13, GPIO_OUTPUT_GP_PP_10MHZ);
	//GPIO_SetPinMode(GPIO_PORTA, PIN1, GPIO_INPUT_PULLING);
	//GPIO_SetPinMode(GPIO_PORTA, USART_TxPin, GPIO_OUTPUT_ALT_OD_2MHZ);
	//GPIO_SetPinMode(GPIO_PORTA, USART_RxPin, GPIO_INPUT_FLOATING);
	//GPIO_SetPinValue(GPIO_PORTC, PIN13, 1);
}
