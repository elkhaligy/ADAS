// interface.h : prototypes for public functions -  - anything user will use
// public macros of registers bits different values
// public macros of buses
// public macros for buses peripherals locations

#ifndef RCC_INTERFACE
#define RCC_INTERFACE

// Buses
#define RCC_AHB 0
#define RCC_APB1 1
#define RCC_APB2 2

// RCC_CFGR -> MCO Values and SW values (Register->Bits->Value definition)
#define RCC_MCO_NO (-2)
#define RCC_SYS_CLK (-1)
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

// RCC_CFGR -> HPRE values (AHB prescaler) (Register->Bits->Value definition)
#define RCC_AHB_PRE_NO 0
#define RCC_AHB_PRE_2 8
#define RCC_AHB_PRE_4 9
#define RCC_AHB_PRE_8 10
#define RCC_AHB_PRE_16 11

typedef enum {
    // AHB peripheral clock enable register
    RCC_DMA1,
    RCC_DMA2,
    RCC_SRAM,
    RCC_RES1,
    RCC_FLITF,
    RCC_RES2,
    RCC_CRCE,
    RCC_RES3,
    RCC_FSMC,
    RCC_RES4,
    RCC_SDIO,

    // APB2 peripheral clock enable register
    RCC_AFIO, // -11
    RCC_Res5,
    RCC_GPIOA,
    RCC_GPIOB,
    RCC_GPIOC,
    RCC_GPIOD,
    RCC_GPIOE,
    RCC_GPIOF,
    RCC_GPIOG,
    RCC_ADC1,
    RCC_ADC2,
    RCC_TIM1,
    RCC_SPI1,
    RCC_TIM8,
    RCC_USART1,
    RCC_ADC3,
    RCC_RES6,
    RCC_RES7,
    RCC_RES8,
    RCC_TIM9,
    RCC_TIM10,
    RCC_TIM11,

    // APB1 peripheral clock enable register
    RCC_TIM2, // - 33
    RCC_TIM3,
    RCC_TIM4,
    RCC_TIM5,
    RCC_TIM6,
    RCC_TIM7,
    RCC_TIM12,
    RCC_TIM13,
    RCC_TIM14,
    RCC_RES9,
    RCC_RES10,
    RCC_WWD,
    RCC_RES11,
    RCC_RES13,
    RCC_SPI2,
    RCC_SPI3,
    RCC_RES14,
    RCC_USART2,
    RCC_USART3,
    RCC_USART4,
    RCC_USART5,
    RCC_I2C1,
    RCC_I2C2,
    RCC_USB,
    RCC_RES15,
    RCC_CAN,
    RCC_RES16,
    RCC_BKP,
    RCC_PWR,
    RCC_DAC,
} Peripherals_t;

/**
 * @brief Initialize system clock
 *
 */
void RCC_systemInit(void);

/**
 * @brief Enable peripheral clock
 * 
 * @param Bus 
 * @param Perphiral 
 */
void RCC_PeripheralClockEnable(u8 Bus, Peripherals_t Perphiral);

/**
 * @brief Disable peripheral clock
 * 
 * @param Bus 
 * @param Perphiral 
 */
void RCC_PeripheralClockDisable(u8 Bus, Peripherals_t Perphiral);

#endif /* RCC_INTERFACE */
