// libraries
#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"
// interface of lower layer (empty)

// own driver files
#include "USART/USART_interface.h"
#include "USART/USART_config.h"
#include "USART/USART_private.h"

// Interface of same level layer
#include "RCC/RCC_interface.h"
#include "GPIO/GPIO_interface.h"

void USART_Start(u16 port_val, u8 USART_NUM)
{
	RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
	RCC_PeripheralClockEnable(RCC_APB2, RCC_USART1);
	GPIO_SetPinMode(GPIO_PORTA, USART_TxPin, GPIO_OUTPUT_ALT_OD_2MHZ);
	USART_SetBaudRate(port_val, USART_NUM);
	USART_EnableUSART(USART_NUM);
}
void USART_SetBaudRate(u16 port_val, u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		USART1_PER->BRR_REG = port_val;
		break;
	case USART_2:
		USART2_PER->BRR_REG = port_val;
		break;
	case USART_3:
		USART3_PER->BRR_REG = port_val;
		break;
	case USART_4:
		USART4_PER->BRR_REG = port_val;
		break;
	case USART_5:
		USART5_PER->BRR_REG = port_val;
		break;
	}
}

void USART_EnableUSART(u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		// Enable USART
		SET_BIT(USART1_PER->CR1_REG, 13);
		// Enable RX to receive data
		SET_BIT(USART1_PER->CR1_REG, 2);
		// Enable Tx to send data
		SET_BIT(USART1_PER->CR1_REG, 3);
		break;
	case USART_2:
		SET_BIT(USART2_PER->CR1_REG, 13);
		SET_BIT(USART2_PER->CR1_REG, 2);
		SET_BIT(USART2_PER->CR1_REG, 3);
		break;
	case USART_3:
		SET_BIT(USART3_PER->CR1_REG, 13);
		SET_BIT(USART3_PER->CR1_REG, 2);
		SET_BIT(USART3_PER->CR1_REG, 3);
		break;
	case USART_4:
		SET_BIT(USART4_PER->CR1_REG, 13);
		SET_BIT(USART4_PER->CR1_REG, 2);
		SET_BIT(USART4_PER->CR1_REG, 3);
		break;
	case USART_5:
		SET_BIT(USART5_PER->CR1_REG, 13);
		SET_BIT(USART5_PER->CR1_REG, 2);
		SET_BIT(USART5_PER->CR1_REG, 3);
		break;
	}
}

void USART_DisableUSART(u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		// Disable USART
		CLR_BIT(USART1_PER->CR1_REG, 13);
		// Disable RX to receive data
		CLR_BIT(USART1_PER->CR1_REG, 2);
		// Disable Tx to send data
		CLR_BIT(USART1_PER->CR1_REG, 3);
		break;
	case USART_2:
		CLR_BIT(USART2_PER->CR1_REG, 13);
		CLR_BIT(USART2_PER->CR1_REG, 2);
		CLR_BIT(USART2_PER->CR1_REG, 3);
		break;
	case USART_3:
		CLR_BIT(USART3_PER->CR1_REG, 13);
		CLR_BIT(USART3_PER->CR1_REG, 2);
		CLR_BIT(USART3_PER->CR1_REG, 3);
		break;
	case USART_4:
		CLR_BIT(USART4_PER->CR1_REG, 13);
		CLR_BIT(USART4_PER->CR1_REG, 2);
		CLR_BIT(USART4_PER->CR1_REG, 3);
		break;
	case USART_5:
		CLR_BIT(USART5_PER->CR1_REG, 13);
		CLR_BIT(USART5_PER->CR1_REG, 2);
		CLR_BIT(USART5_PER->CR1_REG, 3);
		break;
	}
}

void USART_ReceiveInterruptEnable(u8 USART_NUM)
{
	// Bit 5 RXNEIE: RXNE interrupt enable
	// 0: Interrupt is inhibited
	// 1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
	// Bit 3 ORE: Overrun error
	// Bit 5 RXNE: Read data register not empty
	// 0: Data is not received
	// 1: Received data is ready to be read.
	switch (USART_NUM)
	{
	case USART_1:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	case USART_2:
		SET_BIT(USART2_PER->CR1_REG, 5);
		break;
	case USART_3:
		SET_BIT(USART3_PER->CR1_REG, 5);
		break;
	case USART_4:
		SET_BIT(USART4_PER->CR1_REG, 5);
		break;
	case USART_5:
		SET_BIT(USART5_PER->CR1_REG, 5);
		break;
	}
}

