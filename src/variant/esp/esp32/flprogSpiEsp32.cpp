#include "flprogSpiEsp32.h"

#ifdef ARDUINO_ARCH_ESP32

bool FLProgSPI::begin()
{
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    bus()->begin((int8_t)pinSclk, (int8_t)pinMiso, (int8_t)pinMosi);
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