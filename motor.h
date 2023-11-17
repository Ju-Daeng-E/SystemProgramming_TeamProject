#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "header.h"

#define ENA 18  // ENA 핀
#define IN1 23  // IN1 핀
#define IN2 24  // IN2 핀

#define ENB 17  // ENB 핀
#define IN3 22  // IN3 핀
#define IN4 27  // IN4 핀

#define PWM_RANGE 1024  // PWM 범위

void initMotor() {
    wiringPiSetupGpio();  // GPIO 핀 번호 사용

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    softPwmCreate(ENA, 0, PWM_RANGE);  // ENA 핀 PWM 초기화
    softPwmCreate(ENB, 0, PWM_RANGE);  // ENB 핀 PWM 초기화
}

void stopMotor() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    softPwmWrite(ENA, 0);  // ENA 핀 정지
    softPwmWrite(ENB, 0);  // ENB 핀 정지
}

void goForward(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

void goBackward(int spd) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

void turnLeft(int spd) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

void turnRight(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

#endif