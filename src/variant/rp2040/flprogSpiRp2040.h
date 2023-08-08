#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef ARDUINO_ARCH_RP2040
#define FLPROG_SPI_MODE0 SPI_MODE0
#define FLPROG_SPI_MODE1 SPI_MODE1
#define FLPROG_SPI_MODE2 SPI_MODE2
#define FLPROG_SPI_MODE3 SPI_MODE3

#define FLPROG_LSBFIRST LSBFIRST
#define FLPROG_MSBFIRST MSBFIRST

class FLProgSPI : public AbstractFLProgSPI
{
public:
    using AbstractFLProgSPI::AbstractFLProgSPI;
    virtual void setBitOrder(BitOrder mode) { (void)mode; };
    virtual void setDataMode(uint8_t mode) { (void)mode; };
    virtual void setClockDivider(uint8_t mode) { (void)mode; };
    virtual bool begin();

protected:
    virtual SPIClassRP2040 *bus();

private:
    void findDefaultPins(int32_t *pins);
};

#endif
