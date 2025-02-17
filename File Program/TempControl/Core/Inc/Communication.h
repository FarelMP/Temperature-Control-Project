/*
 * Communication.h
 *
 *  Created on: Dec 3, 2024
 *      Author: farelmp
 */

#ifndef INC_COMMUNICATION_H_
#define INC_COMMUNICATION_H_

#include "Calculation.h"
#include "system.h"

typedef struct{
	char mode_set;
	char StartStop;
}State;
extern State state;
extern int led_status;
extern char rcv_data[15];
extern int base1, base2;

void DataSend(void);
void parseData(void);

#endif /* INC_COMMUNICATION_H_ */
