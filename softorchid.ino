//
// softorchid.ino
//

#include <Servo.h>
#include "ServoEaser.h"

const int ledPin   = 13; 
const int servoPin = 10;

int servoFrameMillis = 20;  // minimum time between servo updates

Servo servo1; 
ServoEaser servoEaser;

// configurable list of servo moves
int myServoMovesCount0 = 9;
ServoMove myServoMoves0[] = {
// angle, duration
  { 10, 1500},
  {170, 1500},
  { 10, 1300},
  {170, 1300},
  { 90, 2000},
  { 90, 2000},  // wait at 90
  {135, 3000},
  { 45, 3000},
  {135, 1000},
};

int myServoMovesCount1 = 7;
ServoMove myServoMoves1[] = {
// angle, duration
  { 0,  1000},
  { 85,  500},
  { 35,  500},
  { 100,  500},
  { 80, 500},
  { 120,  500},
  { 100, 500},
};

// pick which list you want here
int myServoMovesCount = myServoMovesCount1;
ServoMove* myServoMoves = myServoMoves1;

//
void setup()
{
  Serial.begin(19200);
  Serial.println("ServoEaser2MovesList");

  // give pin, and min,max microseconds
  servo1.attach( servoPin ); //, 700,2300 );  // maybe give min/max here too?
  servoEaser.begin( servo1, servoFrameMillis );
  servoEaser.setMinMaxMicroseconds(700,2300);

  // start playing a moves list on a particular servo
  servoEaser.play( myServoMoves, myServoMovesCount );
}

//
void loop()
{
  servoEaser.update();
}
