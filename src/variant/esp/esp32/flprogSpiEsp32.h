#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef ARDUINO_ARCH_ESP32

#define FLPROG_SPI_MODE0 SPI_MODE0
#define FLPROG_SPI_MODE1 SPI_MODE1
#define FLPROG_SPI_MODE2 SPI_MODE2
#define FLPROG_SPI_MODE3 SPI_MODE3

#define FLPROG_LSBFIRST SPI_LSBFIRST
#define FLPROG_MSBFIRST SPI_MSBFIRST

class FLProgSPI : public AbstractFLProgSPI
{
public:
    using AbstractFLProgSPI::AbstractFLProgSPI;
    virtual bool begin();
    virtual void setBitOrder(uint8_t mode);
    virtual void setFrequency(uint32_t freq);
    virtual void setHwCs(bool use);

protected:
    virtual SPIClass *bus();
};

#endif
