#ifndef MOTORS_INTERFACE
#define MOTORS_INTERFACE

// Directions
#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define RIGHT 3
#define LEFT 4


/**
 * @brief set the control pins as output and initialize PWM
 */
void MOTORS_init();

/**
 * @brief set control pins value according to the input Direction
 *
 * @param Direction
 */
void MOTORS_setDirection(u8 Direction);

/**
 * @brief set motors speed
 *
 * @param speed percentage (0 --> 100)
 */
void MOTORS_setSpeed(u8 speedPercentage);
#endif /* MOTORS_INTERFACE */
