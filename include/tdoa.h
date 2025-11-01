#ifndef TDOA_H
#define TDOA_H

#ifdef __cplusplus
extern "C" {
#endif

// Returns the index of the maximum value in arr of length n
int max_array(double arr[], int n);

// Computes the time difference of arrival (TDOA) between two signals
double tdoa(double *xReal, double *xImag, double *yReal, double *yImag);

#ifdef __cplusplus
}
#endif

#endif // TDOA_H