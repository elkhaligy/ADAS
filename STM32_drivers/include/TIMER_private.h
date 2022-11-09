#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

typedef struct{
	volatile u32 CR1_REG;
	volatile u32 CR2_REG;
	volatile u32 SMCR_REG;
	volatile u32 DIER_REG;
	volatile u32 SR_REG;
	volatile u32 EGR_REG;
	volatile u32 CCMR1_REG;
    volatile u32 CCMR2_REG;
    volatile u32 CCER_REG;
    volatile u32 CNT_REG;
    volatile u32 PSC_REG;
    volatile u32 ARR_REG;
    volatile u32 Reserved1;
    volatile u32 CCR1_REG;
    volatile u32 CCR2_REG;
    volatile u32 CCR3_REG;
    volatile u32 CCR4_REG;
    volatile u32 Reserved2;
    volatile u32 DCR_REG;
    volatile u32 DMAR_REG;
}TIMER_Port_t;

#define TIM2_PER ((volatile TIMER_Port_t *)0x40000000)
#define TIM3_PER ((volatile TIMER_Port_t *)0x40000400)
#define TIM4_PER ((volatile TIMER_Port_t *)0x40000800)
#define TIM5_PER ((volatile TIMER_Port_t *)0x40000C00)

#endif /* TIMER_PRIVATE_H_ */