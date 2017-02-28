A simple FFT in written in C, intended for the Arduino. I wrote this to learn writing my own FFT and because the projects I saw out there either had to much extra stuff in them, or were difficult to use and mold to my application. Upon writing this the extras that some of the other projects have are for good reason since you will likely need to tweak this code to meet the performance requirements of your applications. This project is simple enough to take and make easy adaptions. Although, it was intended for Arduino it will work on anything that runs C.

# Usage for a size 32 FFT:
```
#define N_FFT 32
double signal_re[N_FFT]; // real signal
double signal_im[N_FFT]; // imaginary signal
fft(signal_re,signal_im,N_FFT); // fft() will write over your arrays
```

# Cloning
Once you clone after running a `make` it will compile the code and run the test cases. The test cases are there to 1) know the code works and 2) for when you make changes to ensure it still works.

# Using for Arduino
The code was written and tested on Unix. Then I simply take the headers from `fft.h` and code from `fft.c` and put into my Arduino project.

# Performance

A work in progress to make it faster and keep it simple.

## Arduino DUE 32-Bit ARM at 84MHz
1. FFT Size = 8   took 4.5ms
2. FFT Size = 16  took 11.5ms
3. FFT Size = 32  took 27.5ms
4. FFT Size = 64  took 61.5ms
5. FFT Size = 128 took 133.5ms
