/*
 * RCC_private.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Potato
 */

// private.h : registers macros and private functions

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

// registers macros
#define RCC_START_ADDRESS 0x40021000
#define RCC_CR         *((volatile u32*) (RCC_START_ADDRESS+0X00))
#define RCC_CFGR       *((volatile u32*) (RCC_START_ADDRESS+0X04))
#define RCC_CIR        *((volatile u32*) (RCC_START_ADDRESS+0X08))
#define RCC_APB2STR    *((volatile u32*) (RCC_START_ADDRESS+0X0C))
#define RCC_APB1STR    *((volatile u32*) (RCC_START_ADDRESS+0X10))
#define RCC_AHBENR     *((volatile u32*) (RCC_START_ADDRESS+0X14))
#define RCC_APB2ENR    *((volatile u32*) (RCC_START_ADDRESS+0X18))
#define RCC_APB1ENR    *((volatile u32*) (RCC_START_ADDRESS+0X1C))
#define RCC_BDCR       *((volatile u32*) (RCC_START_ADDRESS+0X20))
#define RCC_CSR        *((volatile u32*) (RCC_START_ADDRESS+0X24))




#endif /* RCC_PRIVATE_H_ */
