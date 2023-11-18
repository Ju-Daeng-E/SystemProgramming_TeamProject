#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#include "spi.h"

#define ENA 1 // ENA 핀
#define IN1 4  // IN1 핀
#define IN2 5  // IN2 핀

#define ENB 0  // ENB 핀
#define IN3 3 // IN3 핀
#define IN4 2  // IN4 핀

#define PWM_RANGE 128  // PWM 범위

void initMotor() {
    wiringPiSetup();  // GPIO 핀 번호 사용

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
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

void goBackward(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

void turnLeft(int spd) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

    void turnRight(int spd) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    softPwmWrite(ENA, spd);
    softPwmWrite(ENB, spd);
}

int main() {
    initMotor();  // 초기화
    int fd = SPI_init();
    char enter;

    // while(1)
    // {
    //     printf("B value: %d\n", readadc(fd, 0));         //0번 채널의 값을 불러들임 (B의 값)
    //     printf("X value: %d\n", readadc(fd, 1));         //1번 채널의 값을 불러들임 (X의 값)
    //     printf("Y value: %d\n", readadc(fd, 2));         //2번 채널의 값을 불러들임 (Y의 값)
    //     delay(500);
    //  }
   while(1)
   {
     int cnt = 10;
     int Xsum = 0;
     int Ysum = 0;
    printf("ENTER : ");
    scanf("%c", &enter);
    switch(enter)
    {
        case 'f':
           
            do
            {
                printf("B value: %d\n", readadc(fd, 0));         //0번 채널의 값을 불러들임 (B의 값)
                printf("X value: %d\n", readadc(fd, 1));         //1번 채널의 값을 불러들임 (X의 값)
                printf("Y value: %d\n", readadc(fd, 2));         //2번 채널의 값을 불러들임 (Y의 값)

                Xsum += readadc(fd,1);
                Ysum += readadc(fd,2);
                cnt--;

                delay(1000);

            }while(cnt != 0);
            
            delay(500);
            break;
        case 'b':
         do
            {
                printf("B value: %d\n", readadc(fd, 0));         //0번 채널의 값을 불러들임 (B의 값)
                printf("X value: %d\n", readadc(fd, 1));         //1번 채널의 값을 불러들임 (X의 값)
                printf("Y value: %d\n", readadc(fd, 2));         //2번 채널의 값을 불러들임 (Y의 값)

                Xsum += readadc(fd,1);
                Ysum += readadc(fd,2);
                cnt--;

                delay(1000);

            }while(cnt != 0);
            
            delay(500);
            break;
        case 'l':
         do
            {
                printf("B value: %d\n", readadc(fd, 0));         //0번 채널의 값을 불러들임 (B의 값)
                printf("X value: %d\n", readadc(fd, 1));         //1번 채널의 값을 불러들임 (X의 값)
                printf("Y value: %d\n", readadc(fd, 2));         //2번 채널의 값을 불러들임 (Y의 값)

                Xsum += readadc(fd,1);
                Ysum += readadc(fd,2);
                cnt--;

                delay(1000);

            }while(cnt != 0);
            
            delay(500);
            break;
        case 'r':
         do
            {
                printf("B value: %d\n", readadc(fd, 0));         //0번 채널의 값을 불러들임 (B의 값)
                printf("X value: %d\n", readadc(fd, 1));         //1번 채널의 값을 불러들임 (X의 값)
                printf("Y value: %d\n", readadc(fd, 2));         //2번 채널의 값을 불러들임 (Y의 값)

                Xsum += readadc(fd,1);
                Ysum += readadc(fd,2);
                cnt--;

                delay(1000);

            }while(cnt != 0);
            
            delay(500);
            break;
    }

    printf("Average of %c\n", enter);
    printf("X average : %d", Xsum/10);
    printf("Y average : %d", Ysum/10);
   }
   
    

    return 0;
}
