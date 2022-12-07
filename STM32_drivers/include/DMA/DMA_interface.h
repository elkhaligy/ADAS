/*
 * DMA_interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Sirito
 */

#ifndef DMA_INTERFACE
#define DMA_INTERFACE

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_


//Memory size macros
#define DMA_8bits 0b00
#define DMA_16bits 0b01
#define DMA_32bits 0b10


void DMA_ActivateChannel(u8 ChannelNumber);
void DMA_DisableChannel(u8 ChannelNumber);
void DMA_EnableMemorytoMemoryMode(u8 ChannelNumber);
void DMA_DisableMemorytoMemoryMode(u8 ChannelNumber);
// Note, This function needs to be called before enabling the channel
void DMA_SetDataSize(u8 ChannelNumber ,u16 Datasize);

void DMA_SetMemorySize(u8 ChannelNumber,u8 MemorySize);
void DMA_SetPeripheralSize(u8 ChannelNumber,u8 MemorySize);
// 1 for memory increment mode
void DMA_ControlMemoryIncrementMode(u8 ChannelNumber, u8 State);

void DMA_ControlPeripheralIncrementMode(u8 ChannelNumber, u8 State);
//0 read from peripheral, 1 read from memory
void DMA_ControlDataTransferDir(u8 ChannelNumber, u8 State);

// Note, This function needs to be called before enabling the channel
void DMA_SetMemoryAddress(u8 ChannelNumber,u32 *MemoryAddress);

void DMA_SetPeripheralAddress(u8 ChannelNumber,u32 *PeripheralAddress);
void DMA_ChannelPriority(u8 ChannelNumber);

void DMA_EnableTransferCompleteInterrupt(u8 ChannelNumber);
u8 DMA_GetInterruptStatus();
void DMA_ClearInterruptStatus();

void DMA_ControlCircularMode(u8 ChannelNumber,u8 state);
void DMA_Channel3_ClearInterruptStatus(void);
void DMA_Channel5_ClearInterruptStatus(void);

#endif /* DMA_INTERFACE_H_ */


#endif /* DMA_INTERFACE */
