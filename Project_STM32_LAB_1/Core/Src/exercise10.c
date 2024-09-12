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

void RunExercise10(){
	if(cnt_second == 60){
		cnt_second = 0;
		clearNumberOnClock(11);
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
	if(cnt_second%5 == 0){
		clearNumberOnClock(cnt_second/5 - 1);
	}
	setNumberOnClock(cnt_second/5);

	// handle minute
	if(cnt_minute%5 == 0 && (cnt_minute/5-1) != cnt_hour){
		clearNumberOnClock(cnt_minute/5-1);
	}
	setNumberOnClock(cnt_minute/5);

	// handle hour
	setNumberOnClock(cnt_hour);
}


