#include "MoodRoom.h"

MoodRoom::MoodRoom(bool color_sel = true){
	color_mode = color_sel; 
} 

int MoodRoom::get_comfort_level(){ 
	return this.comfort_level;
} 

int MoodRoom::get_LED_level(){ 
	return this.LED_level();
}

void MoodRoom:calibrate_comfort_level(){
//read the input (potentiometer for first-stage proof of concept, simulated brain waves for second, actual brain waves for third)
// based on the input, calculate the comfort level of user
this.comfort_level = calculated_level;
} 

void MoodRoom:calibrate_LED_level(){
//Based on comfort_level + color_mode, calibrate the LED RGB levels
}

