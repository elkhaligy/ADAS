#ifndef UltraSonic_INTERFACE_H_
#define UltraSonic_INTERFACE_H_





/////////////////  PROTOTYPES   //////////////////////

void UltrSonic_INIT(void);

void UltraSonic_Trigger(void);

void UltraSonic_StartECHO(void);

u32 UltrSonic_GetDistance(void);

#endif /* UltrSonic_INTERFACE_H_ */