#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#define DMA_8bits 0b00
#define DMA_16bits 0b01
#define DMA_32bits 0b10

#define DMA_CH1 0
#define DMA_CH2 1
#define DMA_CH3 2
#define DMA_CH4 3
#define DMA_CH5 4
#define DMA_CH6 5
#define DMA_CH7 6
#define DMA_CH8 7

void DMA_UART1_receive(u8 *buffer, u32 size);
void DMA_UART1_transmit(u8 *buffer, u32 size);

// void DMA_ActivateChannel(u8 ChannelNumber);
// void DMA_DisableChannel(u8 ChannelNumber);
// void DMA_EnableMemorytoMemoryMode(u8 ChannelNumber);
// void DMA_DisableMemorytoMemoryMode(u8 ChannelNumber);
// void DMA_SetDataSize(u8 ChannelNumber ,u16 Datasize);
// void DMA_SetMemorySize(u8 ChannelNumber,u8 MemorySize);
// void DMA_SetPeripheralSize(u8 ChannelNumber,u8 MemorySize);
// void DMA_ControlMemoryIncrementMode(u8 ChannelNumber u8 State);
// void DMA_ControlPeripheralIncrementMode(u8 ChannelNumber, u8 State);
// void DMA_ControlDataTransferDir(u8 ChannelNumber, u8 State);
// void DMA_SetMemoryAddress(u8 ChannelNumber,u32 *MemoryAddress);
// void DMA_SetPeripheralAddress(u8 ChannelNumber,u32 *PeripheralAddress);
// void DMA_ChannelPriority(u8 ChannelNumber);
// void DMA_EnableTransferCompleteInterrupt(u8 ChannelNumber);
// u8 DMA_GetInterruptStatus();
// void DMA_ClearInterruptStatus();
// void UART1_DMA_receiveInit(void);
// void DMA_ControlCircularMode(u8 ChannelNumber,u8 state);
// void DMA_Channel3_ClearInterruptStatus(void);
// void DMA_Channel5_ClearInterruptStatus(void);

#endif /* DMA_INTERFACE_H_ */