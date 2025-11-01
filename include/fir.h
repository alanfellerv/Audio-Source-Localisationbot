#ifndef FIR_H
#define FIR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Your existing function declarations go inside this block
void complex_array_multiply(double *v1Real, double *v1Img, const double *v2Real, const double *v2Img, double *r1Real, double *r1Img);

void FIR_filter(uint8_t l_r,int32_t *sample_buffer, double *res_real, double *res_img);

#ifdef __cplusplus
}
#endif

#endif // FIR_H