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
    FLProgSPI(uint8_t _busNumber = 0, int32_t _pinMOSI = -1, int32_t _pinMISO = -1, int32_t _pinSCLK = -1);
    virtual void setBitOrder(BitOrder mode);
    virtual bool begin();

protected:
    virtual SPIClass *bus();

private:
    void findDefaultPins(int32 *pins);
};

#endif
