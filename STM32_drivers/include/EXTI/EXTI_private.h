/*
 * EXTI_private.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Omar Gamal
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS		0x40010400

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;

#define EXTI		((volatile EXTI_t*)EXTI_BASE_ADDRESS)

#endif /* EXTI_PRIVATE_H_ */
