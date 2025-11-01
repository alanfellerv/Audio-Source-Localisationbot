#include "config.h"
#include "fft.h"
#include "tdoa.h"
int max_array(double arr[], int n) {
    int idx = 0;
    double max= arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            idx = i;
            max=arr[idx];
        }
    }
    return idx;
}

double tdoa(double *xReal, double *xImag, double *yReal, double *yImag) {
    static double gReal[256];
    static double gImag[256];
    for (int i = 0; i < 256; i++) {
    // G = (xReal + j*xImag) * (yReal - j*yImag)
    // G = (xReal*yReal + xImag*yImag) + j*(xImag*yReal - xReal*yImag)
    gReal[i] = xReal[i] * yReal[i] + xImag[i] * yImag[i];
    gImag[i] = xImag[i] * yReal[i] - xReal[i] * yImag[i];
  }
  for (int i = 0; i < 256; i++)
  {
    // Calculate magnitude: |G| = sqrt(G_real^2 + G_imag^2)
    double magnitude = sqrt(gReal[i] * gReal[i] + gImag[i] * gImag[i]);

    // Normalize: G_phat = G / |G| to prevent division by zero
    if (magnitude > 1e-22) { // Use a small epsilon for float comparison
     gReal[i]= gReal[i] / magnitude;
       gImag[i]  = gImag[i] / magnitude;
    } else {
      gReal[i] = 0.0;
      gImag[i]  = 0.0;
    }
  }
  IFFT(gReal, gImag,256);
  double maximum = max_array(gReal, 256);
  if (maximum <= 128) return maximum;
  else return maximum-256;
}