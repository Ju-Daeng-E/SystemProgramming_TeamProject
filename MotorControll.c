#include "pwm.h"
#include "motor.h"
#include "spi.h"

int main(int argc)
{
    initMotor();  // 초기화
        
    goForward(500);
    delay(3000);

    goBackward(500);
    delay(3000);

    turnLeft(500);
    delay(3000);

    turnRight(500);
    delay(3000);
   
    stopMotor();
    return 0;

}
