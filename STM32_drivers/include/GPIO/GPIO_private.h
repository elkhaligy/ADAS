/*
 * GPIO_private.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Potato
 */

#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

// NAME_TYPE

// GPIO register map construction
typedef struct{
	volatile u32 CRL_REG;
	volatile u32 CRH_REG;
	volatile u32 IDR_REG;
	volatile u32 ODR_REG;
	volatile u32 BSRR_REG;
	volatile u32 BRR_REG;
	volatile u32 LCKR_REG;
}GPIO_Port_t;


// AFIO REGISTER




// REGISTERS MACROS
	// GPIO ports define (each port has 7 registers)
//PORTA base address: 0x40010800
#define GPIO_PORTA_PER 		((volatile GPIO_Port_t*) 0x40010800) //*((volatile GPIO_Port_t*) 0x40010800) dot operator
//PORTB base address: 0x40010C00
#define GPIO_PORTB_PER 		((volatile GPIO_Port_t*) 0x40010C00)
//PORTC base address: 0x40011000
#define GPIO_PORTC_PER 		((volatile GPIO_Port_t*) 0x40011000)



#endif /* GPIO_PRIVATE */
