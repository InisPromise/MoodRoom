class LED(){ //classes are private by default
	int R_value;
	int G_value; 
	int B_value;
}

class MoodRoom(){ 
	int comfort_level; //comfort level of user
 	LED LED_value; //LED color values (should correspond to comfort_level)
	bool color_mode; //warm (true) by default, false for cool
public: 
MoodRoom(int color_sel); //constructor -- initiates the Mood Room object based on user color selection (warm vs cool color options)
int get_comfort_level(); //returns comfort level 
LED get_LED_value(); //retursn LED value

void calibrate_comfort_level(); //calculates comfort level based on input
void calibrate_LED_level(); //calculates LED level based on comfort level
} 