/*
 * exercise5.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise5.h"
#include "main.h"
#include "exercise2.h"
#include "exercise4.h"
#include "exercise3.h"

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

void InitExercise5(){

}

void RunExercise5(){
	display7SEG((5*(cnt_led_red > 0) + 3*(cnt_led_green > 0) + 2*(cnt_led_yellow > 0) + 1) - (cnt_led_red + cnt_led_yellow + cnt_led_green));
	display7Seg2((5*(cnt_led_red_2 > 0) + 3*(cnt_led_green_2 > 0) + 2*(cnt_led_yellow_2 > 0) + 1) - (cnt_led_red_2 + cnt_led_yellow_2 + cnt_led_green_2));
}

