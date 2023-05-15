#include <TinkerKit.h>

// Set the BPM over here
int bpm = 50; 


// TKButton btn(I0);    // creating the object 'led' that belongs to the 'TKLed' class
                    // and giving the value to the desired output pin

TKMosFet buzzer(O0);  // creating the object 'buzzer' that belongs to the 'TKRlay' class
                      // and giving the value to the desired output pin


// Short vibration
void shortVibration(){
  buzzer.on();
  delay(80);
  buzzer.off();
}

// Long vibration
void longVibration(){
   buzzer.on();
   delay(160);
   buzzer.off();
}


// 1/4 at any tempo || Takes tempo as the parameters
void oneByFour(){
  longVibration();
  delay(60000/bpm);
}


// 2/4 at any tempo || Takes tempo as the parameters
void twoByFour(){
  longVibration();
  delay(60000/bpm);
  shortVibration();
  delay(60000/bpm);
}


// 3/4 at any tempo || Takes tempo as the parameters
void threeByFour(){
  longVibration();
  for(int i = 1; i<4 ; i++){
    shortVibration();
    delay(60000/bpm);
  }
}


// 4/4 at any tempo || Takes tempo as the parameters
void fourByFour(){
  longVibration();
  for(int i = 1; i<5 ; i++){
    shortVibration();
    delay(60000/bpm);
  }
}

// 5/4 at any tempo || Takes tempo as the parameters
void fiveByFour(){
  longVibration();
  for(int i = 1; i<6 ; i++){
    shortVibration();
    delay(60000/bpm);
  }
}
// 7/4 at any tempo || Takes tempo as the parameters
void sevenByFour(){
  longVibration();
  for(int i = 1; i<6 ; i++){
    shortVibration();
    delay(60000/bpm);
  }
}

void setup() {
 Serial.begin(9600);
}

void loop() {
  // oneByFour();
  // twoByFour();
  // threeByFour();
  // fourByFour();
  // fiveByFour();
  // sevenByFour();
}

