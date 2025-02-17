/*
 * Communication.c
 *
 *  Created on: Dec 3, 2024
 *      Author: farelmp
 */
#include "Communication.h"

Param *rslt = &conv;
State *addr = &state;
int bufferMode[2], rcv_buffer[4];
char data[100];
extern int counter;
float D_;

int cntr = 0, data_cntr = 0, base1 = 0, base2 = 0;
char merge[20] = "";

void DataSend(void) {
	if (addr->mode_set == 'A') {
		Param *calc = &conv;
		calc->set_point = calc->buff_set_point;
		calc->set_Time = calc->buff_set_Time;
		bufferMode[0] = 0;
		if (addr->StartStop == 'C') {
			bufferMode[1] = 2;
		} else if (addr->StartStop == 'D') {
			bufferMode[1] = 3;
		}
	} else if (addr->mode_set == 'B') {
		bufferMode[0] = 1;
	}
	D_ = duty * 100.0 / 20000.0;

	sprintf(data, "%d,%d,%.3f,%.3f,%.3f,%.3f,%.2f,%d,%d,%.2f\r\n",
			bufferMode[0], bufferMode[1], rslt->voltage, rslt->current,
			rslt->power, D_, rslt->temperature, rslt->set_point, rslt->set_Time,
			counter / 60.0);
	HAL_UART_Transmit(&huart1, (uint8_t*) &data, strlen(data), HAL_MAX_DELAY);
	memset(data, 0, sizeof(data));
}

int cp = 0;
void parseData(void) {
	if (rcv_data[base1] == '@') {
		if (rcv_data[data_cntr] == '\n') {
			systemVal();
//			data_cntr = 0;
			memset(rcv_data, 0, sizeof(rcv_data));
		}
		if (rcv_data[data_cntr] != ',') {
			strcat(merge, &rcv_data[data_cntr]);
			data_cntr++;
		} else if (rcv_data[data_cntr] == ',') {
			rcv_buffer[cntr] = atoi(merge);
			memset(merge, 0, sizeof(merge));
			cntr++;
			if (cntr >= sizeof(rcv_buffer) / sizeof(rcv_buffer[0])) {
				cntr = 0;
			}
			data_cntr++;
		}
		if (data_cntr > 14)
			data_cntr = 0;

	} else {
		base1++;
		if (base1 > 14)
			base1 = 0;
		data_cntr = base1 + 1;
		cntr = 0;
	}
}
