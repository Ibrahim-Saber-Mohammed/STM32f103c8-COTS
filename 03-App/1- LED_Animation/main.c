/*
 * main.c
 *
 *  Created on: May 30, 2021
 *      Author: ibrahim
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"


GPIO_PIN_CONFIGS LEDS[8] = {
		{PORTA, PIN0, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN1, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN2, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN3, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN4, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN5, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN6, OUTPUT_PUSH_PULL_2_MHz},
		{PORTA, PIN7, OUTPUT_PUSH_PULL_2_MHz}
};



void Ping_Pong(void);
void Flashing(void);
void In_Out(void);

void CALLBACK_Text(void)
{
	GPIO_u8ReadPinValue(&LEDS[0], LOW);
}

int main(void)
{
	/* Enable System CLOCK */
	RCC_voidInitSystemClock();
	/* Enable GPIOA CLOCK  */
	RCC_voidEnable_PeripheralCLOCK(APB2_BUS, GPIOA_CLK);
	/* Initialize the SYSTICK */
	SYSTICK_voidInit();
	/* MAin Code */
	u8 LOC_LoopIterator = 0;
	for (LOC_LoopIterator = 0; LOC_LoopIterator < 8; LOC_LoopIterator++)
	{
		GPIO_u8SetPinDirection(&LEDS[LOC_LoopIterator]);
	}

	GPIO_u8SetPinValue(&LEDS[0], HIGH);
	SYSTICK_u8SetSingleInterval(1000000, CALLBACK_Text);
	while(1)
	{

		/*for (LOC_LoopIterator = 0; LOC_LoopIterator<4; LOC_LoopIterator++)
		{
			Ping_Pong();
		}
		for(LOC_LoopIterator = 0; LOC_LoopIterator<4; LOC_LoopIterator++)
		{
			In_Out();
		}
		for (LOC_LoopIterator = 0; LOC_LoopIterator<=7; LOC_LoopIterator++)
		{
			Flashing();
		}*/
	}

	return 0;
}

void Ping_Pong(void)
{
	s8 LOC_LoopIterator = 0;
	for(LOC_LoopIterator = 0; LOC_LoopIterator < 8; LOC_LoopIterator++)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], HIGH);
		SYSTICK_u8SetBusyWait(200000);
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], LOW);
	}
	for(LOC_LoopIterator = 6; LOC_LoopIterator >=0; LOC_LoopIterator--)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], HIGH);
		SYSTICK_u8SetBusyWait(200000);
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], LOW);
	}

}
void Flashing(void)
{
	u8 LOC_LoopIterator = 0;
	for(LOC_LoopIterator = 0; LOC_LoopIterator < 8; LOC_LoopIterator++)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], HIGH);
	}
	SYSTICK_u8SetBusyWait(500000);
	for(LOC_LoopIterator = 0; LOC_LoopIterator < 8; LOC_LoopIterator++)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], LOW);
	}
	SYSTICK_u8SetBusyWait(500000);

}

void In_Out(void)
{
	s8 LOC_LoopIterator = 0;
	for(LOC_LoopIterator = 0; LOC_LoopIterator < 4; LOC_LoopIterator++)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], HIGH);
		GPIO_u8SetPinValue(&LEDS[7 - LOC_LoopIterator], HIGH);
		SYSTICK_u8SetBusyWait(200000);
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], LOW);
		GPIO_u8SetPinValue(&LEDS[7 - LOC_LoopIterator], LOW);
	}

	for(LOC_LoopIterator = 2; LOC_LoopIterator >=0; LOC_LoopIterator--)
	{
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], HIGH);
		GPIO_u8SetPinValue(&LEDS[7 - LOC_LoopIterator], HIGH);
		SYSTICK_u8SetBusyWait(200000);
		GPIO_u8SetPinValue(&LEDS[LOC_LoopIterator], LOW);
		GPIO_u8SetPinValue(&LEDS[7 - LOC_LoopIterator], LOW);
	}
}
