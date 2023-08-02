#include "flprogSpiEsp8266.h"

#ifdef ARDUINO_ARCH_ESP8266

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

void FLProgSPI::setBitOrder(uint8_t mode)
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
#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SPI)
    if (busNumber == 0)
    {
        return &SPI;
    }
#endif
    return 0;
}

void FLProgSPI::setHwCs(bool use)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setHwCs(use);
}

void FLProgSPI::setFrequency(uint32_t freq)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setFrequency(freq);
}

#endif