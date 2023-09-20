/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: SYSTICK														*****/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"


static u8 Interval_Type;
static void(*STK_CALLBACK)(void);
void SYSTICK_voidInit(void)
{
#if SYSTICK_CLOCK_SOURCE == AHB
	SET_BIT(STK->CTRL, SYSTICK_CLOCK_SIURCE_BIT);
#elif SYSTICK_CLOCK_SOURCE == AHB_DEV_8
	CLR_BIT(STK->CTRL, SYSTICK_CLOCK_SIURCE_BIT);
#else
#error "Wrong Configurations"
#endif

}
void SYSTICK_u8SetBusyWait(u32 Copy_u32BusyTicks )
{
	STK->VAL  = 0;
	/* Set The Load Register With desired Ticks */
	STK->LOAD = Copy_u32BusyTicks;
	/* Enable the SYSTICK */
	STK->CTRL |= ( 1 << SYSTICK_ENABLE_BIT) ;
	/* Wait the flag  */
	while( GET_BIT(STK->CTRL, COUNTING_FLAG)==0 );
	/*Disable the SYSTICK*/
	STK->CTRL &= ~( 1 << SYSTICK_ENABLE_BIT) ;
	STK->VAL  = 0;
	STK->LOAD = 0;

}

void SYSTICK_voidSetSingleInterval( u32 Copy_u32BusyTicks , void(*Copy_PtrSYSTICK_CallBack)(void))
{
	STK->CTRL &=~(1<<SYSTICK_ENABLE_BIT);
	STK->VAL  = 0;
	Interval_Type = SINGLE_INTERVAL;
	/* Set The Load Register With desired Ticks */
	STK->LOAD = Copy_u32BusyTicks;
	/* Enable the SYSTICK_EXCEPTION */
	STK->CTRL |= ( 1 << SYSTICK_EXCEPTION_BIT);
	/* Setting the Call Back Function */
	STK_CALLBACK = Copy_PtrSYSTICK_CallBack;
	/* Enable the SYSTICK */
	STK->CTRL |= ( 1 << SYSTICK_ENABLE_BIT) ;
}
void SYSTICK_u8SetPeriodicInterval( u32 Copy_u32BusyTicks , void(*Copy_PtrSYSTICK_CallBack)(void) )
{
	Interval_Type = PERIODIC_INTERVAL;
	/* Set The Load Register With desired Ticks */
	STK->LOAD = Copy_u32BusyTicks - 1;
	/* Enable the SYSTICK_EXCEPTION */
	STK->CTRL |= ( 1 << SYSTICK_EXCEPTION_BIT);
	/* Enable the SYSTICK */
	STK->CTRL |= ( 1 << SYSTICK_ENABLE_BIT) ;
	/* Setting the Call Back Function */
	STK_CALLBACK = Copy_PtrSYSTICK_CallBack;
}

void SysTick_Handler(void)
{
	u8 LOC_DummyVariable = 0;
	if ( Interval_Type == SINGLE_INTERVAL )
	{
		/* Disable The Interrupt */
		STK->CTRL &=~( 1 << SYSTICK_EXCEPTION_BIT );
		/* Disable the SYSTICK */
		STK->CTRL &=~( 1 << SYSTICK_ENABLE_BIT );
		STK->LOAD = 0;
		STK->VAL = 0;
	}
	/* Invoking the Call Back Function */
	if ( STK_CALLBACK != NULL )
	{
		STK_CALLBACK();
		/* Clear the Counting Flag  */
		LOC_DummyVariable = GET_BIT(STK->CTRL, COUNTING_FLAG);
	}

}
