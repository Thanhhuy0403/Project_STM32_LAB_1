/*
 * exercise10.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise4.h"
#include "exercise6.h"
#include "main.h"

int cnt_second = -1;
int cnt_minute = 0;
int cnt_hour = 0;

void InitExercise10(){
	clearAllClock();
}

void display7Seg2(int num){
	if(num >= 10 && num < 0) return;
	HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, numLed[num][0]);
	HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, numLed[num][1]);
	HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, numLed[num][2]);
	HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, numLed[num][3]);
	HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, numLed[num][4]);
	HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, numLed[num][5]);
	HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, numLed[num][6]);
}

void RunExercise10(){
	if(cnt_second == 60){
		cnt_second = 0;
		cnt_minute++;
	}else{
		cnt_second++;
	}

	if(cnt_minute == 60){
		cnt_minute = 0;
		clearNumberOnClock(11);
		cnt_hour++;
	}

	if(cnt_hour == 12){
		cnt_hour = 0;
		clearNumberOnClock(11);
	}

	// handle clock second
	if(cnt_second%12 == 0){
		clearNumberOnClock(11);
	}else{
		clearAllClock((cnt_second-1)%12);
	}
	setNumberOnClock(cnt_second%12);

	// handle minute
	if(cnt_minute%5 == 0){
		clearNumberOnClock(cnt_minute/5-1);
	}
	setNumberOnClock(cnt_minute/5);

	// handle hour
	setNumberOnClock(cnt_hour);

	display7SEG(cnt_minute%5);
	display7Seg2(cnt_second/12);
}


