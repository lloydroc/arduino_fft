#include <stdio.h>
#include <math.h>
#include <time.h>
#include "fft.h"

int
compare_arrays(const float x[], const float y[],  const unsigned int N, const float eps);

void
print_arr(const float data[], const unsigned int N);

void
print_test_result(int tc_re, int tc_im, int tc_num);

// We will run 4 test cases to ensure our FFT data is correct
int main(int argc,  char **argv)
{
  int i; // loop iterator
  clock_t start,  stop;
  double cpu_time_used;

  // Test Case 0 - Rearranging
  float data0_re[8] = {1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0};
  float expected0_re[8] = {1.0,  5.0,  3.0,  7.0,  2.0,  6.0,  4.0,  8.0};
  float data0_im[8] = {1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0};
  float expected0_im[8] = {1.0,  5.0,  3.0,  7.0,  2.0,  6.0,  4.0,  8.0};
  rearrange(data0_re,  data0_im,  8);
  int tc0_re = compare_arrays(data0_re, expected0_re, 8, 0.01);
  int tc0_im = compare_arrays(data0_im, expected0_im, 8, 0.01);
  print_test_result(tc0_re, tc0_im, 0);

  // Test Case 1
  float data1_re[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  float data1_im[8] = {7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0};
  float expected1_re[8] = {28.0, 5.656, 0.0, -2.343, -4.0, -5.656, -8.0, -13.656};
  float expected1_im[8] = {28.0, 13.656, 8.0, 5.656, 4.0, 2.343, 0.0, -5.656};
  fft(data1_re, data1_im, 8);
  int tc1_re = compare_arrays(data1_re, expected1_re, 8, 0.01);
  int tc1_im = compare_arrays(data1_im, expected1_im, 8, 0.01);
  print_test_result(tc1_re, tc1_im, 1);

  // Test Case 2
  float data2_re[8] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  float data2_im[8] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  float expected2_re[8] = {8.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  float expected2_im[8] = {8.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  fft(data2_re, data2_im, 8);
  int tc2_re = compare_arrays(data2_re, expected2_re, 8, 0.01);
  int tc2_im = compare_arrays(data2_im, expected2_im, 8, 0.01);
  print_test_result(tc2_re, tc2_im, 2);

  // Test Case 3
  float data3_re[8] = { 1.0, -1.0,  1.0, -1.0,  1.0, -1.0,  1.0, -1.0};
  float data3_im[8] = {-1.0,  1.0, -1.0,  1.0, -1.0,  1.0, -1.0,  1.0};
  float expected3_re[8] = {0.0, 0.0, 0.0, 0.0,  8.0, 0.0, 0.0, 0.0};
  float expected3_im[8] = {0.0, 0.0, 0.0, 0.0, -8.0, 0.0, 0.0, 0.0};
  fft(data3_re, data3_im, 8);
  int tc3_re = compare_arrays(data3_re, expected3_re, 8, 0.01);
  int tc3_im = compare_arrays(data3_im, expected3_im, 8, 0.01);
  print_test_result(tc3_re, tc3_im, 3);

  // Test Case 4
  float data4_re[4] = {1.0, 2.0, 3.0, 4.0};
  float data4_im[4] = {0.0, 0.0, 0.0, 0.0};
  float expected4_re[4] = {10.0, -2.0, -2.0, -2.0};
  float expected4_im[4] = {0.0, 2.0, 0.0, -2.0};
  fft(data4_re, data4_im, 4);
  int tc4_re = compare_arrays(data4_re, expected4_re, 4, 0.01);
  int tc4_im = compare_arrays(data4_im, expected4_im, 4, 0.01);
  print_test_result(tc4_re, tc4_im, 4);

  // Test Case 5
  float data5_re[128];
  float data5_im[128];

  start = clock();
  for(i=0;i<100000;i++) fft(data5_re, data5_im, 128);
  stop = clock();
  cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
  printf("Average time per fft %fms", cpu_time_used/1000);
}

void print_test_result(int tc_re, int tc_im, int tc_num)
{
  int res = tc_re+tc_im;
  if(res == 2) {
    printf("Test Case %d: Passed\n", tc_num);
  } else {
    printf("Test Case %d: Failed\n", tc_num);
  }
}

int compare_arrays(const float x[], const float y[], const unsigned int N, const float eps)
{
  int result = 1;
  for(unsigned int i=0;i<N;i++)
    {
      if(fabs(x[i]-y[i])>eps) {
	result = 0;
      }
    }

  if(result==0)
    {
      printf("Expected: ");
      print_arr(y, N);
      printf("Got     : ");
      print_arr(x, N);
    }

  return 1;
}

void print_arr(const float data[], const unsigned int N)
{
  printf("{");
  for(unsigned int i=0;i<N-1;i++)
    printf("%.3f, ", data[i]);
  printf("%.3f}\n", data[N-1]);
}
