#define NN 0

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

#define MF 0
#define MB 1
#define SR 2
#define SL 3

#include <RedBot.h>
RedBotMotors motors;
RedBotAccel acc1;
boolean done = false;

int f=1;
const int notes[] = 
{
  B4, AS4, A4, GS3, AS4, A4,
  GS3, G3, A4, GS3, G3, FS3,
  GS3, G3, FS3, F3, G3, FS3,
  F3, E3, FS3, F3, E3, DS3,
  F3, E3, DS3, D3, E3, DS3,
  D3, C3, B3, B3, D3, E3, B3,
  F3, E3, D3, B3, B3, D3, E3,
  B3, D3, A3, C3, B3, B3, D3,
  E3, B3, F3, E3, D3, B3, B3,
  D3, E3, B3, D3, A3, C3, B3,
  B3, D3, E3, B3, F3, E3, D3,
  B3, B3, D3, E3, B3, D3, A3,
  C3, B3, B3, D3, E3, B3, F3,
  E3, D3, B3, B3, D3, E3, B3,
  D3, A3, C3, B3, FS3, B3, FS3,
  B3, FS3, B3, FS3, B3, FS3, B3,
  F3, C3, G3, C3, G3, C3, G3,
  C3, G3, C3, G3, A4, G3, FS3,
  E3, D3, C3, B3, FS3, B3, FS3,
  B3, FS3, B3, FS3, B3, FS3, B3,
  F3, A3, E3, A3, E3, A3, E3, A3,
  E3, A3, E3, D3, CS3, D3, CS3, A3,
  GS2 
};

int j=0;
int power = 200;
double delaycounter = 0;
const int motorAction[] =    {SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL, SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL,  SR,  SL, MF,  MB,  SR,  SL,  SR,   MF,  MB,  SR,  SL,  SR};
const double motorTime[] =   {95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95, 95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95, 570, 570, 380, 380, 1140, 570, 570, 380, 380, 1140};
boolean motRun = false;
double beforeAfter[] = {0, 0};

const int buzzPin = 9;
const int buttonPin = 12;

volatile boolean bumped = false;

void setup()
{
  Serial.begin(9600);
  acc1.enableBump();
}

void loop() {
 bumped = acc1.checkBump();
  if(bumped && !done){   
    
      for(int i = 0; i < sizeof(notes)/sizeof(int); i++)
      {
        if (i>31)
        {
          f=2;
        }
        if(motRun){
          if(beforeAfter[1] < delaycounter+1)
          {
            motRun = false;
            motors.brake();
          }
        }
        
        if(!motRun)
        {
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
      delay(2000);
      
      f=1;
      done = true;
      bumped = false;

  }
  
}
  
  void startMotors(int mode)
 {

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

  motRun=true;
}


void playNote(int nnum, double fastness)
{
  if(nnum < sizeof(notes)/sizeof(int))
  {
    int currnote = notes[nnum];
    delaycounter+=95*f;
    if(currnote!=NN)
    {
      tone(buzzPin,currnote);
      delay(95*(f));
      noTone(buzzPin);
    } 
    else 
    {
      noTone(buzzPin);
      delay(95);  
    }
  }
}
