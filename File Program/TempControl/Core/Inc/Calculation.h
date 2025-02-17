/*
 * Calculation.h
 *
 *  Created on: Dec 1, 2024
 *      Author: farelmp
 */

#ifndef INC_CALCULATION_H_
#define INC_CALCULATION_H_

#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "tim.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct{
	float voltage;
	float current;
	float temperature;
	float power;
	uint16_t set_point;
	uint16_t set_Time;
	uint16_t buff_set_point;
	uint16_t buff_set_Time;
}Param;
extern Param conv;
extern uint16_t ADC_Val[5];
int extern duty;
extern float error;

void adc_conv(void);
int tim_set(int time_raw);
float PWM_Control(float Set_Point);

extern int cntr, data_cntr;
extern char merge[20];

#endif /* INC_CALCULATION_H_ */
