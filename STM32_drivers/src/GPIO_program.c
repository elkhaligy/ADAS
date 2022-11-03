/*
 * GPIO_program.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Omar Gamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"



/*
 * function to set mode of a certain pin
 */

void GPIO_SetPinMode(u8 Port, PINS Pin, u8 Mode){
	switch(Port){
	case GPIO_PORTA:
		if(Pin <= 7){
			GPIO_PORTA_PER->CRL_REG &= (~(0b1111<<(4*Pin)));
			GPIO_PORTA_PER->CRL_REG |= (Mode << (4*Pin));
		}else if(Pin <= 16){
			GPIO_PORTA_PER->CRH_REG &= (~(0b1111<<(4*(Pin-8))));
			GPIO_PORTA_PER->CRH_REG |= (Mode << (4*(Pin-8)));
		}
		break;
	case GPIO_PORTB:
		if(Pin <= 7){
			GPIO_PORTB_PER->CRL_REG &= (~(0b1111<<(4*Pin)));
			GPIO_PORTB_PER->CRL_REG |= (Mode << (4*Pin));
		}else if(Pin <= 16){
			GPIO_PORTB_PER->CRH_REG &= (~(0b1111<<(4*(Pin-8))));
			GPIO_PORTB_PER->CRH_REG |= (Mode << (4*(Pin-8)));
		}
		break;
	case GPIO_PORTC:
		if(Pin <= 7){
			GPIO_PORTC_PER->CRL_REG &= (~(0b1111<<(4*Pin)));
			GPIO_PORTC_PER->CRL_REG |= (Mode << (4*Pin));
		}else if(Pin <= 16){
			GPIO_PORTC_PER->CRH_REG &= (~(0b1111<<(4*(Pin-8))));
			GPIO_PORTC_PER->CRH_REG |= (Mode << (4*(Pin-8)));
		}
		break;
	}
}


/*
 * function to get input value of a certain pin
 */
u8 GPIO_GetPinValue(u8 Port, u8 Pin){
	u8 ReturnValue = 0 ;
	switch(Port){
	case GPIO_PORTA:
		ReturnValue = GET_BIT(GPIO_PORTA_PER->IDR_REG,Pin);
		break;
	case GPIO_PORTB:
		ReturnValue = GET_BIT(GPIO_PORTB_PER->IDR_REG,Pin);
		break;
	case GPIO_PORTC:
		return GET_BIT(GPIO_PORTC_PER->IDR_REG,Pin);
		break;
	}
	return ReturnValue;
}


/*
 * function to set output value of a certain pin
 */
//void GPIO_void_SetPinValue(u8 Copy_u8_Port, u8 Copy_u8_Pin, u8 Copy_u8_PinValue){
//
//	switch(Copy_u8_Port){
//	case GPIO_PORTA:
//		if(Copy_u8_PinValue){
//			SET_BIT(GPIO_PORTA_PER->ODR_REG,Copy_u8_Pin);
//		}else{
//			CLR_BIT(GPIO_PORTA_PER->ODR_REG,Copy_u8_Pin);
//		}
//		break;
//	case GPIO_PORTB:
//		if(Copy_u8_PinValue){
//			SET_BIT(GPIO_PORTB_PER->ODR_REG,Copy_u8_Pin);
//		}else{
//			CLR_BIT(GPIO_PORTB_PER->ODR_REG,Copy_u8_Pin);
//		}
//			break;
//	case GPIO_PORTC:
//		if(Copy_u8_PinValue){
//			SET_BIT(GPIO_PORTC_PER->ODR_REG,Copy_u8_Pin);
//		}else{
//			CLR_BIT(GPIO_PORTC_PER->ODR_REG,Copy_u8_Pin);
//		}
//			break;
//	}
//
//}
/*
 * function to set output value of some pins according to a mask
 */
void GPIO_voidPortMaskWrite(u8 Copy_u8Port, u16 Copy_u16Mask, u16 Copy_u8Value){

	switch(Copy_u8Port){
	case GPIO_PORTA:
		GPIO_PORTA_PER->BSRR_REG = (Copy_u16Mask << 16) | (Copy_u16Mask & Copy_u8Value);
		break;
	case GPIO_PORTB:
		GPIO_PORTB_PER->BSRR_REG = (Copy_u16Mask << 16) | (Copy_u16Mask & Copy_u8Value);
			break;
	case GPIO_PORTC:
		GPIO_PORTC_PER->BSRR_REG = (Copy_u16Mask << 16) | (Copy_u16Mask & Copy_u8Value);
			break;
	}

}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value){
	switch(Port){
	case GPIO_PORTA:
		if(Value){
			GPIO_PORTA_PER->BSRR_REG=(Value<<Pin);
		}else{
			GPIO_PORTA_PER->BSRR_REG=(1<<(Pin+16));
		}
		break;
	case GPIO_PORTB:
		if(Value){
			GPIO_PORTB_PER->BSRR_REG=(Value<<Pin);
		}else{
			GPIO_PORTB_PER->BSRR_REG=(1<<(Pin+16));
		}
			break;
	case GPIO_PORTC:
		if(Value){
			GPIO_PORTC_PER->BSRR_REG=(Value<<Pin);
		}else{
			GPIO_PORTC_PER->BSRR_REG=(1<<(Pin+16));
		}
			break;
	}
}
