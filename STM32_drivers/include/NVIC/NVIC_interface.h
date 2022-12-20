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

/* NVIC Peripherals Macros */

#define NVIC_WWDG 0            // Window watchdog interrupt
#define NVIC_PVD 1             // PVD through EXTI Line detection interrupt
#define NVIC_TAMPER 2          // Tamper interrupt
#define NVIC_RTC 3             // RTC global interrupt
#define NVIC_FLASH 4           // Flash global interrupt
#define NVIC_RCC 5             // RCC global interrupt
#define NVIC_EXTI0 6           // EXTI Line0 interrupt
#define NVIC_EXTI1 7           // EXTI Line1 interrupt
#define NVIC_EXTI2 8           // EXTI Line2 interrupt
#define NVIC_EXTI3 9           // EXTI Line3 interrupt
#define NVIC_EXTI4 10          // EXTI Line4 interrupt
#define NVIC_DMA1_Channel1 11  // DMA1 Channel1 global interrupt
#define NVIC_DMA1_Channel2 12  // DMA1 Channel2 global interrupt
#define NVIC_DMA1_Channel3 13  // DMA1 Channel3 global
#define NVIC_DMA1_Channel4 14  // DMA1 Channel4 global interrupt
#define NVIC_DMA1_Channel5 15  // DMA1 Channel5 global interrupt
#define NVIC_DMA1_Channel6 16  // DMA1 Channel6 global interrupt
#define NVIC_DMA1_Channel7 17  // DMA1 Channel7 global interrupt
#define NVIC_ADC1_2 18         // ADC1 and ADC2 global interrupt
#define NVIC_USB_HP_CAN_TX 19  // USB High Priority or CAN TX interrupts
#define NVIC_USB_LP_CAN_RX0 20 // USB Low Priority or CAN RX0 interrupts
#define NVIC_CAN_RX1 21        // CAN RX1 interrupt
#define NVIC_CAN_SCE 22        // CAN SCE interrupt
#define NVIC_EXTI9_5 23        // EXTI Line[9:5] interrupts
#define NVIC_TIM1_BRK 24       // TIM1 Break interrupt
#define NVIC_TIM1_UP 25        // TIM1 Update interrupt
#define NVIC_TIM1_TRG_COM 26   // TIM1 Trigger and Commutation interrupts
#define NVIC_TIM1_CC 27        // TIM1 Capture Compare interrupt
#define NVIC_TIM2 28           // TIM2 global interrupt
#define NVIC_TIM3 29           // TIM3 global interrupt
#define NVIC_TIM4 30           // TIM4 global interrupt
#define NVIC_I2C1_EV 31        // I2C1 event interrupt
#define NVIC_I2C1_ER 32        // I2C1 error interrupt
#define NVIC_I2C2_EV 33        // I2C2 event interrupt
#define NVIC_I2C2_ER 34        // I2C2 error interrupt
#define NVIC_SPI1 35           // SPI1 global interrupt
#define NVIC_SPI2 36           // SPI2 global interrupt
#define NVIC_USART1 37         // USART1 global interrupt
#define NVIC_USART2 38         // USART2 global interrupt
#define NVIC_USART3 39         // USART3 global interrupt
#define NVIC_EXTI15_10 40      // EXTI Line[15:10] interrupts
#define NVIC_RTCAlarm 41       // RTC alarm through EXTI line interrupt
#define NVIC_USBWakeup 42      // USB wakeup from suspend through EXTI line interrupt
#define NVIC_TIM8_BRK 43       // TIM8 Break interrupt
#define NVIC_TIM8_UP 44        // TIM8 Update interrupt
#define NVIC_TIM8_TRG_COM 45   // TIM8 Trigger and Commutation interrupts
#define NVIC_TIM8_CC 46        // TIM8 Capture Compare interrupt
#define NVIC_ADC3 47           // ADC3 global interrupt
#define NVIC_FSMC 48           // FSMC global interrupt
#define NVIC_SDIO 49           // SDIO global interrupt
#define NVIC_TIM5 50           // TIM5 global interrupt
#define NVIC_SPI3 51           // SPI3 global interrupt
#define NVIC_UART4 52          // UART4 global interrupt
#define NVIC_UART5 53          // UART5 global interrupt
#define NVIC_TIM6 54           // TIM6 global interrupt
#define NVIC_TIM7 55           // TIM7 global interrupt

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
