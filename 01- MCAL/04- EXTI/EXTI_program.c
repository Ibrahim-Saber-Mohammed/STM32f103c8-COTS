/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: EXTI															*****/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void(*Exti_CallBacksArr[16])(void) = {0};

u8 EXTI_u8EnableInterrupt	( EXTI_Configurations *Copy_structExtiConfigurations )
{
	u8 LOC_ErrorState = STATE_OK;
	if(Copy_structExtiConfigurations!=NULL)
	{
		/* Selecting the Edge Trigger */
		switch( Copy_structExtiConfigurations-> SenseEdge)
		{
		case EXTI_ONCHANGE 	: 	EXTI->EXTI_RTSR |= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_FTSR |= ( 1 << Copy_structExtiConfigurations->LineID ); break;

		case EXTI_RISING 	:	 EXTI->EXTI_RTSR |= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_FTSR &= ~( 1 << Copy_structExtiConfigurations->LineID ); break;

		case EXTI_FALLING 	: 	EXTI->EXTI_FTSR |= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_RTSR &= ~( 1 << Copy_structExtiConfigurations->LineID ); break;
		default : LOC_ErrorState = STATE_NOK;
		}

		if( (Copy_structExtiConfigurations->LineID <= EXTI_LINE15 ) && Copy_structExtiConfigurations->Copy_PtrCallBackFunction!= NULL)
		{

			/* Storing the CAll BAck Function address */
			Exti_CallBacksArr[Copy_structExtiConfigurations->LineID] = Copy_structExtiConfigurations->Copy_PtrCallBackFunction;
			/* Enable the Given EXTI_LINEx by Writing "1"  to the Corresponding Bit */
			EXTI->EXTI_IMR |= (1 << Copy_structExtiConfigurations->LineID);
		}
		else
		{
			LOC_ErrorState = STATE_NOK;
		}
	}
	else
	{
		LOC_ErrorState = STATE_NOK;
	}

	return LOC_ErrorState;
}

u8 EXTI_u8DisableInterrupt	(EXTI_LINE Copy_enumLineID )
{
	u8 LOC_ErrorState = STATE_OK;
	if( Copy_enumLineID <= EXTI_LINE15 )
	{
		/* Enable the Given EXTI_LINEx by Writing "1"  to the Corresponding Bit */
		EXTI->EXTI_IMR &= ~(1 << Copy_enumLineID);
	}
	else
	{
		LOC_ErrorState = STATE_NOK;
	}
	return LOC_ErrorState;
}

u8 EXTI_u8EnableEvent	( EXTI_Configurations * Copy_structExtiConfigurations )
{
	u8 LOC_ErrorState = STATE_OK;
	if(Copy_structExtiConfigurations!=NULL)
	{
		/* Selecting the Edge Trigger */
		/* Selecting the Edge Trigger */
		switch( Copy_structExtiConfigurations-> SenseEdge)
		{
		case EXTI_ONCHANGE 	: EXTI->EXTI_RTSR|= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_FTSR |= ( 1 << Copy_structExtiConfigurations->LineID ); break;

		case EXTI_RISING 	: EXTI->EXTI_RTSR|= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_FTSR &= ~( 1 << Copy_structExtiConfigurations->LineID ); break;

		case EXTI_FALLING 	: EXTI->EXTI_FTSR |= ( 1 << Copy_structExtiConfigurations->LineID );
		EXTI->EXTI_RTSR&= ~( 1 << Copy_structExtiConfigurations->LineID ); break;
		default : LOC_ErrorState = STATE_NOK;
		}

		if( Copy_structExtiConfigurations->LineID <= EXTI_LINE15 )
		{
			/* Enable the Given EXTI_LINEx by Writing "1"  to the Corresponding Bit */
			EXTI->EXTI_EMR |= (1 << Copy_structExtiConfigurations->LineID);
		}
		else
		{
			LOC_ErrorState = STATE_NOK;
		}
	}
	else
	{
		LOC_ErrorState = STATE_NOK;
	}

	return LOC_ErrorState;
}
u8 EXTI_u8DisableEvent	(EXTI_LINE Copy_enumLineID)
{
	u8 LOC_ErrorState = STATE_OK;
	if( Copy_enumLineID <= EXTI_LINE15 )
	{
		/* Enable the Given EXTI_LINEx by Writing "1"  to the Corresponding Bit */
		EXTI->EXTI_EMR &= ~(1 << Copy_enumLineID);
	}
	else
	{
		LOC_ErrorState = STATE_NOK;
	}
	return LOC_ErrorState;
}
u8 EXTI_u8ESetCallBAck	(EXTI_LINE LineID, void(*Copy_PtrCallBackFunction)(void))
{
	u8 LOC_ErrorState = STATE_OK;
	if( (LineID <= EXTI_LINE15 ) && Copy_PtrCallBackFunction!= NULL)
	{
		Exti_CallBacksArr[LineID] = Copy_PtrCallBackFunction;
	}
	else
	{
		LOC_ErrorState =STATE_NOK;
	}
	return LOC_ErrorState;
}

u8 EXTI_u8CreateSWIR( EXTI_LINE Copy_enumLineID  )
{
	u8 LOC_ErrorState = STATE_OK;
	if( Copy_enumLineID <= EXTI_LINE15 )
	{
		/* Enable Interrupt Line */
		EXTI->EXTI_IMR |= ( 1 << Copy_enumLineID );
		/* Clearing the Pending Flag */
		EXTI->EXTI_PR  |= ( 1 << Copy_enumLineID );
		/* Generating the SW Interrupt */
		EXTI->EXTI_SWIER |= ( 1 << Copy_enumLineID );
	}
	else
	{
		LOC_ErrorState = STATE_NOK;
	}
	return LOC_ErrorState;
}

void EXTI0_IRQHandler(void)
{
	if ( Exti_CallBacksArr[EXTI_LINE0] != NULL )
	{
		Exti_CallBacksArr[EXTI_LINE0]();
	}
	/* Clear the flag "Pending flag" */
	EXTI->EXTI_PR |= (1 << EXTI_LINE0);
}
void EXTI1_IRQHandler(void)
{
	if ( Exti_CallBacksArr[EXTI_LINE1] != NULL )
	{
		Exti_CallBacksArr[EXTI_LINE1]();
	}
	/* Clear the flag "Pending flag" */
	EXTI->EXTI_PR |= (1 << EXTI_LINE1);
}
void EXTI2_IRQHandler(void)
{
	if ( Exti_CallBacksArr[EXTI_LINE2] != NULL )
	{
		Exti_CallBacksArr[EXTI_LINE2]();
	}
	/* Clear the flag "Pending flag" */
	EXTI->EXTI_PR |= (1 << EXTI_LINE2);
}
void EXTI3_IRQHandler(void)
{
	if ( Exti_CallBacksArr[EXTI_LINE3] != NULL )
	{
		Exti_CallBacksArr[EXTI_LINE3]();
	}
	/* Clear the flag "Pending flag" */
	EXTI->EXTI_PR |= (1 << EXTI_LINE3);
}
void EXTI4_IRQHandler(void)
{
	if ( Exti_CallBacksArr[EXTI_LINE4] != NULL )
	{
		Exti_CallBacksArr[EXTI_LINE4]();
	}
	/* Clear the flag "Pending flag" */
	EXTI->EXTI_PR |= (1 << EXTI_LINE4);
}


