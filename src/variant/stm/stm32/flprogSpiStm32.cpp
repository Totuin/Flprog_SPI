#include "flprogSpiStm32.h"

#ifdef ARDUINO_ARCH_STM32

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
            bus()->setMISO(pins[0]);
        }
    }
    else
    {
        bus()->setMISO(pinMiso);
    }
    if (pinMosi == -1)
    {
        if (pins[1] > -1)
        {
            bus()->setMOSI(pins[1]);
        }
    }
    else
    {
        bus()->setMOSI(pinMosi);
    }
    if (pinSclk == -1)
    {
        if (pins[2] > -1)
        {
            bus()->setSCLK(pins[2]);
        }
    }
    else
    {
        bus()->setSCLK(pinSclk);
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
#ifdef FLPROG_HAS_SPI1
    if (busNumber == 1)
    {
        return &SPI1;
    }
#endif
#ifdef FLPROG_HAS_SPI2
    if (busNumber == 2)
    {
        return &SPI2;
    }
#endif
#ifdef FLPROG_HAS_SPI3
    if (busNumber == 3)
    {
        return &SPI3;
    }
#endif
#ifdef FLPROG_HAS_SPI4
    if (busNumber == 4)
    {
        return &SPI4;
    }
#endif
    return 0;
}

void FLProgSPI::findDefaultPins(int32 *pins)
{
    if (busNumber == 0)
    {
        pins[0] = PIN_SPI_MISO;
        pins[1] = PIN_SPI_MOSI;
        pins[2] = PIN_SPI_SCK;
    }
#ifdef FLPROG_HAS_SPI1
    if (busNumber == 1)
    {
        pins[0] = pinmap_find_pin(SPI1, PinMap_SPI_MISO);
        pins[1] = pinmap_find_pin(SPI1, PinMap_SPI_MOSI);
        pins[2] = pinmap_find_pin(SPI1, PinMap_SPI_SCLK);
    }
#endif
#ifdef FLPROG_HAS_SPI2
    if (busNumber == 2)
    {
        pins[0] = pinmap_find_pin(SPI2, PinMap_SPI_MISO);
        pins[1] = pinmap_find_pin(SPI2, PinMap_SPI_MOSI);
        pins[2] = pinmap_find_pin(SPI2, PinMap_SPI_SCLK);
    }
#endif
#ifdef FLPROG_HAS_SPI3
    if (busNumber == 3)
    {
        pins[0] = pinmap_find_pin(SPI3, PinMap_SPI_MISO);
        pins[1] = pinmap_find_pin(SPI3, PinMap_SPI_MOSI);
        pins[2] = pinmap_find_pin(SPI3, PinMap_SPI_SCLK);
    }
#endif
#ifdef FLPROG_HAS_SPI4
    if (busNumber == 4)
    {
        pins[0] = pinmap_find_pin(SPI4, PinMap_SPI_MISO);
        pins[1] = pinmap_find_pin(SPI4, PinMap_SPI_MOSI);
        pins[2] = pinmap_find_pin(SPI4, PinMap_SPI_SCLK);
    }
#endif
}

#endif