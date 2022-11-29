#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"
#include "GPIO/GPIO_interface.h"
#include "RCC/RCC_interface.h"
#include "H_BRIDGE/H_BRIDGE_config.h"
#include "H_BRIDGE/H_BRIDGE_interface.h"


void H_BRIDGE_Initialize(){
	RCC_PeripheralClockEnable(RCC_APB2, H_BRIDGE_CLOCK);
	GPIO_SetPinMode(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_OUTPUT_GP_PP_10MHZ);
	GPIO_SetPinMode(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_OUTPUT_GP_PP_10MHZ);
}

void H_BRIDGE_SetDirection(u8 Direction){
	switch(Direction){
		case Stop:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_LOW);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_LOW);
			break;
		case Forward:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_HIGH);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_LOW);	
			break;
		case Reverse:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_LOW);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_HIGH);
			break;
	}
}