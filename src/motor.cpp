#include "config.h"
#include "motor.h"
#define mot1u 26
#define mot1d 25
#define mot2u 33
#define mot2d 32
#define enable1 23
#define enable2 22

void motor_init()
{
  pinMode(mot1u, OUTPUT);
  pinMode(mot1d, OUTPUT);
  pinMode(mot2u, OUTPUT);
  pinMode(mot2d, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  stop();
}
void stop()
  {
    digitalWrite(mot1u, LOW);
    digitalWrite(mot1d, LOW);
    digitalWrite(mot2u, LOW);
    digitalWrite(mot2d, LOW);
    analogWrite(enable1, 0);
    analogWrite(enable2, 0);
  }
void move_left()
{
  
    digitalWrite(mot1u, HIGH);
    digitalWrite(mot1d, LOW);
    digitalWrite(mot2u, LOW);
    digitalWrite(mot2d, HIGH);
    analogWrite(enable1, 128);
    analogWrite(enable2, 128);
    delay(100);
    stop();


}

void move_right()
{

  {digitalWrite(mot1u, LOW);
    digitalWrite(mot1d, HIGH);
    digitalWrite(mot2u, HIGH);
    digitalWrite(mot2d, LOW);
    analogWrite(enable1, 128);
    analogWrite(enable2, 128);
    delay(100);
    stop();

    }
    
}

void move_center()
{
    
        digitalWrite(mot1u, HIGH);
        digitalWrite(mot1d, LOW);
        digitalWrite(mot2u, HIGH);
        digitalWrite(mot2d, LOW);
        analogWrite(enable1, 512);
        analogWrite(enable2, 512);
        delay(30);
        stop();                                                                                                                                                                                 
}

