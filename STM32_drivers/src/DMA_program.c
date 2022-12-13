#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"

#include "DMA/DMA_interface.h"
#include "DMA/DMA_config.h"
#include "DMA/DMA_private.h"

u8 UART_transferDone = 1;
// FIXME DMA transmit overlaps if two transmissions are called  
/**
 * @brief Receive serial data on UART1 peripheral without involvment of the CPU
 * @note DMA here is programmed not to initiate any interrupt because it is not needed
 * @note Once DMA is called it operates until program ends (circular)
 * @param buffer
 * @param size
 */
void DMA_UART1_receive(u8 *buffer, u32 size)
{
	CLR_BIT(DMA->Channel[DMA_CH5].CCR_REG, 0);			// disabe DMA channel
	CLR_BIT(DMA->Channel[DMA_CH5].CCR_REG, 14);			// disable memory-to-memory mode
	DMA->Channel[DMA_CH5].CCR_REG |= (0b11 << 12);		// channel priority high
	DMA->Channel[DMA_CH5].CCR_REG |= (DMA_8bits << 8);	// peripheral data size 8bit
	DMA->Channel[DMA_CH5].CCR_REG |= (DMA_8bits << 10); // memory data size 8bit
	CLR_BIT(DMA->Channel[DMA_CH5].CCR_REG, 6);			// disable peripheral increment
	SET_BIT(DMA->Channel[DMA_CH5].CCR_REG, 7);			// enable memory increment
	SET_BIT(DMA->Channel[DMA_CH5].CCR_REG, 5);			// enable circular mode
	CLR_BIT(DMA->Channel[DMA_CH5].CCR_REG, 4);			// transfer direction to memory
	DMA->Channel[DMA_CH5].CNDTR_REG = size;				// number of data to transfer 1 byte
	DMA->Channel[DMA_CH5].CPAR_REG = (u32)0x40013804;	// peripheral address
	DMA->Channel[DMA_CH5].CMAR_REG = (u32)buffer;		// memory address
	SET_BIT(DMA->Channel[DMA_CH5].CCR_REG, 0);			// activate channel
}
/**
 * @brief Transmit serial data using DMA processor
 *
 * @param buffer
 * @param size
 */
void DMA_UART1_transmit(u8 *buffer, u32 size)
{
		CLR_BIT(DMA->Channel[DMA_CH4].CCR_REG, 0);			// disabe DMA channel
		CLR_BIT(DMA->Channel[DMA_CH4].CCR_REG, 14);			// disable memory-to-memory mode
		DMA->Channel[DMA_CH4].CCR_REG |= (0b11 << 12);		// channel priority high
		DMA->Channel[DMA_CH4].CCR_REG |= (DMA_8bits << 8);	// peripheral data size 8bit
		DMA->Channel[DMA_CH4].CCR_REG |= (DMA_8bits << 10); // memory data size 8bit
		CLR_BIT(DMA->Channel[DMA_CH4].CCR_REG, 6);			// disable peripheral increment
		SET_BIT(DMA->Channel[DMA_CH4].CCR_REG, 7);			// enable memory increment
		CLR_BIT(DMA->Channel[DMA_CH4].CCR_REG, 5);			// disable circular mode
		SET_BIT(DMA->Channel[DMA_CH4].CCR_REG, 4);			// transfer direction to peripheral
		SET_BIT(DMA->Channel[DMA_CH4].CCR_REG, 1);			// enable transfer complete interrupt
		DMA->Channel[DMA_CH4].CNDTR_REG = size;				// number of data to transfer 1 byte
		DMA->Channel[DMA_CH4].CPAR_REG = (u32)0x40013804;	// peripheral address
		DMA->Channel[DMA_CH4].CMAR_REG = (u32)buffer;		// memory address
		SET_BIT(DMA->Channel[DMA_CH4].CCR_REG, 0);			// activate channel
}
// void DMA1_Channel5_IRQHandler(void)
// {
// }
// void DMA_ActivateChannel(u8 ChannelNumber)
// {
// 	SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 0);
// }
// void DMA_DisableChannel(u8 ChannelNumber)
// {
// 	CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 0);
// }
// void DMA_EnableMemorytoMemoryMode(u8 ChannelNumber)
// {
// 	SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 14);
// }
// void DMA_DisableMemorytoMemoryMode(u8 ChannelNumber)
// {
// 	CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 14);
// }
// // Note, This function needs to be called before enabling the channel
// void DMA_SetDataSize(u8 ChannelNumber, u16 Datasize)
// {
// 	DMA->Channel[ChannelNumber].CNDTR_REG = Datasize;
// }

