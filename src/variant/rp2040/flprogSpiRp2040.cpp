#include "flprogSpiRp2040.h"

#ifdef ARDUINO_ARCH_RP2040

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
    int32_t pins[3] = {-1, -1, -1};
    findDefaultPins(pins);
    if (pinMiso == -1)
    {
        if (pins[0] > -1)
        {
            bus()->setRX(pins[0]);
        }
    }
    else
    {
        bus()->setRX(pinMiso);
    }
    if (pinMosi == -1)
    {
        if (pins[1] > -1)
        {
            bus()->setTX(pins[1]);
        }
    }
    else
    {
        bus()->setTX(pinMosi);
    }
    if (pinSclk == -1)
    {
        if (pins[2] > -1)
        {
            bus()->setSCK(pins[2]);
        }
    }
    else
    {
        bus()->setSCK(pinSclk);
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
    if (busNumber == 1)
    {
        return &SPI1;
    }
    return 0;
}

void FLProgSPI::findDefaultPins(int32 *pins)
{
    if (busNumber == 0)
    {
        pins[0] = PIN_SPI0_MISO;
        pins[1] = PIN_SPI0_MOSI;
        pins[2] = PIN_SPI0_SCK;
    }
    if (busNumber == 1)
    {
        pins[0] = PIN_SPI1_MISO;
        pins[1] = PIN_SPI1_MOSI;
        pins[2] = PIN_SPI1_SCK;
    }
}
#endif