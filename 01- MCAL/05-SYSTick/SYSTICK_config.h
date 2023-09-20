/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: SYSTICK														*****/
/************************************************************************************/
#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/************* Available Options **************/
/************* 1- AHB			 **************/
/************* 2- AHB_DEV_8		 **************/

#define SYSTICK_CLOCK_SOURCE	AHB_DEV_8

/************* Available Options 	 **************/
/************* 1- EXCEPTION_ENABLED	 **************/
/************* 2- EXCEPTION_DISABLED **************/

#define SYSTICK_EXCEPTION		EXCEPTION_DISABLED

#endif
