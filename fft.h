#ifndef ARDUINO_FFT_INCLUDED
#define ARDUINO_FFT_INCLUDED

// An FFT for the Arduino.
// This was built on UNIX the C declarations
// and C code in fft.c can be placed into
// your Arduino project.
//
// The arrays for the fft will be computed in place
// and thus your array will have the fft result
// written over your original data
void fft(float data_re[], float data_im[],const int N);
// helper functions called by the fft
// data will first be rearranged then computed
void rearrange(float data_re[],float data_im[],const unsigned int N);
void compute(float data_re[],float data_im[],const unsigned int N);
#endif
