/*
 * exercise6.c
 *
 *  Created on: Sep 8, 2024
 *      Author: phan thanh huy
 */

#include "exercise6.h"
#include "main.h"

#define LED_Clock_1_GPIO_Port LED_RED_GPIO_Port
#define LED_Clock_2_GPIO_Port LED_YELLOW_GPIO_Port
#define LED_Clock_3_GPIO_Port LED_GREEN_GPIO_Port
#define LED_Clock_4_GPIO_Port LED_RED_2_GPIO_Port
#define LED_Clock_5_GPIO_Port LED_YELLOW_2_GPIO_Port
#define LED_Clock_6_GPIO_Port LED_GREEN_2_GPIO_Port

#define LED_Clock_1_Pin LED_RED_Pin
#define LED_Clock_2_Pin LED_YELLOW_Pin
#define LED_Clock_3_Pin LED_GREEN_Pin
#define LED_Clock_4_Pin LED_RED_2_Pin
#define LED_Clock_5_Pin LED_YELLOW_2_Pin
#define LED_Clock_6_Pin LED_GREEN_2_Pin

GPIO_TypeDef* LED_GPIO_Ports[12] = {
	LED_Clock_0_GPIO_Port, LED_Clock_1_GPIO_Port, LED_Clock_2_GPIO_Port, LED_Clock_3_GPIO_Port,
	LED_Clock_4_GPIO_Port, LED_Clock_5_GPIO_Port, LED_Clock_6_GPIO_Port, LED_Clock_7_GPIO_Port,
	LED_Clock_8_GPIO_Port, LED_Clock_9_GPIO_Port, LED_Clock_10_GPIO_Port, LED_Clock_11_GPIO_Port
};

uint16_t LED_Pins[12] = {
		LED_Clock_0_Pin, LED_Clock_1_Pin, LED_Clock_2_Pin, LED_Clock_3_Pin,
		LED_Clock_4_Pin, LED_Clock_5_Pin, LED_Clock_6_Pin,LED_Clock_7_Pin,
		LED_Clock_8_Pin, LED_Clock_9_Pin, LED_Clock_10_Pin, LED_Clock_11_Pin
};

void InitExercise6(){
	for(int i = 0; i < 12; i++){
		HAL_GPIO_WritePin(LED_GPIO_Ports[i], LED_Pins[i], GPIO_PIN_SET);
	}
}

void RunExercise6(){
	for(int i = 0; i < 12; i++){
		if(i == 0){
			HAL_GPIO_WritePin(LED_GPIO_Ports[11], LED_Pins[11], GPIO_PIN_SET);
		}else{
		  HAL_GPIO_WritePin(LED_GPIO_Ports[i-1], LED_Pins[i-1], GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin(LED_GPIO_Ports[i], LED_Pins[i], GPIO_PIN_RESET);
		HAL_Delay(1000);
	}
}
