#include <TinkerKit.h>
#include <LiquidCrystal.h>


// Set the BPM over here
int bpm = 80; 
String signatures[] = {"1/4","2/4","3/4","4/4","5/4","7/4"};
int currentSignature = 0;


// Screen variables
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(12,11,5,4,3,2);


// Input and outputs
TKPotentiometer potSig(I0);                     
TKPotentiometer potBpm(I1);
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
  for(int i = 1; i<8 ; i++){
    shortVibration();
    delay(60000/bpm);
  }
}

// The potentiometer allows values between 0 & 1023
// The bpm ranges between 20 & 250
// Therefore the bpm values need to be mapped to the potentiometer's values
// The function below returns the value of the BPM based on potentiometer's reading
// Read potentiometer's values
void potBpmVal(){

  // Creating a function pointer
  void (*potentiometerVal)();
  potentiometerVal = potBpm.read();
  // Prints the value of the potentiometer's reading
  // Serial.println(reinterpret_cast<uintptr_t>(potentiometerVal), DEC);
  // Arduino's builtin function to map values of the potentiometer to the BPM
  bpm = map(potentiometerVal, 0, 1023, 50, 250);



}

// The potentiometer allows values between 0 & 1023
// The Time signatures have 6 values || 1/4 | 2/4 | 3/4 | 4/4 | 5/4 | 7/4
// Therefore the Timesignature values need to be mapped to the potentiometer's values
// The function below returns the value of the Time Signature based on potentiometer's reading
// Reads potentiometer's values
void signatureVal(){

  // Creating a function pointer
  void (*potentiometerVal)();
  potentiometerVal = potSig.read();
  currentSignature = map(potentiometerVal, 0, 1023, 0, 6);
 
 switch (currentSignature) {
    case 0:
        oneByFour();
    break;

    case 1:
        twoByFour();
    break;

    case 2:
        threeByFour();
    break;

    case 3:
        fourByFour();
    break;

    case 4:
        fiveByFour();
    break;

    case 5:
        sevenByFour();
    break;

  }

}


// LCD display code
void lcdDisplay(){
  lcd.setCursor(0,0 );
  lcd.print("Time: ");
  lcd.println(signatures[currentSignature]);
  lcd.setCursor(0,1 );
  lcd.print("BPM: ");
  lcd.println(bpm);
}


// ********************************************************* //
// ********************************************************* //
// ********************************************************* //
// ********************************************************* //
// ********************************************************* //
// ********************************************************* //
// ********************************************************* //


void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.clear();
}

void loop() {  
   potBpmVal();
   signatureVal();
  //  lcd.clear();  // Clears the LCD
  //  lcdDisplay(); // Displays the content
}

