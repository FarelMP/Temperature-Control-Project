/*
 * Calculation.c
 *
 *  Created on: Dec 1, 2024
 *      Author: farelmp
 */

#include "Calculation.h"

Param conv;
float buffer1[100], buffer2[100], sum1 = 0, sum2 = 0;
float moving_avg1 = 0, moving_avg2 = 0,error,volt_buff, current_buff;
uint16_t indx1 = 0, indx2;
int D, timer_config;

float moving_average_volt(float result) {

	sum1 -= buffer1[indx1];
	buffer1[indx1] = result;
	sum1 += result;
	moving_avg1 = (sum1 / 100.0);
	indx1 = (indx1 + 1) % 100;
	return moving_avg1;
}

float moving_average_current(float result) {
	sum2 -= buffer2[indx2];
	buffer2[indx2] = result;
	sum2 += result;
	moving_avg2 = (sum2 / 100.0);
	indx2 = (indx2 + 1) % 100;
	return moving_avg2;
}

void adc_conv(void) {
	Param *calc = &conv;
	if(calc->current>0){
	volt_buff = 709-moving_average_volt(ADC_Val[0]);
	}else{
	volt_buff =0;
	}
	calc->voltage = 3*volt_buff*21/4095.0; 					//channel 6, voltage

	current_buff = moving_average_current(ADC_Val[1]);
	calc->current = current_buff * 3/ 4095.0; 				//channel 7, current


	calc->temperature = ADC_Val[2] * 205 *2/ 4095; 			//channel 8, temperature

	calc->buff_set_point = (ADC_Val[3] * 45 / 4029) + 45; 	//channel 12, potentio set point
	calc->buff_set_Time = ADC_Val[4] * 240 / 4029; 			//channel 15, potentio timer

	calc->power = calc->current*calc->voltage;
}

//Control PWM
float PWM_Control(float Set_Point) {
	Param *calc = &conv;
//float tolerance = 0.07 * Set_Point;

	error = (float) ((Set_Point - calc->temperature) * 1.0 / Set_Point);
	HAL_GPIO_WritePin(LED_SETPOINT_GPIO_Port, LED_SETPOINT_Pin, 0);
	if (error < 0.95 && error > 0.05) {
		duty = error * 20000;
	} else if (error < 0.05) {
		HAL_GPIO_WritePin(LED_SETPOINT_GPIO_Port, LED_SETPOINT_Pin, 1);
		duty = 100;
	} else if (error > 0.95) {
		duty = 19000;
	}

	return duty;
}

