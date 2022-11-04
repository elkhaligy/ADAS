#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_SetPinMode(u8 Port, PINS Pin, u8 Mode) {
    switch (Port) {
    case GPIO_PORTA:
        if (Pin <= 7) {
            GPIO_PORTA_PER->CRL_REG &= (~(0b1111 << (4 * Pin)));
            GPIO_PORTA_PER->CRL_REG |= (Mode << (4 * Pin));
        } else if (Pin <= 16) {
            GPIO_PORTA_PER->CRH_REG &= (~(0b1111 << (4 * (Pin - 8))));
            GPIO_PORTA_PER->CRH_REG |= (Mode << (4 * (Pin - 8)));
        }
        break;
    case GPIO_PORTB:
        if (Pin <= 7) {
            GPIO_PORTB_PER->CRL_REG &= (~(0b1111 << (4 * Pin)));
            GPIO_PORTB_PER->CRL_REG |= (Mode << (4 * Pin));
        } else if (Pin <= 16) {
            GPIO_PORTB_PER->CRH_REG &= (~(0b1111 << (4 * (Pin - 8))));
            GPIO_PORTB_PER->CRH_REG |= (Mode << (4 * (Pin - 8)));
        }
        break;
    case GPIO_PORTC:
        if (Pin <= 7) {
            GPIO_PORTC_PER->CRL_REG &= (~(0b1111 << (4 * Pin)));
            GPIO_PORTC_PER->CRL_REG |= (Mode << (4 * Pin));
        } else if (Pin <= 16) {
            GPIO_PORTC_PER->CRH_REG &= (~(0b1111 << (4 * (Pin - 8))));
            GPIO_PORTC_PER->CRH_REG |= (Mode << (4 * (Pin - 8)));
        }
        break;
    }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin) {
    u8 ReturnValue = 0;
    switch (Port) {
    case GPIO_PORTA:
        ReturnValue = GET_BIT(GPIO_PORTA_PER->IDR_REG, Pin);
        break;
    case GPIO_PORTB:
        ReturnValue = GET_BIT(GPIO_PORTB_PER->IDR_REG, Pin);
        break;
    case GPIO_PORTC:
        return GET_BIT(GPIO_PORTC_PER->IDR_REG, Pin);
        break;
    }
    return ReturnValue;
}

void GPIO_voidPortMaskWrite(u8 Port, u16 Mask, u16 Value) {

    switch (Port) {
    case GPIO_PORTA:
        GPIO_PORTA_PER->BSRR_REG = (Mask << 16) | (Mask & Value);
        break;
    case GPIO_PORTB:
        GPIO_PORTB_PER->BSRR_REG = (Mask << 16) | (Mask & Value);
        break;
    case GPIO_PORTC:
        GPIO_PORTC_PER->BSRR_REG = (Mask << 16) | (Mask & Value);
        break;
    }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value) {
    switch (Port) {
    case GPIO_PORTA:
        if (Value) {
            GPIO_PORTA_PER->BSRR_REG = (Value << Pin);
        } else {
            GPIO_PORTA_PER->BSRR_REG = (1 << (Pin + 16));
        }
        break;
    case GPIO_PORTB:
        if (Value) {
            GPIO_PORTB_PER->BSRR_REG = (Value << Pin);
        } else {
            GPIO_PORTB_PER->BSRR_REG = (1 << (Pin + 16));
        }
        break;
    case GPIO_PORTC:
        if (Value) {
            GPIO_PORTC_PER->BSRR_REG = (Value << Pin);
        } else {
            GPIO_PORTC_PER->BSRR_REG = (1 << (Pin + 16));
        }
        break;
    }
}
