#ifndef _H_BRIDGE_INTERFACE_H
#define _H_BRIDGE_INTERFACE_H

// Directions
#define STOP 0
#define RIGHT 1
#define LEFT 2

//################# prototypes ########################

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

#endif