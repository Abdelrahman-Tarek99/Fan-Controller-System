/*
 -------------------------------------------------------------------------------------------------------------
 Name: prjct.c
 Author:Abdelrahman Tarek
 Description: Fan Controller system
 Date: 7/10/2022
 -------------------------------------------------------------------------------------------------------------
 */
#include "adc.h"
#include "motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
int main(void) {
	uint8 temp;
	/*intializing Motor*/
	DcMotor_Init();
	/* create intilization for the strucure of the ADC*/
	ADC_ConfigType ADC_ConfigType = { INTERNAL_VOLT, PRE_8 };
	ADC_init(&ADC_ConfigType);
	LCD_init(); /* initialize LCD driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Fan is");
	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayStringRowColumn(1, 0, "Temp =");
	while (1) {
		temp = LM35_getTemperature();
		if (temp < 30) {
			DcMotor_Rotate(STOPPED, 0);
			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "OFF");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if (temp < 60) {
			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "ON ");
			DcMotor_Rotate(CLOCKWISE, 25);
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if ( temp < 90) {
			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "ON ");
			DcMotor_Rotate(CLOCKWISE, 50);
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		} else if ( temp <120) {
			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "ON ");
			DcMotor_Rotate(CLOCKWISE, 75);
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if(temp>120){

			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "ON ");
			DcMotor_Rotate(ANTICLOCKWISE, 100);
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);

		}
		/*same as if it's bigger than 120 */
		else{
			/* Display the Fan State every time at same position */
			LCD_displayStringRowColumn(0, 7, "ON ");
			DcMotor_Rotate(ANTICLOCKWISE, 100);
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);

		}
	}
}

