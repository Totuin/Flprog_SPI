#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef FLPROG_ANON_SELECT_SPI

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
    virtual void setBitOrder(uint8_t mode);

protected:
    virtual SPIClass *bus();
};

#endif
