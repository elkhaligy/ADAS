/*
 * USART_private.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Sirito
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


typedef struct{
	volatile u32 SR_REG;
	volatile u32 DR_REG;
	volatile u32 BRR_REG;
	volatile u32 CR1_REG;
	volatile u32 CR2_REG;
	volatile u32 CR3_REG;
	volatile u32 GTPR_REG;
}USART_Peripheral_struct;


#define USART1_PER ((volatile USART_Peripheral_struct*) 0x40013800)
#define USART2_PER ((volatile USART_Peripheral_struct*) 0x40004400)
#define USART3_PER ((volatile USART_Peripheral_struct*) 0x40004800)
#define USART4_PER ((volatile USART_Peripheral_struct*) 0x40004C00)
#define USART5_PER ((volatile USART_Peripheral_struct*) 0x40005000)

#endif /* USART_PRIVATE_H_ */
