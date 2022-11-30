
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define BAUD_RATE_9600 0x341
#define BAUD_RATE_115200 0x45
#define USART_TxPin PIN9
#define USART_1 0
#define USART_2 1
#define USART_3 2
#define USART_4 3
#define USART_5 4

//Init/Disable Functions
void USART_SetBaudRate(u16 Port_Val, u8 USART_NUM);
void USART_EnableUSART(u8 USART_NUM);
void USART_DisableUSART(u8 USART_NUM);

//Interrupt Enable Functions
void USART_TransmitInterruptEnable(u8 USART_NUM);
void USART_ReceiveInterruptEnable(u8 USART_NUM);

//Send/Recieve Functions

void USART_SendByte(u8 USART_NUM,u8 value);
u8 USART_ReceiveByte(u8 USART_NUM);
void USART_SendString(u8 USART_NUM,u8 *String);

//Other Functions
void USART_ClearRXNE(u8 USART_NUM);
void USART_Start(u16 port_val, u8 USART_NUM);

#endif /* USART_INTERFACE_H_ */
