#ifndef FFT_H
#define FFT_H


#ifdef __cplusplus
extern "C" {
#endif

// Function prototype for FFT
void FFT(double *xreal,double *ximag,int n);
void IFFT(double *xreal,double *ximag,int n);

#ifdef __cplusplus
}
#endif

#endif // FFT_H