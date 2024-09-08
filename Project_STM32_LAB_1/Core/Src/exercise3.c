/*
 * exercise3.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise3.h"
#include "main.h"

int cnt_led_red_2 = 0;
int cnt_led_green_2 = 0;
int cnt_led_yellow_2 = 0;
int state_2 = 2; // state_2 = 1 (red 1), state_2 = 2(green 1), state_2 = 3 (yellow 1) of LED_2

void InitExercise3(){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void RunExercise3(){
	if(state_2 == 2){
		if(cnt_led_green_2 < 3){
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			cnt_led_green_2++;
		}else{
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
			cnt_led_green_2 = 0;
			cnt_led_yellow_2 = 1;
			state_2 = 3;
		}
	}else if(state_2 == 3){
		if(cnt_led_yellow_2 < 2){
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
			cnt_led_yellow_2++;
		}else{
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			cnt_led_red_2 = 0;
			cnt_led_red_2 = 1;
			state_2 = 1;
		}
	}else{
		if(cnt_led_red_2 < 5){
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			cnt_led_red_2++;
		}else{
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
			cnt_led_red_2 = 0;
			cnt_led_green_2 = 1;
			state_2 = 2;
		}
	}
}
