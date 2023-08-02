#include "flprogSpiAvr.h"

#ifdef ARDUINO_ARCH_AVR

bool FLProgSPI::begin()
{
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    bus()->begin();
    return true;
}


SPIClass *FLProgSPI::bus()
{
    if (busNumber == 0)
    {
        return &SPI;
    }
    return 0;
}

void FLProgSPI::setBitOrder(uint8_t mode)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setBitOrder(mode);
}


#endif