#include <TinkerKit.h>
#include <LiquidCrystal.h>


// Time variables 
unsigned long t_previous = 0;
bool isVibrating = false;
int t_delta_lastBeat = 0;
int beats = 0;


// BPM and Time signature variables
int bpm = 80; 
String signatures[] = {"1/4","2/4","3/4","4/4","5/4","6/4","7/4"};
int currentSignature = 0;


// Screen variables
// Initialize the library by associating any needed LCD interface pin
// With the arduino pin number it is connected to
LiquidCrystal lcd(12,11,5,4,3,2);


// Input and outputs
TKPotentiometer potSig(I0);                     
TKPotentiometer potBpm(I1);
TKMosFet buzzer(O1); 


// Reads the potentiometer's value and maps it to the BPM set by the user
void readBpmVal(){

  // Creating a function pointer
  void (*potentiometerVal)();
  potentiometerVal = potBpm.read();
  bpm = map(potentiometerVal, 0, 1023, 50, 250);

}

// Reads the potentiometer's value and maps it to the current signature value 
void readSignatureVal(){

  // Creating a function pointer
  void (*potentiometerVal)();
  potentiometerVal = potSig.read();
  currentSignature = map(potentiometerVal, 0, 1023, 0, 6);
 
}


// Update the LCD
void updateLCD(){
  lcd.setCursor(0,0 );
  lcd.print("Time: ");
  lcd.println(signatures[currentSignature]);
  lcd.setCursor(0,1 );
  lcd.print("BPM: ");
  lcd.println(bpm);
}





// /*******************************************************/
// /*******************************************************/
// /*******************************************************/
// /*******************************************************/
// /*******************************************************/
// /*******************************************************/
// /*******************************************************/


void setup() {

    Serial.begin(9600);
    lcd.begin(16, 2);

}

void loop() {
  
    // Serial.println(beats);
    updateLCD();
    readBpmVal();
    readSignatureVal();
    


  // Serial.println(t_previous);

    // Task: Vibration based on the time signatures and time signature selected by the user
    unsigned long t_difference = millis() - t_previous;
    t_previous = millis();
    t_delta_lastBeat += t_difference;


      // Start the beat
      if(t_delta_lastBeat > 60000/bpm){
        buzzer.on();
        isVibrating = true;
        t_delta_lastBeat -= 60000/bpm;
      }else if(beats > currentSignature ){
          if(t_delta_lastBeat > 160 && isVibrating){
            buzzer.off();
            isVibrating = false;
            beats = 1;
          }
      }else if (t_delta_lastBeat > 80 && isVibrating){
            buzzer.off();
            isVibrating = false;
            beats += 1;
      }   


delay(10);



}





