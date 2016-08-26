#include <BarometerClick.h>

void BarometerClick::writeRegister(uint8_t reg, uint8_t val) {
    Wire.beginTransmission(_i2caddr);
    Wire.write(reg);
    Wire.write(val);
    Wire.endTransmission();
}

uint8_t BarometerClick::readRegister(uint8_t reg) {
    Wire.beginTransmission(_i2caddr);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(_i2caddr, (uint8_t)1);
    return Wire.read();
}

void BarometerClick::begin() {
    begin(LPS25HB_ADDRESS + 1); // By default the click is set to address 1
}

void BarometerClick::begin(uint8_t addr) {
    _i2caddr = addr;
    Wire.begin();
    writeRegister(LPS25HB_CTRL_REG1, 0b10110000);
}

float BarometerClick::readPressure() {
    uint8_t xl = readRegister(LPS25HB_PRESS_OUT_XL);
    uint8_t l = readRegister(LPS25HB_PRESS_OUT_L);
    uint8_t h = readRegister(LPS25HB_PRESS_OUT_H);
    uint32_t press = (h << 16) | (l << 8) | xl;
    return press / 4096.0;
}

float BarometerClick::readTemperature() {
    uint8_t l = readRegister(LPS25HB_TEMP_OUT_L);
    uint8_t h = readRegister(LPS25HB_TEMP_OUT_H);
    int16_t tmp = (h << 8) | l;
    return tmp / 480.0 + 42.5;
}
