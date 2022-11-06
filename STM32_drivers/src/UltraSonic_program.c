#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"RCC_interface.h"
#include"SYSTICK_interface.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include"UltraSonic_config.h"
#include"UltraSonic_interface.h"

u32 Ticks=0;

void UltrSonic_INIT(void){

    TICK_Init(SYSTICK_AHB_8);
    RCC_Init();
    RCC_PeripheralClockEnable(RCC_APB2, UltraSonic_PORT_RCC);

    GPIO_SetPinMode(UltraSonic_PORT_GPIO,PIN_Trigger, GPIO_OUTPUT_GP_PP_10MHZ);
    GPIO_SetPinMode(UltraSonic_PORT_GPIO,PIN_ECHO, GPIO_INPUT_PULLING);

    NVIC_voidEnableInterrupt(6);
}

void UltraSonic_Trigger(void){

    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_HIGH);
    TICK_Delay(1);  // how to use interrupt
    GPIO_SetPinValue(UltraSonic_PORT_GPIO, PIN_Trigger, GPIO_LOW);
}

void UltraSonic_StartECHO(void){

    EXTI_void_SelectLineTriggerType(PIN_ECHO, EXTI_LineTrigger_RISING);

}

u32 UltrSonic_GetDistance(void){
    
    UltraSonic_StartECHO();
    u32 Time=Ticks/1000000;
    u32 Distance=(Time/2)*34300;
    return Distance;
}

void EXTI0_IRQHandler(void)
{
    static u8 f=0;
    if(f==0){
        TICK_StartCounting();
        EXTI_void_SelectLineTriggerType(PIN_ECHO, EXTI_LineTrigger_FALLING);
        f=1;
    }
    else if(f==1){
        Ticks=TICK_ElapsedTicks();
        TICK_Stop();
        f=0;
    }
}