#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef ARDUINO_ARCH_STM32

#ifdef SPI1
#if defined(FLPROG_CREATE_ALL_SPI) || defined(FLPROG_CREATE_SPI1)
#define FLPROG_HAS_SPI1
SPIClass SPI1;
#endif
#endif

#ifdef SPI2
#if defined(FLPROG_CREATE_ALL_SPI) || defined(FLPROG_CREATE_SPI2)
#define FLPROG_HAS_SPI2
SPIClass SPI2;
#endif
#endif

#ifdef SPI3
#if defined(FLPROG_CREATE_ALL_SPI) || defined(FLPROG_CREATE_SPI3)
#define FLPROG_HAS_SPI3
SPIClass SPI3;
#endif
#endif

#ifdef SPI4
#if defined(FLPROG_CREATE_ALL_SPI) || defined(FLPROG_CREATE_SPI4)
#define FLPROG_HAS_SPI4
SPIClass SPI4;
#endif
#endif

#define FLPROG_SPI_MODE0 SPI_MODE0
#define FLPROG_SPI_MODE1 SPI_MODE1
#define FLPROG_SPI_MODE2 SPI_MODE2
#define FLPROG_SPI_MODE3 SPI_MODE3

#define FLPROG_LSBFIRST LSBFIRST
#define FLPROG_MSBFIRST MSBFIRST

class FLProgSPI : public AbstractFLProgSPI
{
public:
    FLProgSPI(uint8_t _busNumber = 0);
    virtual bool begin();
    virtual void setBitOrder(BitOrder mode) { spi->setBitOrder(mode); };

protected:
    virtual SPIClass *bus();

private:
    void findDefaultPins(int32 *pins);
};

#endif
