#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"
#include"GPIO/GPIO_interface.h"
#include"RCC/RCC_interface.h"
#include"SYSTICK/SYSTICK_interface.h"
#include"NVIC/NVIC_interface.h"
#include"EXTI/EXTI_interface.h"
#include"ULTRASONIC/UltraSonic_config.h"
#include"ULTRASONIC/UltraSonic_interface.h"

//u32 Ticks=0;

void UltrSonic_INIT(void){
    TICK_Init(SYSTICK_AHB_8);
    //RCC_Init();
    RCC_PeripheralClockEnable(RCC_APB2, UltraSonic_PORT_RCC);

    GPIO_SetPinMode(UltraSonic_PORT_GPIO,PIN_Trigger, GPIO_OUTPUT_GP_PP_10MHZ);


    //GPIO_SetPinMode(UltraSonic_PORT_GPIO,PIN_ECHO, GPIO_INPUT_PULLING);
   // GPIO_SetPinMode(GPIO_PORTA, 0, GPIO_INPUT_PULLING);

   // EXTI_void_ControlInterruptLine(0, EXTI_LINE_ENABLE);

   // NVIC_voidEnableInterrupt(6);
}

void UltraSonic_Trigger(void){
    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_HIGH);
    //TICK_Delay(10);  // how to use interrupt
    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_LOW);
}

void UltraSonic_StartECHO(void){
    EXTI_void_ControlInterruptLine(0, EXTI_LINE_ENABLE);         // enable external interrupt line 0 (EXTI0) (A0)
    EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_RISING); // select trigger type (rising edge)
    NVIC_voidEnableInterrupt(6);                                 // enable interrupt 6 (EXTI0)
}

// u32 UltrSonic_GetDistance(void){
    
//     //UltraSonic_StartECHO();
//     u32 Time=Ticks/1000000;
//     u32 Distance=(Time/2)*34300;
//     return Distance;
// }

// void EXTI0_IRQHandler(void)
// {
//     static u8 f=0;
//     if(f==0){
//         TICK_StartCounting();
//         EXTI_void_SelectLineTriggerType(0, EXTI_LineTrigger_FALLING);
//         f=1;
//     }
//     else if(f==1){
//         Ticks=TICK_ElapsedTicks();
//         TICK_Stop();
//         f=0;
//     }
// }