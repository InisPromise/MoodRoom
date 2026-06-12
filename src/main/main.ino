#include "MoodRoom.h"


 //declare the MoodRoom object globally (so that all functions can access it)
MoodRoom mood_room;

void setup() {
  // put your setup code here, to run once:

  //setup up digital display, inputs, outputs, serial monitor, etc
  pinMode(POT_PIN, INPUT); 
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  //setup Serial Monitior
  Serial.begin(115200);
  //welcome user and ask for color mode
  welcome_prompt(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //update  mood room
  mood_room.calibrate_comfort_level();
  mood_room.calibrate_LED_level();

  //output to actuators (update LEDs)
  LED output_LED = mood_room.get_LED_value(); 
  output_to_user(&output_LED); 

  //output values to serial monitor using mood_room.get_comfort_level();
  Serial.print("Comfort Level: "); 
  Serial.println(mood_room.get_comfort_level()); 

  Serial.print("R: "); 
  Serial.println(output_LED.R_value);

  Serial.print("G: "); 
  Serial.println(output_LED.G_value);

  Serial.print("B: "); 
  Serial.println(output_LED.B_value);

  delay(500);
}

void welcome_prompt(){ 
  //prompt the user for their color mode selection using digital display
  mood_room.set_color_mode(true); //just setting as true for now
}

void output_to_user(LED* led_value){
  analogWrite(LED_R_PIN, led_value->R_value);
  analogWrite(LED_G_PIN, led_value->G_value);
  analogWrite(LED_B_PIN, led_value->B_value); 
}
