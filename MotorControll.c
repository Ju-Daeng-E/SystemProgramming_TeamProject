#include "pwm.h"
#include "motor.h"
#include "spi.h"
#include "spi_noWiring.h"

int main(int argc)
{
    initMotor();
    PWMinit();
    //SPIinit();
    SPI_NO_init();

}
