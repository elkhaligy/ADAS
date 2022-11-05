/*
 * NVIC_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"




/*
 * NVIC_voidInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities
 */
//void NVIC_voidInit(void){
//
//	SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION;
//
////	switch(NVIC_PRIORITY_DISTRIBUTION){
////
////	case NVIC_GROUP_4_BITS:
////		SCB_AIRCR = 0x05FA0300;
////		break;
////	case NVIC_GROUP_3_BITS:
////		SCB_AIRCR = 0x05FA0400;
////		break;
////	case NVIC_GROUP_2_BITS:
////		SCB_AIRCR = 0x05FA0500;
////		break;
////	case NVIC_GROUP_1_BITS:
////		SCB_AIRCR = 0x05FA0600;
////		break;
////	case NVIC_GROUP_0_BITS:
////		SCB_AIRCR = 0x05FA0700;
////		break;
////
////	}
//
//
//}



/*
 * NVIC_voidSetPriority
 * parameters:
 * return value:
 * description: Sets the priority for a specific interrupt
 */

// For NVIC to set priority you need to know what priority user chosen, and that's done in SCB peripheral
//
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority,u32 SCB_PRIORITY_DISTRIBUTION){

	//NVIC_IPR[Copy_u8InterruptPosition] = (Copy_u8GroupPriority<<(4+NVIC_PRIORITY_DISTRIBUTION)) | (Copy_u8SubPriority<<4);
	NVIC_IPR[Copy_u8InterruptPosition] = (Copy_u8GroupPriority<<(4+((SCB_PRIORITY_DISTRIBUTION-0x05FA0300)/0x100))) | (Copy_u8SubPriority<<4);

}








/*
 * NVIC_voidEnableInterrupt
 * parameters: Copy_u8InterruptPotiotion
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion){

	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ISER0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ISER1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}


/*
 * NVIC_voidDisableInterrupt
 * parameters: Copy_u8InterruptPotiotion
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion){
	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ICER0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ICER1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}

/*
 * NVIC_voidSetPendingFlag
 * parameters: Copy_u8InterruptPotiotion
 * description: Sets the pending flag for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion){
	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ISPR0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ISPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}


/*
 * NVIC_voidClearPendingFlag
 * parameters: Copy_u8InterruptPotiotion
 * description: Clears the pending flag for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion){
	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ICPR0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ICPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}

}

/*
 * NVIC_u8GetActiveFlag
 * parameters: Copy_u8InterruptPotiotion
 * return value: u8
 * description: Returns the Active flag for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion){
	u8 ReturnVal=0;
	if(Copy_u8InterruptPotiotion < 32){
		ReturnVal=GET_BIT(NVIC_IABR0,Copy_u8InterruptPotiotion);
	}else if(Copy_u8InterruptPotiotion < 60){
		ReturnVal=GET_BIT(NVIC_IABR1,(Copy_u8InterruptPotiotion-32));
	}
	return ReturnVal;
}
