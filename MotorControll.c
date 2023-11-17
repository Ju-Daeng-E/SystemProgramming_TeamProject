#include "pwm.h"
#include "motor.h"
#include "spi.h"

int main(int argc)
{
    initMotor();
    PWMinit();
    SPIinit();
    
}
