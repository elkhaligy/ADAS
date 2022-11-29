#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "TIMER/TIMER_interface.h"

#include "H_BRIDGE/H_BRIDGE_config.h"
#include "H_BRIDGE/H_BRIDGE_interface.h"

void H_BRIDGE_Initialize()
{
	RCC_PeripheralClockEnable(RCC_APB2, H_BRIDGE_PORT_CLOCK);
	GPIO_SetPinMode(H_BRIDGE_PORT, H_BRIDGE_PIN_IN1, GPIO_OUTPUT_GP_PP_10MHZ);
	GPIO_SetPinMode(H_BRIDGE_PORT, H_BRIDGE_PIN_IN2, GPIO_OUTPUT_GP_PP_10MHZ);

	// for speed control
	RCC_PeripheralClockEnable(RCC_APB1, RCC_TIM2);
	RCC_PeripheralClockEnable(RCC_APB2, RCC_AFIO);
	RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
	GPIO_SetPinMode(GPIO_PORTA, H_BRIDGE_PIN_EA, GPIO_OUTPUT_ALT_PP_10MHZ);
	TIMER_Init(TIMER2, TIMER_CHANNEL_1);
}

void H_BRIDGE_SetDirection(u8 Direction)
{
	switch (Direction)
	{
	case Stop:
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN1, GPIO_LOW);
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN2, GPIO_LOW);
		break;
	case Forward:
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN1, GPIO_HIGH);
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN2, GPIO_LOW);
		break;
	case Reverse:
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN1, GPIO_LOW);
		GPIO_SetPinValue(H_BRIDGE_PORT, H_BRIDGE_PIN_IN2, GPIO_HIGH);
		break;
	}
}
void H_BRIDGE_SetSpeed(u8 speedPercentage)
{
	TIMER_PWM(speedPercentage, TIMER2, TIMER_CHANNEL_1);
}