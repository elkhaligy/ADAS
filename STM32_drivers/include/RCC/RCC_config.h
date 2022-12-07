
#ifndef RCC_CONFIG
#define RCC_CONFIG
// configurable register values (single value) (for multivalues check interface)

// RCC_CR register values (Register->Bits->Value set)
#define RCC_HSI_ON		    1
#define RCC_TRIMMING_VAL	16
#define RCC_HSE_ON		    0 			// Enable status of HSE	1: ON, 0: OFF
#define RCC_HSE_BYPASS		0
#define RCC_CSS_ON			0
#define RCC_PLL_ON		    0

// RCC_CFGR register values
#define RCC_SYSTEM_CLOCK_SWITCH		RCC_HSI
#define RCC_AHB_PRESCALER			RCC_AHB_PRE_NO
#define RCC_APB1_PRESCALER			1
#define RCC_APB2_PRESCALER			1
#define RCC_ADC_PRESCALER			1
#define RCC_PLL_SRC					RCC_HSE
#define RCC_PLL_HSE_DIV				1
#define RCC_PLL_MUL					6
#define RCC_MCO_SRC					RCC_HSE



#endif /* RCC_CONFIG */
