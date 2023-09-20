/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: EXTI															*****/
/************************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_





typedef enum{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,

}EXTI_LINE;
typedef enum{
	EXTI_RISING,
	EXTI_FALLING,
	EXTI_ONCHANGE
}EXTI_EGDE;

typedef struct {
	EXTI_LINE LineID;
	EXTI_EGDE SenseEdge;
	void(*Copy_PtrCallBackFunction)(void);
	
}EXTI_Configurations;

u8 EXTI_u8EnableInterrupt	( EXTI_Configurations *Copy_structExtiConfigurations );
u8 EXTI_u8DisableInterrupt	( EXTI_LINE Copy_enumLineID );
u8 EXTI_u8EnableEvent	( EXTI_Configurations *Copy_structExtiConfigurations );
u8 EXTI_u8DisableEvent	( EXTI_LINE Copy_enumLineID  );
u8 EXTI_u8CreateSWIR	( EXTI_LINE Copy_enumLineID  );
u8 EXTI_u8ESetCallBAck	(EXTI_LINE LineID, void(*Copy_PtrCallBackFunction)(void));


#endif
