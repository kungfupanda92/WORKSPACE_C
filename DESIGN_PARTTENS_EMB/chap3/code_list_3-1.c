#include <stdlib.h>
#include <stdio.h>

#define TURN_OFF    (0x00)
#define INITIALIZE  (0x61)
#define RUN         (0x69)
#define CHECK_ERROR (0x02)
#define DEVICE_ADD  (0x01FFAFD0)

void emergencyShutDown(void)
{
    printf("OMG we're all gonna die\n");
}

int main(int argc, char *argv[])
{
    unsigned char *pDevice;

    // pDevice = (unsigned char *)(DEVICE_ADD);
    pDevice = (unsigned char *)malloc(sizeof(char));
    *pDevice = 0xFF; //start with all bit on

    printf ("Device bits %X\n", *pDevice);
    *pDevice = *pDevice & INITIALIZE; // and the bits into
    printf ("Device bits %X\n", *pDevice);
    if (*pDevice & CHECK_ERROR) { // system fail bit on?
        emergencyShutDown();
        abort();
    }
    else {
        *pDevice = *pDevice & RUN;
        printf ("Device bits %X\n", *pDevice);
    }


    return 0;
}