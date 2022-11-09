#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "H_BRIDGE_config.h"
#include "H_BRIDGE_interface.h"


void H_BRIDGE_Initialize(){
	GPIO_SetPinMode(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_OUTPUT_GP_PP_10MHZ);
	GPIO_SetPinMode(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_OUTPUT_GP_PP_10MHZ);
}

void H_BRIDGE_SetDirection(u8 Direction){
	switch(Direction){
		case STOP:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_LOW);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_LOW);
			break;
		case RIGHT:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_HIGH);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_LOW);	
			break;
		case LEFT:
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_0,GPIO_LOW);
			GPIO_SetPinValue(H_BRIDGE_PORT,H_BRIDGE_CONTROL_1,GPIO_HIGH);
			break;
	}
}