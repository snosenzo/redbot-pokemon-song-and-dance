#define NN 0
#define NN 1

#define S .25
#define E .5
#define Q 1
#define H 2


#define B1  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A2  55
#define AS2 58
#define B2  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A3  110
#define AS3 117
#define B3  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A4  220
#define AS4 233
#define B4  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A5  440
#define AS5 466
#define B5  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A6  880
#define AS6 932
#define B6  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A7  1760
#define AS7 1865
#define B7  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A8  3520
#define AS8 3729
#define B8  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978




#include <RedBot.h>
RedBotMotors motors;




//const int notes[] = {A4,B4,C4,D4,E4,C4,E4,NN,DS4,B4,DS4,NN,D4,AS4,D4,NN,A4,B4,C4,D4,E4,C4,E4,A5,G4,E4,C4,E4,G4,NN,NN};


const int notes[] = {A6, GS5, G5, FS5, A6, E5, F5, E5, A6, DS5, E5, DS5, A6, D5, DS5, D5, A6, CS5, D5, CS5, A6, C5, CS5, C5, A6, B5, C5, B5, A6, AS5, B5, AS5, B6, NN, NN, E4, NN, F4, NN, D4, E4, NN, F4, NN, C4, NN, B6, NN, NN, E4, NN, F4, NN, D4, E4, NN, F4, NN, A6, CS5, B5, NN, NN, CS5, NN, D5, NN, B5, CS5, NN, D5, NN, CS5, AS6, B6, NN, NN, CS6, NN, D6, NN, B6, CS6, NN, D6, NN, A6, CS5, D4, E4, FS4, B5, D4, B4, FS4, E4, D4, C4, B5, C5, C4, CS4, D4, DS4, E4, DS4, D4, CS4, C4, CS4, D4, DS4, E4, F4, FS4, G4, GS4, A5, GS4, G4, FS4, F4, E4, D4, B5, E4,   FS4, B5, FS4, CS4, B4, CS4, A5};
const double notln[]={S,   S,  S,   S,  S,  S,  S,  S,  S,   S,  S,   S,  S,  S,   S,  S,  S,   S,  S,   S,  S,  S,   S,  S,  S,  S,  S,  S,  S,   S,  S,   S,  E,  E,  E,  E,  Q,  E,  E,  E,  E,  E,  E,  Q,  E,  E,  E,  E,  E,  E,  Q,  E,  E,  E,  E,  E,  E,  Q,  E,   E,  E,  E,  E,   E,  Q,  E,  E,  E,   E,  E,  E,  Q,   E,   E,  E,  E,  E,   E,  Q,  E,  E,  E,   E,  E,  E,  Q,  E,   E,  E,  Q,   E,  Q,  Q,  Q,   Q,  E,  Q,  E,  Q,  H,  S,   S,  S,   S,  S,   S,  S,   S,  S,   S,  S,   S,  S,  S,   S,  S,   S,  S,   S,  S,   S,  S,  S,  S,E+Q,  Q, H+E+Q,  Q,   Q,   E,  E,   E, H};

#define MF 0
#define MB 1
#define SR 2
#define SL 3


int power = 200;
double delaycounter = 0;
const int motorAction[] =    {SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL, SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL, MF,  MB,  SR,  SL,  SR,  SL,  MF,  SR,  SL,  MF,  MB,  SR,  SL,  SR,  SL,  MF,  MB,  SL,  SR,  SL,  SR,  SL,  SR,  MF,  MB,  SL,  SR,  MB,  MF,  SL,  SR,  SL,  SR,  MF,  MB,  MF,  SL,  SR,  SL,  SR,  SL,  SR,  MB,  MF,  MB,  MF,  SL,  SR,  MB,  MF, SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL, SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  MF,  MB,  SR};
const double motorTime[] =   {95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95, 95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95, 760, 760, 190, 190, 190, 190, 380, 190, 190, 570, 570, 190, 190, 190, 190, 380, 380, 190, 190, 190, 190, 380, 380, 190, 190, 190, 190, 380, 380, 190, 190, 190, 190, 380, 190, 190, 190, 190, 190, 190, 380, 380, 380, 380, 380, 380, 570, 570, 380, 760,95,  95,  95,  95,  95,  95,  95,  95, 95,  95,  95,  95,  95,  95,  95,  95,  570, 380, 1330};
boolean motRun = false;
double beforeAfter[] = {0, 0};

const int buzzPin = 9;
const int buttonPin = 12;
boolean hasRun = false;
RedBotAccel acc;
int j = 0;
volatile boolean activated = false;



void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzPin, OUTPUT);  // configures the buzzerPin as an OUTPUT
  acc.enableBump();
}


void loop() {
  activated = acc.checkBump();
  if(activated && !hasRun){   
    
      for(int i = 0; i < sizeof(notes)/sizeof(int); i++){
        if(motRun){
          if(beforeAfter[1] < delaycounter+1){
            motRun = false;
            motors.brake();
          }
        }
        
        if(!motRun){
          beforeAfter[0] = delaycounter;
          beforeAfter[1] = motorTime[j%(sizeof(motorAction)/sizeof(int))]+delaycounter;
          startMotors(motorAction[j%(sizeof(motorAction)/sizeof(int))]);
          j++;
        }
        
        playNote(i, 1);
      }
      
      delay(2000);
      motors.brake();
      motRun = false;
      
      hasRun = true;

  }
  
  activated = false;
  // put your main code here, to run repeatedly:

}


void startMotors(int mode){

  if(mode == MF){
      motors.rightMotor(power);
      motors.leftMotor(-power); // Turn on left motor counter clockwise medium power (motorPower = 150)   
  }else if(mode == MB){
      motors.rightMotor(-power);
      motors.leftMotor(power); 
  }else if(mode == SR){
      motors.rightMotor(-power); // Turn CCW at motorPower of 100
      motors.leftMotor(-power);
  }else if(mode == SL){
      motors.rightMotor(power); // Turn CCW at motorPower of 100
      motors.leftMotor(power);
  }
  motRun = true;
  
}


void playNote(int nnum, double fastness){
  if( nnum < sizeof(notes)/sizeof(int)){
    int currnote = notes[nnum];
    double currlen = 380*notln[nnum];
    delaycounter+=currlen;
    if(currnote!=NN){
       tone(buzzPin,currnote);
       delay(currlen);
       noTone(buzzPin);
    } else{
      noTone(buzzPin);
      delay(currlen);  
    }
  }
}

