#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_HIGH 1
#define GPIO_LOW 0

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} PINS;

// PIN MODE MACROS
// INPUT MODE
#define GPIO_INPUT_ANALOG 0b0000   // ANALOG INPUT
#define GPIO_INPUT_FLOATING 0b0100 // FLOATING INPUT
#define GPIO_INPUT_PULLING 0b1000  // PULLING INPUT
// OUTPUT MODE
#define GPIO_OUTPUT_GP_PP_10MHZ 0b0001 // OUTPUT 10MHZ General Purpose Push-Pull
#define GPIO_OUTPUT_GP_PP_2MHZ 0b0010  // OUTPUT 02MHZ General Purpose Push-Pull
#define GPIO_OUTPUT_GP_PP_50MHZ 0b0011 // OUTPUT 50MHZ General Purpose Push-Pull

#define GPIO_OUTPUT_GP_OD_10MHZ 0b0101 // OUTPUT 10MHZ General Purpose Open-Drain
#define GPIO_OUTPUT_GP_OD_2MHZ 0b0110  // OUTPUT 02MHZ General Purpose Open-Drain
#define GPIO_OUTPUT_GP_OD_50MHZ 0b0111 // OUTPUT 50MHZ General Purpose Open-Drain

#define GPIO_OUTPUT_ALT_PP_10MHZ 0b1001 // OUTPUT 10MHZ Alternating Function Push-Pull
#define GPIO_OUTPUT_ALT_PP_2MHZ 0b1010  // OUTPUT 02MHZ Alternating Function Push-Pull
#define GPIO_OUTPUT_ALT_PP_50MHZ 0b1011 // OUTPUT 50MHZ Alternating Function Push-Pull

#define GPIO_OUTPUT_ALT_OD_10MHZ 0b1101 // OUTPUT 10MHZ Alternating Function Open-Drain
#define GPIO_OUTPUT_ALT_OD_2MHZ 0b1110  // OUTPUT 02MHZ Alternating Function Open-Drain
#define GPIO_OUTPUT_ALT_OD_50MHZ 0b1111 // OUTPUT 50MHZ Alternating Function Open-Drain

/**
 * @brief Set pin mode of operation on a specific port
 * @param Port
 * @param Pin
 * @param Mode
 */
void GPIO_SetPinMode(u8 Port, PINS Pin, u8 Mode);

/**
 * @brief Retrieve input of a pin on a specific port
 *
 * @param Port
 * @param Pin
 * @return u8
 */
u8 GPIO_GetPinValue(u8 Port, u8 Pin);

/**
 * @brief Write a mask to a whole port
 *
 * @param Port
 * @param Mask
 * @param Value
 */
void GPIO_PortMaskWrite(u8 Port, u16 Mask, u16 Value);

/**
 * @brief  Set pin value to high or low
 *
 * @param Port
 * @param Pin
 * @param Value
 */
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

#endif /* GPIO_INTERFACE */
