#include "flprogSpiDue.h"

#ifdef ARDUINO_ARCH_SAM

FLProgSPI::FLProgSPI(uint8_t _busNumber)
{
    busNumber = _busNumber
}

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

void FLProgSPI::setBitOrder(BitOrder mode)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setBitOrder(mode);
}

SPIClass *FLProgSPI::bus()
{
    if (busNumber == 0)
    {
        return &SPI;
    }
    return 0;
}
#endif