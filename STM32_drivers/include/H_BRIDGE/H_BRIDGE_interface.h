#ifndef _H_BRIDGE_INTERFACE_H
#define _H_BRIDGE_INTERFACE_H

// Directions
#define Stop 0
#define Forward 1
#define Reverse 2

/**
 * @brief set the control pins as output
 */
void H_BRIDGE_Initialize();

/**
 * @brief set control pins value according to the input Direction
 *
 * @param Direction
 */
void H_BRIDGE_SetDirection(u8 Direction);

void H_BRIDGE_SetSpeed(u8 speedPercentage);
#endif