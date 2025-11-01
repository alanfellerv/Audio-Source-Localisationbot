#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>
#include <string.h>
#include <stdint.h>
#define sample_no 128
#define sampling_rate 44100
#define avg_threshold 15000
// I2S Configuration
#define I2S_WS 15
#define I2S_SD 13
#define I2S_SCK 2
#define I2S_PORT I2S_NUM_0

#endif // CONFIG_H
