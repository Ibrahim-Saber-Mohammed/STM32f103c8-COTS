/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: SYSTICK														*****/
/************************************************************************************/
#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_CLOCK_SIURCE_BIT 	2
#define SYSTICK_EXCEPTION_BIT		1
#define EXCEPTION_ENABLED			(1 << SYSTICK_EXCEPTION_BIT)
#define EXCEPTION_DISABLED			(0 << SYSTICK_EXCEPTION_BIT)
#define AHB							(1 << SYSTICK_CLOCK_SIURCE_BIT)
#define AHB_DEV_8					(0 << SYSTICK_CLOCK_SIURCE_BIT)
#define COUNTING_FLAG				16
#define SYSTICK_ENABLE_BIT			0

#define SINGLE_INTERVAL				0
#define PERIODIC_INTERVAL			1
#endif
