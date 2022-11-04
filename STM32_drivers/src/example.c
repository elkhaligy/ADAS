// Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"
// Interfaces of MCAL
#include "GPIO_interface.h"
#include "RCC_interface.h"

int main(void) {
    // System clock initialize to high speed external clock
    RCC_Init();
    // Enable port GPIOA clock on APB2 bus
    RCC_PeripheralClockEnable(RCC_APB2, RCC_GPIOA);
    // Set portA pin0 mode to general purpose output 2MHZ
    GPIO_SetPinMode(GPIO_PORTA, PIN0, GPIO_OUTPUT_GP_PP_2MHZ);
    // Set portA pin0 value to low
    GPIO_SetPinValue(GPIO_PORTA, PIN0, 0);

    while (1)
        ;
    return 0;
}
