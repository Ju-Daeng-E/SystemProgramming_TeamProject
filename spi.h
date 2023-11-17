#include "header.h"

#define CHANNEL 0
#define SPEED 1000000

int ReadChannel(int channel) {
    unsigned char buffer[3];
    buffer[0] = 1;
    buffer[1] = (8 + channel) << 4;
    buffer[2] = 0;

    wiringPiSPIDataRW(CHANNEL, buffer, 3);

    int data = ((buffer[1] & 3) << 8) + buffer[2];
    return data;
}

// Define sensor channels
// (Channels 3 to 7 unused)
#define SWT_CHANNEL 0
#define VRX_CHANNEL 1
#define VRY_CHANNEL 2

void SPIinit()
{
    wiringPiSPISetup(CHANNEL, SPEED);
    wiringPiSetup();
}

int main() {

    float delay = 0.5;

    while (1) {
        int vrx_pos = ReadChannel(VRX_CHANNEL);
        int vry_pos = ReadChannel(VRY_CHANNEL);
        int swt_val = ReadChannel(SWT_CHANNEL);

        printf("-----------------------------\n");
        printf("X : %d  Y : %d  Switch : %d\n", vrx_pos, vry_pos, swt_val);

        delay(delay);
    }

    return 0;
}
