
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


void USART_SetBaudRate(u16 port_val);
void USART_EnableUSART(u8 USART_NUM);
void USART_DisableUSART();
u8 USART1_u8_Recieve();

void USART1_ReceiveInterruptEnable(u8 USART_NUM);
u8 StringMatch(u8* SourceString, u8* StringToFind);

void USART_SendByte(u8 USART_NUM,u8 value);
u8 USART_ReceiveByte(u8 USART_NUM);

void UART1_Transmit_Interrupt_Enabler();
void USART1_Send_Interrupt(u8 value);

void USART_SendString(u8 USART_NUM,u8 *String);

void USART_ClearRXNE();
#endif /* USART_INTERFACE_H_ */
