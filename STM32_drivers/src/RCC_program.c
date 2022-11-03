/*
 * RCC_program.c
 *
 *  Created on: Aug 3, 2022
 *      Author: Potato
 */

// program.c : implementation of the actual functions (code)
// include 1.libraries - 2.interface of lower layers - 3.own driver files



// libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"


// interface of lower layers (empty) (already lowest)

// own driver files
#include <RCC_config.h>
#include <RCC_interface.h>
#include <RCC_private.h>

void RCC_void_Initialize(void)
{
	// RCC_CR -> HSION
	RCC_CR = 0;
	RCC_CR |= (RCC_HSI_ON<<0);

	if(RCC_TRIMMING_VAL<32)
		RCC_CR |= (RCC_TRIMMING_VAL<<3);
	RCC_CR |= (RCC_HSE_ON<<16);
	RCC_CR |= (RCC_HSE_BYPASS<<18);
	RCC_CR |= (RCC_CSS_ON<<19);
	RCC_CR |= (RCC_PLL_ON<<24);

	RCC_CFGR = 0;
	if(RCC_SYSTEM_CLOCK_SWITCH < 4)
		RCC_CFGR|=(RCC_SYSTEM_CLOCK_SWITCH << 0);
	RCC_CFGR |= (RCC_AHB_PRESCALER <<4);
	RCC_CFGR |= (RCC_APB2_PRESCALER <<11);
	RCC_CFGR |= (RCC_APB1_PRESCALER <<8);
	RCC_CFGR |= (RCC_ADC_PRESCALER <<14);
	RCC_CFGR |= (RCC_PLL_SRC <<16);
	RCC_CFGR |= (RCC_PLL_HSE_DIV <<17);
	if(RCC_PLL_MUL> 1&& RCC_PLL_MUL<17)
		RCC_CFGR |= ((RCC_PLL_MUL-2) <<18);
	if(RCC_MCO_SRC > -3 && RCC_MCO_SRC < 3)
		RCC_CFGR |= ((RCC_MCO_SRC+5) <<24);
}

void RCC_void_PeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName)
{
	switch(Copy_u8BusName){
	case RCC_AHB:	SET_BIT(RCC_AHBENR, Copy_u8PerphiralName);				break;
	case RCC_APB2:	SET_BIT(RCC_APB2ENR, (Copy_u8PerphiralName - 11));		break;
	case RCC_APB1:	SET_BIT(RCC_APB1ENR, (Copy_u8PerphiralName -33));		break;
	}
}

void RCC_void_PeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName)
{
	switch(Copy_u8BusName){
	case RCC_AHB:	CLR_BIT(RCC_AHBENR, Copy_u8PerphiralName);				break;
	case RCC_APB2:	CLR_BIT(RCC_APB2ENR, (Copy_u8PerphiralName - 11));		break;
	case RCC_APB1:	CLR_BIT(RCC_APB1ENR, (Copy_u8PerphiralName -33));		break;
	}
}
