#ifndef MOTORS_CONFIG
#define MOTORS_CONFIG

// motors port
#define MOTORS_PORT GPIO_PORTB   // to set pins mode
#define MOTORS_PORT_CLOCK RCC_GPIOB   // to enable port clock

// motors pins     ex: motor 1 control pin 1 is conected to pin0 (MOTORS_PIN_M1IN1)
#define MOTORS_PIN_M1IN1 PIN0
#define MOTORS_PIN_M1IN2 PIN1
#define MOTORS_PIN_M2IN1 PIN2
#define MOTORS_PIN_M2IN2 PIN3
#define MOTORS_PIN_M3IN1 PIN4
#define MOTORS_PIN_M3IN2 PIN5
#define MOTORS_PIN_M4IN1 PIN6
#define MOTORS_PIN_M4IN2 PIN7

// enable pin to control speed by generating PWM 
#define MOTORS_PIN_EN PIN0

#endif /* MOTORS_CONFIG */
