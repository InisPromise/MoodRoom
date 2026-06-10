#include "MoodRoom.h"

void setup() {
  // put your setup code here, to run once:

  //setup up digital display, inputs, outputs, serial monitor, etc

  //welcome user and ask for color mode
  bool color_mode = welcome_prompt(); 
  
  //declare the MoodRoom object
  MoodRoom mood_room(color_mode);

}

void loop() {
  // put your main code here, to run repeatedly:
  //update  mood room
  mood_room.calibrate_comfort_level();
  mood_room.calibrate_LED_level();

  //output to actuators (update LEDs)

  //output values to serial monitor using mood_room.get_comfort_level();

}

bool welcome_prompt(){ 
  //prompt the user for their color mode selection using digital display
  bool color_mode = TRUE;
  return color_mode;
}
