/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: LED_MATRIX													*****/
/************************************************************************************/
#ifndef LEDMXD_CONFIG_H_
#define LEDMXD_CONFIG_H_

/* Options : 
				* ( PORTA - PORTB - PORTC ), ( PIN0.....PIN16 ) 
				* Note With PORTB PINS ( PIN2, PIN3, PIN4 ) Not used
*/

#define ROW0		PORTA, PIN0
#define ROW1		PORTA, PIN1
#define ROW2		PORTA, PIN2
#define ROW3		PORTA, PIN3
#define ROW4		PORTA, PIN4
#define ROW5		PORTA, PIN5
#define ROW6		PORTA, PIN6
#define ROW7		PORTA, PIN7

#define COL0		PORTB, PIN0
#define COL1		PORTB, PIN1
#define COL2		PORTB, PIN5
#define COL3		PORTB, PIN6
#define COL4		PORTB, PIN7
#define COL5		PORTB, PIN8
#define COL6		PORTB, PIN9
#define COL7		PORTB, PIN10

#endif