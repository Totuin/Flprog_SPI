#include "flprogSPI.h"

AbstractFLProgSPI::AbstractFLProgSPI(uint8_t _busNumber, int32_t _pinMOSI, int32_t _pinMISO, int32_t _pinSCLK)
{
    pinMosi = _pinMOSI;
    pinMiso = _pinMISO;
    pinSclk = _pinSCLK;
    busNumber = _busNumber;
}

bool AbstractFLProgSPI::begin(int32_t _pinMOSI, int32_t _pinMISO, int32_t _pinSCLK)
{
    pinMosi = _pinMOSI;
    pinMiso = _pinMISO;
    pinSclk = _pinSCLK;
    return begin();
}

void AbstractFLProgSPI::beginTransaction(SPISettings settings)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->beginTransaction(settings);
}

uint8_t AbstractFLProgSPI::transfer(uint8_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return bus()->transfer(data);
}

void AbstractFLProgSPI::transfer(uint8_t *buf, size_t count)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->transfer(buf, count);
}

uint16_t AbstractFLProgSPI::transfer16(uint16_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return bus()->transfer16(data);
}

void AbstractFLProgSPI::endTransaction()
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->endTransaction();
}

bool AbstractFLProgSPI::checkBus()
{
    return bus() != 0;
}

void AbstractFLProgSPI::stopBus()
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    return bus()->end();
}

void AbstractFLProgSPI::startBus()
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    return bus()->begin();
}

void AbstractFLProgSPI::changePins(int32_t newMisoPin, int32_t newMosiPin, int32_t newSclkPin)
{
    bool hasChanged = false;
    if (newMosiPin > -2)
    {
        if (pinMosi != newMosiPin)
        {
            pinMosi = newMosiPin;
            hasChanged = true;
        }
    }
    if (newMisoPin > -2)
    {
        if (pinMiso != newMisoPin)
        {
            pinMiso = newMisoPin;
            hasChanged = true;
        }
    }
    if (newSclkPin > -2)
    {

        if (pinSclk != newSclkPin)
        {
            pinSclk = newSclkPin;
            hasChanged = true;
        }
    }
    if (hasChanged)
    {
        stopBus();
        startBus();
    }
}

void AbstractFLProgSPI::changeBus(uint8_t newBus)
{
    if (busNumber == newBus)
    {
        return;
    }
    stopBus();
    busNumber = newBus;
    startBus();
}

void AbstractFLProgSPI::changePinsAndBus(uint8_t newBus, int32_t newMisoPin, int32_t newMosiPin, int32_t newSclkPin)
{
    bool hasChanged = false;
    if (newMosiPin > -2)
    {
        if (pinMosi != newMosiPin)
        {
            pinMosi = newMosiPin;
            hasChanged = true;
        }
    }
    if (newMisoPin > -2)
    {
        if (pinMiso != newMisoPin)
        {
            pinMiso = newMisoPin;
            hasChanged = true;
        }
    }
    if (newSclkPin > -2)
    {
        if (pinSclk != newSclkPin)
        {
            pinSclk = newSclkPin;
            hasChanged = true;
        }
    }
    if (busNumber != newBus)
    {
        return;
    }
    if (hasChanged)
    {
        stopBus();
        busNumber = newBus;
        startBus();
    }
}

void AbstractFLProgSPI::setDataMode(uint8_t mode)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setDataMode(mode);
}

void AbstractFLProgSPI::setClockDivider(uint8_t mode)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    bus()->setClockDivider(mode);
}
