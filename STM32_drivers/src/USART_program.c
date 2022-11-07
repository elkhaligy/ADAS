// libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
// interface of lower layer (empty)

// own driver files
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void USART_SetBaudRate(u16 port_val) {
	USART1_PER->BRR_REG = port_val;
}

void USART_EnableUSART(u8 USART_NUM) {
	switch (USART_NUM) {
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
void USART_DisableUSART() {
	// Disable USART
	CLR_BIT(USART1_PER->CR1_REG, 13);
	// Disable RX to receive data
	CLR_BIT(USART1_PER->CR1_REG, 2);
	// Disable Tx to send data
	CLR_BIT(USART1_PER->CR1_REG, 3);
}

u8 USART1_u8_Recieve() {

	while ( GET_BIT(USART1_PER->SR_REG,5) == 0)
		;   //wait until data is available for reading

	return (0xFF & USART1_PER->DR_REG);                       //return read data

}

void USART1_ReceiveInterruptEnable(u8 USART_NUM) {
	// Bit 5 RXNEIE: RXNE interrupt enable
	// 0: Interrupt is inhibited
	// 1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
	// Bit 3 ORE: Overrun error
	// Bit 5 RXNE: Read data register not empty
	// 0: Data is not received
	// 1: Received data is ready to be read.
	switch (USART_NUM) {
	case USART_1:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	case USART_2:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	case USART_3:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	case USART_4:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	case USART_5:
		SET_BIT(USART1_PER->CR1_REG, 5);
		break;
	}
}
u8 USART_ReceiveByte(u8 USART_NUM) {
	switch (USART_NUM) {
	case USART_1:
		return (0xFF & USART1_PER->DR_REG);
		break;
	case USART_2:
		return (0xFF & USART2_PER->DR_REG);
		break;
	case USART_3:
		return (0xFF & USART3_PER->DR_REG);
		break;
	case USART_4:
		return (0xFF & USART4_PER->DR_REG);
		break;
	case USART_5:
		return (0xFF & USART5_PER->DR_REG);
		break;
	}
	return 0;
}

void UART1_Transmit_Interrupt_Enabler() {
	SET_BIT(USART1_PER->CR1_REG, 7); // Data transfered TXE
	SET_BIT(USART1_PER->CR1_REG, 6); // Transmission complete TC
}
void USART1_Send_Interrupt(u8 value) {
	USART1_PER->DR_REG = value;
}
void USART_SendByte(u8 USART_NUM, u8 value) {
	switch (USART_NUM) {
	case USART_1:
		// Put the Data on DR Register
		USART1_PER->DR_REG = value;
		// Bit 7 TXE: Transmit data register empty
		// 0: Data is not transferred to the shift register
		// 1: Data is transferred to the shift register
		// So when the data is transfered to the shift register you are ready to send another one.
		while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
		}
		;
		break;
	case USART_2:
		USART1_PER->DR_REG = value;
		while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
		}
		;
		break;
	case USART_3:
		USART1_PER->DR_REG = value;
		while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
		}
		;
		break;
	case USART_4:
		USART1_PER->DR_REG = value;
		while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
		}
		;
		break;
	case USART_5:
		USART1_PER->DR_REG = value;
		while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
		}
		;
		break;
	}

}

void USART_SendString(u8 USART_NUM, u8 *String) {
	u8 i = 0;
	switch (USART_NUM) {
	case USART_1:
		while (String[i] != '\0') {
			// Put the Data on DR Register
			USART1_PER->DR_REG = String[i];
			i++;
			// Bit 7 TXE: Transmit data register empty
			// 0: Data is not transferred to the shift register
			// 1: Data is transferred to the shift register
			// So when the data is transfered to the shift register you are ready to send another one.
			while (GET_BIT(USART1_PER->SR_REG,7) == 0) {
			};
		}
		break;
	case USART_2:

		break;
	case USART_3:

		break;
	case USART_4:

		break;
	case USART_5:

		break;
	}

}
void USART_ClearRXNE(){
	CLR_BIT(USART1_PER->SR_REG,5);
}
