#include <Arduino.h>
#include <Wire.h>

#define LPS25HB_ADDRESS         0x5C

#define LPS25HB_REF_P_XL        0x08
#define LPS25HB_REF_P_L         0x09
#define LPS25HB_REF_P_H         0x0A
#define LPS25HB_WHO_AM_I        0x0F
#define LPS25HB_RES_CONF        0x10
#define LPS25HB_CTRL_REG1       0x20
#define LPS25HB_CTRL_REG2       0x21
#define LPS25HB_CTRL_REG3       0x22
#define LPS25HB_CTRL_REG4       0x23
#define LPS25HB_INTERRUPT_CFG   0x24
#define LPS25HB_INT_SOURCE      0x25
#define LPS25HB_STATUS_REG      0x27
#define LPS25HB_PRESS_OUT_XL    0x28
#define LPS25HB_PRESS_OUT_L     0x29
#define LPS25HB_PRESS_OUT_H     0x2A
#define LPS25HB_TEMP_OUT_L      0x2B
#define LPS25HB_TEMP_OUT_H      0x2C
#define LPS25HB_FIFO_CTRL       0x2E
#define LPS25HB_FIFO_STATUS     0x2F
#define LPS25HB_THS_P_L         0x30
#define LPS25HB_THS_P_H         0x31
#define LPS25HB_RPDS_L          0x39
#define LPS25HB_RPDS_H          0x3A

class BarometerClick {
    private:
        uint8_t _i2caddr;

        void writeRegister(uint8_t reg, uint8_t val);
        uint8_t readRegister(uint8_t reg);

    public:
        BarometerClick() {}
        void begin();
        void begin(uint8_t addr);
        float readPressure();
        float readTemperature();
};
