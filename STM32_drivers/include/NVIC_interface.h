/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


//#define		NVIC_GROUP_4_BITS		0x05FA0300
//#define		NVIC_GROUP_3_BITS		0x05FA0400
//#define		NVIC_GROUP_2_BITS		0x05FA0500
//#define		NVIC_GROUP_1_BITS		0x05FA0600
//#define		NVIC_GROUP_0_BITS		0x05FA0700

//#define		NVIC_GROUP_4_BITS		0
//#define		NVIC_GROUP_3_BITS		1
//#define		NVIC_GROUP_2_BITS		2
//#define		NVIC_GROUP_1_BITS		3
//#define		NVIC_GROUP_0_BITS		4


/*
 * NVIC_voidInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities
 */
void NVIC_voidInit(void);


/*
 * NVIC_voidEnableInterrupt
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPosition);


/*
 * NVIC_voidDisableInterrupt
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPosition);

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPosition);


/*
 * NVIC_voidClearPendingFlag
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPosition);

/*
 * NVIC_u8GetActiveFlag
 * parameters:
 * return value:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPosition);

/*
 * NVIC_voidSetPriority
 * parameters:
 * return value:
 * description: Sets the priority for a specific interrupt
 */
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 SCB_PRIORITY_DISTRIBUTION);

#endif /* NVIC_INTERFACE_H_ */
