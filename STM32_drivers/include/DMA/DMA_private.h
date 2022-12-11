#ifndef DMA_PRIVATE
#define DMA_PRIVATE

typedef struct{
	volatile u32 CCR_REG;
	volatile u32 CNDTR_REG;
	volatile u32 CPAR_REG;
	volatile u32 CMAR_REG;
	volatile u32 RES_REG;
}DMA_Channel_t;

typedef struct{
	volatile u32 ISR_REG;
	volatile u32 IFCR_REG;
	volatile DMA_Channel_t Channel[7]; // TODO I think this needs to be 8
}DMA_REG_t;


	#define DMA ((volatile DMA_REG_t*) 0x40020000)


#endif /* DMA_PRIVATE */
