#ifndef __MOTOR__
#define __MOTOR__

#include "header.h"
#include "PWM.h"

//#define ENA 1 // ENA 핀
#define IN1 4  // IN1 핀
#define IN2 5  // IN2 핀

//#define ENB 26  // ENB 핀
#define IN3 3 // IN3 핀
#define IN4 2  // IN4 핀

//ENA, ENB는 각각 gpio기준 18번,12번 핀에 꽂혀야함.

#define PWM_RANGE 1024  // PWM 범위

void initMotor() {
    wiringPiSetup();  // GPIO 핀 번호 사용

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    PWMinit(PWM);

}

void stopMotor() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    PWMWriteDutyCycle(PWM, 0);

}

void goForward(int spd) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    PWMWriteDutyCycle(PWM, spd * 1000);

}

void goBackward(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    PWMWriteDutyCycle(PWM, spd * 1000);

}

void turnLeft(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    PWMWriteDutyCycle(PWM, spd * 1000);
 
}

    void turnRight(int spd) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    PWMWriteDutyCycle(PWM, spd * 1000);
}

#endif