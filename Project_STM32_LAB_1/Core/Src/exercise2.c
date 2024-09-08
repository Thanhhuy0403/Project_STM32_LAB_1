/*
 * exercise2.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise2.h"
#include "main.h"

int cnt_led_red = 0;
int cnt_led_green = 0;
int cnt_led_yellow = 0;
int state = 1; // state = 1 (red on), state = 2(green on), state = 3 (yellow on)

void InitExercise2(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
}

void RunExercise2(){
	if(state == 1){
		if(cnt_led_red < 5){
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			cnt_led_red++;
		}else{
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			cnt_led_red = 0;
			cnt_led_green = 1;
			state = 2;
		}
	}else if(state == 2){
		if(cnt_led_green < 3){
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			cnt_led_green++;
		}else{
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			cnt_led_green = 0;
			cnt_led_yellow = 1;
			state = 3;
		}
	}else{
		if(cnt_led_yellow < 2){
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			cnt_led_yellow++;
		}else{
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			cnt_led_red = 0;
			cnt_led_red = 1;
			state = 1;
		}
	}
}
