/*
 * BIT_MATH.h
 *
 *  Created on: Aug 3, 2022
 *      Author: Potato
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR, BIT)   (VAR|=(0x01<<BIT)) //Trying Commenting
#define CLR_BIT(VAR, BIT)   (VAR&=~(0x01<<BIT))
#define GET_BIT(VAR, BIT)   ((VAR>>BIT)&0x01)
#define TOG_BIT(VAR, BIT)   (VAR ^=(1<<BIT))






#endif /* BIT_MATH_H_ */
