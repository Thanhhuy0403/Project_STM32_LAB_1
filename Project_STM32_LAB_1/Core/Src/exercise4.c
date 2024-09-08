/*
 * exercise4.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise4.h"
#include "main.h"

int cnt_led_7Seg = 0;
int numLed[10][7] = {{0,0,0,0,0,0,1},
					 {1,0,0,1,1,1,1},
					 {0,0,1,0,0,1,0},
					 {0,0,0,0,1,1,0},
					 {1,0,0,1,1,0,0},
					 {0,1,0,0,1,0,0},
					 {0,1,0,0,0,0,0},
					 {0,0,0,1,1,1,1},
					 {0,0,0,0,0,0,0},
					 {0,0,0,0,1,0,0}
					};

void InitExercise4(){
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
}

void display7SEG(int num){
	if(num >= 10 && num < 0) return;
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, numLed[num][0]);
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, numLed[num][1]);
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, numLed[num][2]);
	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, numLed[num][3]);
	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, numLed[num][4]);
	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, numLed[num][5]);
	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, numLed[num][6]);
}

void RunExercise4(){
	if(cnt_led_7Seg == 10){
		cnt_led_7Seg = 0;
	}
	display7SEG(cnt_led_7Seg);
	cnt_led_7Seg++;
}
