#pragma once
#include "Arduino.h"
#include <SPI.h>
#include "flprogUtilites.h"

class AbstractFLProgSPI
{
public:
    bool begin();
    virtual bool begin(int32_t pinMOSI, int32_t pinMISO = -1, int32_t pinSCLK = -1);
    uint8_t getErrorCode() { return codeErr; };
    bool isReady() { return checkBus(); }
    void beginTransaction(SPISettings settings);
    uint8_t transfer(uint8_t data);
    void transfer(uint8_t *buf, size_t count);
    uint16_t transfer16(uint16_t data);
    void endTransaction();

    void setDataMode(uint8_t mode);
    void setClockDivider(uint8_t mode);
    virtual void setFrequency(uint32_t freq){};
    virtual void setHwCs(bool use){};

    virtual void changePins(int32_t newMisoPin = -2, int32_t newMosiPin = -2, int32_t newSclkPin = -2);
    virtual void changeBus(uint8_t newBus);
    virtual void changePinsAndBus(uint8_t newBus, int32_t newMisoPin = -2, int32_t newMosiPin = -2, int32_t newSclkPin = -2);

protected:
    uint8_t codeErr = 0;
    int32_t pinMiso = -1;
    int32_t pinMosi = -1;
    int32_t pinSclk = -1;
    uint8_t busNumber = 0;
    virtual bool checkBus();
    virtual SPIClass *bus() { return 0; };
    virtual void startBus();
    virtual void stopBus();
};

#ifdef ARDUINO_ARCH_AVR
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/avr/flprogSpiAvr.h"
#endif

#ifdef ARDUINO_ARCH_SAM
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/due/flprogSpiDue.h"
#endif

#ifdef ARDUINO_ARCH_ESP32
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/esp/esp32/flprogSpiEsp32.h"
#endif

#ifdef ARDUINO_ARCH_ESP8266
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/esp/esp8266/flprogSpiEsp8266.h"
#endif

#ifdef ARDUINO_ARCH_STM32
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/stm/stm32/flprogSpiStm32.h"
#endif

#ifdef ARDUINO_ARCH_RP2040
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/rp2040/flprogSpiRp2040.h"
#endif

#ifndef FLPROG_EXISTS_SELECT_SPI
#define FLPROG_EXISTS_SELECT_SPI
#define FLPROG_ANON_SELECT_SPI
#include "variant/anon/flprogSpiAnon.h"
#endif
