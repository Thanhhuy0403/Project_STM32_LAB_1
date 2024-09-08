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

void InitExercise5(){

}

void RunExercise5(){
	display7SEG((5*(cnt_led_red > 0) + 3*(cnt_led_green > 0) + 2*(cnt_led_yellow > 0) + 1) - (cnt_led_red + cnt_led_yellow + cnt_led_green));
}

