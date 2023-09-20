/************************************************************************************/
/*** Author 	: Ibrahim Saber Mohamed Ahmed 									*****/
/*** Version  	: V01 															*****/
/*** SOC		: LED_MATRIX													*****/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMXD_interface.h"
#include "LEDMXD_config.h"
#include "LEDMXD_private.h"

GPIO_PIN_CONFIGS LEDMXD_ROW0 = {ROW0, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW1 = {ROW1, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW2 = {ROW2, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW3 = {ROW3, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW4 = {ROW4, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW5 = {ROW5, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW6 = {ROW6, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_ROW7 = {ROW7, OUTPUT_PUSH_PULL_2_MHz};

GPIO_PIN_CONFIGS LEDMXD_COL0 = {COL0, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL1 = {COL1, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL2 = {COL2, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL3 = {COL3, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL4 = {COL4, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL5 = {COL5, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL6 = {COL6, OUTPUT_PUSH_PULL_2_MHz};
GPIO_PIN_CONFIGS LEDMXD_COL7 = {COL7, OUTPUT_PUSH_PULL_2_MHz};

void LEDMXD_voidInitPins(void)
{
	/* Configure Pin Direction */
	GPIO_u8SetPinDirection(&LEDMXD_ROW0);
	GPIO_u8SetPinDirection(&LEDMXD_ROW1);
	GPIO_u8SetPinDirection(&LEDMXD_ROW2);
	GPIO_u8SetPinDirection(&LEDMXD_ROW3);
	GPIO_u8SetPinDirection(&LEDMXD_ROW4);
	GPIO_u8SetPinDirection(&LEDMXD_ROW5);
	GPIO_u8SetPinDirection(&LEDMXD_ROW6);
	GPIO_u8SetPinDirection(&LEDMXD_ROW7);

	GPIO_u8SetPinDirection(&LEDMXD_COL0);
	GPIO_u8SetPinDirection(&LEDMXD_COL1);
	GPIO_u8SetPinDirection(&LEDMXD_COL2);
	GPIO_u8SetPinDirection(&LEDMXD_COL3);
	GPIO_u8SetPinDirection(&LEDMXD_COL4);
	GPIO_u8SetPinDirection(&LEDMXD_COL5);
	GPIO_u8SetPinDirection(&LEDMXD_COL6);
	GPIO_u8SetPinDirection(&LEDMXD_COL7);

}

void LEDMXD_voidDisplay(u8 * Copy_ptrChar)
{
	/* Disable All Columns */
	LEDMXD_DisableAllColumns();
}

static void LEDMXD_DisableAllColumns(void)
{
	GPIO_u8SetPinValue(&LEDMXD_COL0, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL1, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL2, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL3, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL4, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL5, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL6, LOW);
	GPIO_u8SetPinValue(&LEDMXD_COL7, LOW);
}
static void LEDMXD_SetRowsValue(u8 Copy_u8Data)
{
	u8 LOC_Iterrator = 0;
	for(LOC_Iterrator = 0; LOC_Iterrator < 8 ; LOC_Iterrator++)
	{
		
	}		
}

