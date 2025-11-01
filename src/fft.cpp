#include "fft.h"
#include "config.h" 
#include <arduinoFFT.h>
void FFT(double *xreal,double *ximag,int n){
  ArduinoFFT<double> FFT = ArduinoFFT<double>(xreal, ximag, n, sampling_rate);
  FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward); /* Weigh data */
  FFT.compute(FFTDirection::Forward); /* Compute FFT */
}
void IFFT(double *xreal,double *ximag,int n){
  ArduinoFFT<double> FFT = ArduinoFFT<double>(xreal, ximag, n, sampling_rate);
  FFT.compute(FFTDirection::Reverse);
}