// void DMA_SetMemorySize(u8 ChannelNumber, u8 MemorySize)
// {
// 	DMA->Channel[ChannelNumber].CCR_REG &= (~(0b111 << 10));
// 	DMA->Channel[ChannelNumber].CCR_REG |= (MemorySize << 10);
// }
// void DMA_SetPeripheralSize(u8 ChannelNumber, u8 MemorySize)
// {
// 	DMA->Channel[ChannelNumber].CCR_REG &= (~(0b111 << 8));
// 	DMA->Channel[ChannelNumber].CCR_REG |= (MemorySize << 8);
// }
// // 1 for memory increment mode
// void DMA_ControlMemoryIncrementMode(u8 ChannelNumber, u8 State)
// {
// 	switch (State)
// 	{
// 	case 0:
// 		CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 7);
// 		break;
// 	case 1:
// 		SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 7);
// 		break;
// 	}
// }

// void DMA_ControlPeripheralIncrementMode(u8 ChannelNumber, u8 State)
// {
// 	switch (State)
// 	{
// 	case 0:
// 		CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 6);
// 		break;
// 	case 1:
// 		SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 6);
// 		break;
// 	}
// }
// // 0 read from peripheral, 1 read from memory
// void DMA_ControlDataTransferDir(u8 ChannelNumber, u8 State)
// {
// 	switch (State)
// 	{
// 	case 0:
// 		CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 4);
// 		break;
// 	case 1:
// 		SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 4);
// 		break;
// 	}
// }

// // Note, This function needs to be called before enabling the channel
// void DMA_SetMemoryAddress(u8 ChannelNumber, u32 *MemoryAddress)
// {
// 	DMA->Channel[ChannelNumber].CMAR_REG = (u32)MemoryAddress;
// }

// void DMA_SetPeripheralAddress(u8 ChannelNumber, u32 *PeripheralAddress)
// {
// 	DMA->Channel[ChannelNumber].CPAR_REG = (u32)PeripheralAddress;
// }
// void DMA_ChannelPriority(u8 ChannelNumber)
// {
// 	// DMA->Channel[ChannelNumber].CCR_REG &= (~(0b11<<12));
// 	DMA->Channel[ChannelNumber].CCR_REG |= (0b11 << 12);
// }

// void DMA_EnableTransferCompleteInterrupt(u8 ChannelNumber)
// {
// 	SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 1);
// }
// u8 DMA_GetInterruptStatus()
// {
// 	u8 return_var;
// 	return_var = GET_BIT(DMA->ISR_REG, 1);
// 	return return_var;
// }
// // Do this function
// void DMA_Channel5_ClearInterruptStatus()
// {
// 	SET_BIT(DMA->IFCR_REG, 16);
// }

// void DMA_Channel3_ClearInterruptStatus()
// {
// 	SET_BIT(DMA->IFCR_REG, 8);
// }
// void DMA_ControlCircularMode(u8 ChannelNumber, u8 state)
// {
// 	switch (state)
// 	{
// 	case 1:
// 		SET_BIT(DMA->Channel[ChannelNumber].CCR_REG, 5);
// 		break;
// 	case 0:
// 		CLR_BIT(DMA->Channel[ChannelNumber].CCR_REG, 5);
// 		break;
// 	}
// }
