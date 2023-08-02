#include "flprogSpiAnon.h"

#ifdef FLPROG_ANON_SELECT_SPI

FLProgSPI::FLProgSPI(uint8_t _busNumber, int32_t _pinMOSI, int32_t _pinMISO, int32_t _pinSCLK)
{
    pinMosi = _pinMOSI;
    pinMosi = _pinMOSI;
    pinSclk = _pinSCLK;
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