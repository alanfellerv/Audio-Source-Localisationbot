#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

void motor_init();
void move_left();
void move_right();
void move_center();
void stop();

#ifdef __cplusplus
}
#endif

#endif // MOTOR_H