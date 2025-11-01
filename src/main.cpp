#include "config.h"
#include <driver/i2s.h>
#include "fir.h"
#include "tdoa.h"
#include "motor.h"
// global variables:
double res_real_L[256];
double res_img_L[256];
double res_real_R[256];
double res_img_R[256];

// put function declarations here:
void i2s_install();
void i2s_setpin();
int average(double* arr, int len);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200 );
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);
  motor_init();
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  static int32_t sample_buffer[256];
  size_t bytes = 0;
  esp_err_t result = i2s_read(I2S_PORT, &sample_buffer, sizeof(sample_buffer), &bytes, 100);

  if (result == ESP_OK && bytes == sizeof(sample_buffer))
  {
    
    
    
    FIR_filter(0, sample_buffer, res_real_L, res_img_L);
    FIR_filter(1, sample_buffer, res_real_R, res_img_R);
    int avg = average(res_real_L,256);

    if (avg >avg_threshold)
    {
      Serial.print("Avg:");
      Serial.println(avg);

      double tdoa_val = (double) tdoa(res_real_L, res_img_L, res_real_R, res_img_R)/sampling_rate;
      //Serial.print(">Direction:");
      if (tdoa_val > 0) {
        move_right();
        Serial.println("Right ");
      } else if (tdoa_val < 0) {
        move_left();

        Serial.println("Left ");
      }
      else {
        move_center();
        Serial.println("Center ");
      }
    }
  }
}










// put function definitions here:
void i2s_install(){
  static const i2s_config_t i2s_config = {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = sampling_rate,
    .bits_per_sample = i2s_bits_per_sample_t(24),
    .channel_format =   I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };
    i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin(){
  static const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = -1,
    .data_in_num = I2S_SD
  };

  i2s_set_pin(I2S_PORT, &pin_config);
}
int average(double* arr, int len){
  long int sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += arr[i]>0? (int) (arr[i]):(int)(-arr[i]);
  }
  return sum/len;
}