void USART_TransmitInterruptEnable(u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		SET_BIT(USART1_PER->CR1_REG, 7); // Data transfered TXE
		SET_BIT(USART1_PER->CR1_REG, 6); // Transmission complete TC		break;
	case USART_2:
		SET_BIT(USART2_PER->CR1_REG, 7); // Data transfered TXE
		SET_BIT(USART2_PER->CR1_REG, 6); // Transmission complete TC
		break;
	case USART_3:
		SET_BIT(USART3_PER->CR1_REG, 7); // Data transfered TXE
		SET_BIT(USART3_PER->CR1_REG, 6); // Transmission complete TC
		break;
	case USART_4:
		SET_BIT(USART4_PER->CR1_REG, 7); // Data transfered TXE
		SET_BIT(USART4_PER->CR1_REG, 6); // Transmission complete TC
		break;
	case USART_5:
		SET_BIT(USART5_PER->CR1_REG, 7); // Data transfered TXE
		SET_BIT(USART5_PER->CR1_REG, 6); // Transmission complete TC
		break;
	}
}

u8 USART_ReceiveByte(u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		while (GET_BIT(USART1_PER->SR_REG, 5) == 0)
			; // wait until data is available for reading
		return (0xFF & USART1_PER->DR_REG);
		break;
	case USART_2:
		while (GET_BIT(USART2_PER->SR_REG, 5) == 0)
			;
		return (0xFF & USART2_PER->DR_REG);
		break;
	case USART_3:
		while (GET_BIT(USART3_PER->SR_REG, 5) == 0)
			;
		return (0xFF & USART3_PER->DR_REG);
		break;
	case USART_4:
		while (GET_BIT(USART4_PER->SR_REG, 5) == 0)
			;
		return (0xFF & USART4_PER->DR_REG);
		break;
	case USART_5:
		while (GET_BIT(USART5_PER->SR_REG, 5) == 0)
			;
		return (0xFF & USART5_PER->DR_REG);
		break;
	}
	return 0;
}

void USART_SendByte(u8 USART_NUM, u8 value)
{
	switch (USART_NUM)
	{
	case USART_1:
		// Put the Data on DR Register
		// Bit 7 TXE: Transmit data register empty
		// 0: Data is not transferred to the shift register
		// 1: Data is transferred to the shift register
		// So when the data is transfered to the shift register you are ready to send another one.
		USART1_PER->DR_REG = value;
		while (GET_BIT(USART1_PER->SR_REG, 7) == 0)
			;
		break;
	case USART_2:
		USART2_PER->DR_REG = value;
		while (GET_BIT(USART2_PER->SR_REG, 7) == 0)
			;
		break;
	case USART_3:
		USART3_PER->DR_REG = value;
		while (GET_BIT(USART3_PER->SR_REG, 7) == 0)
			;
		break;
	case USART_4:
		USART4_PER->DR_REG = value;
		while (GET_BIT(USART4_PER->SR_REG, 7) == 0)
			;
		break;
	case USART_5:
		USART5_PER->DR_REG = value;
		while (GET_BIT(USART5_PER->SR_REG, 7) == 0)
			;
		break;
	}
}

void USART_SendString(u8 USART_NUM, u8 *String)
{
	u8 i = 0;
	switch (USART_NUM)
	{
	case USART_1:
		// Put the Data on DR Register
		// Bit 7 TXE: Transmit data register empty
		// 0: Data is not transferred to the shift register
		// 1: Data is transferred to the shift register
		// So when the data is transfered to the shift register you are ready to send another one.
		while (String[i] != '\0')
		{
			USART1_PER->DR_REG = String[i];
			i++;
			while (GET_BIT(USART1_PER->SR_REG, 7) == 0)
				;
		}
		break;
	case USART_2:
		while (String[i] != '\0')
		{
			USART2_PER->DR_REG = String[i];
			i++;
			while (GET_BIT(USART2_PER->SR_REG, 7) == 0)
				;
		}
		break;
	case USART_3:
		while (String[i] != '\0')
		{
			USART3_PER->DR_REG = String[i];
			i++;
			while (GET_BIT(USART3_PER->SR_REG, 7) == 0)
				;
		}
		break;
	case USART_4:
		while (String[i] != '\0')
		{
			USART4_PER->DR_REG = String[i];
			i++;
			while (GET_BIT(USART4_PER->SR_REG, 7) == 0)
				;
		}
		break;
	case USART_5:
		while (String[i] != '\0')
		{
			USART5_PER->DR_REG = String[i];
			i++;
			while (GET_BIT(USART5_PER->SR_REG, 7) == 0)
				;
		}
		break;
	}
}

void USART_ClearRXNE(u8 USART_NUM)
{
	switch (USART_NUM)
	{
	case USART_1:
		CLR_BIT(USART1_PER->SR_REG, 5);
		break;
	case USART_2:
		CLR_BIT(USART2_PER->SR_REG, 5);
		break;
	case USART_3:
		CLR_BIT(USART3_PER->SR_REG, 5);
		break;
	case USART_4:
		CLR_BIT(USART4_PER->SR_REG, 5);
		break;
	case USART_5:
		CLR_BIT(USART5_PER->SR_REG, 5);
		break;
	}
}
