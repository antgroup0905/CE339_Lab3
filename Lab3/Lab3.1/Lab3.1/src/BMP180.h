#ifndef __BAROMETER_H__
#define __BAROMETER_H__

#include <Arduino.h>
#include <Wire.h>

const unsigned char OSS = 0;
#define BMP180_ADDRESS 0x77
class BMP180
{
public:
    void init(void);
    long PressureCompensate;
    float bmp180GetTemperature(unsigned int ut);
    long bmp180GetPressure(unsigned long up);
    float calcAltitude(float pressure);
    unsigned int bmp180ReadUT(void);
    unsigned long bmp180ReadUP(void);

private:
    int ac1, ac2, ac3;
    unsigned int ac4, ac5, ac6;
    int b1, b2, mb, mc, md;
    char bmp180Read(unsigned char address);
    int bmp180ReadInt(unsigned char address);
    void writeRegister(int deviceAddress, byte address, byte val);
    int readRegister(int deviceAddress, byte address);
};

#endif