/*
 * system.c
 *
 *  Created on: Dec 3, 2024
 *      Author: farelmp
 */

#include "system.h"

int control_state = 1, counter;
extern int rcv_buffer[4], bufferMode[2];

void systemFunction(void) {
//	State *addr = &state;
	Param *calc = &conv;
	if (control_state == 1) {
			PWM_Control((float)calc->set_point);		//activating control
	}else{
		duty=100;
	}
}

void systemVal(void) {
	State *addr = &state;
	Param *calc = &conv;
	if (addr->mode_set == 'B') {
		if(rcv_buffer[1] != 0){
		bufferMode[1]=rcv_buffer[1];
		}
		if (rcv_buffer[0] == 5) {
			HAL_GPIO_WritePin(LED_MODE_GPIO_Port, LED_MODE_Pin, 1);
			addr->mode_set = 'A';
		}
		if (rcv_buffer[3] != 0) {
			calc->set_Time = rcv_buffer[3];
		}
		if (rcv_buffer[2] != 0) {
			calc->set_point = rcv_buffer[2];
		}
	} else if (addr->mode_set == 'A') {
		calc->set_Time = calc->buff_set_Time;
		calc->set_point = calc->buff_set_point;
	}
}

void systemTimer(void) {
//	State *addr = &state;
	Param *calc = &conv;
	if ((bufferMode[1] == 2 && control_state == 0) ||bufferMode[1] == 2) {
		counter = 0;
		HAL_GPIO_WritePin(LED_STOPRUN_GPIO_Port, LED_STOPRUN_Pin, 0);
	}
	if (bufferMode[1] == 3 && control_state == 1) {
		HAL_GPIO_WritePin(LED_STOPRUN_GPIO_Port, LED_STOPRUN_Pin, 1);
		counter++;
		if (counter == (calc->set_Time * 600)) {
			HAL_GPIO_WritePin(LED_STOPRUN_GPIO_Port, LED_STOPRUN_Pin, 0);
			control_state = 0;
			counter = 0;
		}
	}
//	 else if (addr->mode_set == 'B' && addr->StartStop == 'D') {
//		counter++;
//		if (counter == (calc->PC_set_Time * 600)) {
//			control_state = 0;
//			counter = 0;
//		}
//	}
}
