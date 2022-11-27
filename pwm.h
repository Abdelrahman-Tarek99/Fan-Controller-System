 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the pwm driver
 *
 * Author: Abdelrahman Tarek
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_FREQUENCY 500;
#define COMPARE_VALUE_PORT_ID PORTB_ID
#define COMPARE_VALUE_PIN_ID PIN3_ID
typedef enum
{
	NOCLOCK,NOPRESCALER,CPU_8,CPU_64,CPU_256,CPU_1024,CPU_EXTERNALCLOCK_FALLINGEDGE,CPU_EXTERNALCLOCK_RISINGEDGE
}Pwm_Prescaler;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Timer0_PWM_Start(unsigned char set_duty_cycle);

#endif /* PWM_H_ */
