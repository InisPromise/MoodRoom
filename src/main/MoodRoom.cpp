#include "MoodRoom.h"

MoodRoom::MoodRoom(){
	//initialize values so as to not have them be junk
	color_mode = true; 
	comfort_level = 0; 
	LED_value.R_value = 0; 
	LED_value.G_value = 0;
	LED_value.B_value = 0; 
} 

int MoodRoom::get_comfort_level(){ 
	return comfort_level;
} 

LED MoodRoom::get_LED_value(){ 
	return LED_value;
}

void MoodRoom::calibrate_comfort_level(){
	//read the input (potentiometer for first-stage proof of concept, simulated brain waves for second, actual brain waves for third)
	// based on the input, calculate the comfort level of user
	comfort_level = analogRead(POT_PIN);
} 

void MoodRoom::calibrate_LED_level(){
//Based on comfort_level + color_mode, calibrate the LED RGB levels
int mapped_comfort = map(comfort_level, 0, comfort_max, 0, 255); 

	LED_value.G_value = G_VALUE;

	if (color_mode){
		LED_value.R_value = mapped_comfort;
		LED_value.B_value = 0; 
	}
	else{
		LED_value.R_value = 0;
		LED_value.B_value = mapped_comfort; 
	}
}

void MoodRoom::set_color_mode(bool color_mode){ 
	this->color_mode = color_mode;
}

