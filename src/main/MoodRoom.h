#include <Arduino.h>

#define POT_PIN  15
#define LED_R_PIN  26
#define LED_G_PIN  14
#define LED_B_PIN  12

#define comfort_max  4095
/* This comfort_max macro ensures the LED value maps onto correct maximum comfort value 
This is important because the comfort level maximum might change as development continues */

#define G_VALUE  180
//chooses a defined g value for RGB so that it remains constant. 
//the only variable color value is R (for warm mode) or B (for cool mode)

struct LED{ //structs are public by default
	int R_value;
	int G_value; 
	int B_value;
};

class MoodRoom{ 
	int comfort_level; 
 	LED LED_value; 
	bool color_mode; //warm (true) by default, false for cool

public: 
	MoodRoom(); //constructor 
	int get_comfort_level(); 
	LED get_LED_value(); 

	void calibrate_comfort_level(); //calculates comfort level based on input
	void calibrate_LED_level(); //calculates LED level based on comfort level
	void set_color_mode(bool color_mode); 
};