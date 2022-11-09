/*
 * EXTI_interface.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Omar Gamal
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

// Macros

#define EXTI_LINE_ENABLE	1
#define EXTI_LINE_DISABLE	0

#define EXTI_LineTrigger_RISING		0
#define EXTI_LineTrigger_FALLING	1
#define EXTI_LineTrigger_BOTH		2

typedef enum{
	LINE0,
	LINE1,
	LINE2,
	LINE3,
	LINE4,
	LINE5,
	LINE6,
	LINE7,
	LINE8,
	LINE9,
	LINE10,
	LINE11,
	LINE12,
	LINE13,
	LINE14,
	LINE15
}LINES;

/*
 * Configures the trigger signal EXTI for a certain line
 */
void  EXTI_void_SelectLineTriggerType(u8 Copy_u8_EXTI_Line, u8 Copy_u8_TriggerType);

/*
 * EXTI_void_ControlInterruptLine
 * Parameters: u8 , u8 Copy_u8_LineState
 * Return: void
 * Description: Enable or disable the passed interrupt line
 * Options: Example -> Line 0 Corresponds to EXTERNAL INTERRUPT AT PIN0 in Each Port
 */
void EXTI_void_ControlInterruptLine(LINES Copy_u8_EXTI_Line, u8 Copy_u8_State);


/*
 * Clearing the xPIF for EXTI for a certain line
 */
void EXTI_void_ClearFlag(u8 Copy_u8_EXTI_Line);

#endif /* EXTI_INTERFACE_H_ */
