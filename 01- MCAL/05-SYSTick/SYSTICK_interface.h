/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: SYSTICK														*****/
/************************************************************************************/
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void SYSTICK_voidInit(void);
void SYSTICK_u8SetBusyWait			(u32 Copy_u32BusyTicks );
void SYSTICK_voidSetSingleInterval	( u32 Copy_u32BusyTicks , void(*Copy_PtrSYSTICK_CallBack)(void));
void SYSTICK_u8SetPeriodicInterval	( u32 Copy_u32BusyTicks , void(*Copy_PtrSYSTICK_CallBack)(void));



#endif
