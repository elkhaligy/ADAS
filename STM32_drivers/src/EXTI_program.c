/*
 * EXTI_program.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Omar Gamal
 */

#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"

#include "EXTI/EXTI_interface.h"
#include "EXTI/EXTI_private.h"
#include "EXTI/EXTI_config.h"



/*
 * Configures the trigger signal EXTI for a certain line
 */
void EXTI_void_SelectLineTriggerType(u8 Copy_u8_EXTI_Line, u8 Copy_u8_TriggerType){
	switch(Copy_u8_TriggerType){
	case EXTI_LineTrigger_RISING:
		SET_BIT(EXTI->RTSR, Copy_u8_EXTI_Line);
		CLR_BIT(EXTI->FTSR, Copy_u8_EXTI_Line);
	break;
	case EXTI_LineTrigger_FALLING:
		CLR_BIT(EXTI->RTSR, Copy_u8_EXTI_Line);
		SET_BIT(EXTI->FTSR, Copy_u8_EXTI_Line);
	break;
	case EXTI_LineTrigger_BOTH:
		SET_BIT(EXTI->RTSR, Copy_u8_EXTI_Line);
		SET_BIT(EXTI->FTSR, Copy_u8_EXTI_Line);
	break;
	}
}


/*
 * EXTI_void_ControlInterruptLine
 * Parameters: u8 , u8 Copy_u8_LineState
 * Return: void
 * Description: Enable or disable the passed interrupt line
 * Options: Example -> Line 0 Corresponds to EXTERNAL INTERRUPT AT PIN0 in Each Port
 */
void EXTI_void_ControlInterruptLine(LINES Copy_u8_EXTI_Line, u8 Copy_u8_State){
	switch(Copy_u8_State){
	case EXTI_LINE_ENABLE:
		SET_BIT(EXTI->IMR, Copy_u8_EXTI_Line);
		break;
	case EXTI_LINE_DISABLE:
		CLR_BIT(EXTI->IMR, Copy_u8_EXTI_Line);
		break;
	}
}

/*
 * Clearing the xPIF for EXTI for a certain line
 */
void EXTI_void_ClearFlag(u8 Copy_u8_EXTI_Line){
		SET_BIT(EXTI->PR, Copy_u8_EXTI_Line);
}
