//============================
// gcc -o prueba prueba_c.c
// ./prueba
//============================
//  Programa de prueba en C 
//============================
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define VEC_LEN 1000000
#define AVERAGING 1000

int main(int argc, char** argv) {

  srand(time(NULL));

  //================
  //  Dos vectores 
  //================
  double* A = (double*)malloc(sizeof(double) * VEC_LEN);
  double* B = (double*)malloc(sizeof(double) * VEC_LEN);

  //==============================
  //  Llenado con números al azar
  //==============================
  for (int i = 0; i < VEC_LEN; ++i) {
    A[i] = (double)rand() / (double)RAND_MAX;
    B[i] = (double)rand() / (double)RAND_MAX;
  }

  double c;
  double* a = A;
  double* b = B;

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC_RAW, &start);

  //====================
  //  Producto escalar
  //====================
  for (int j = 0; j < AVERAGING; ++j) {
    c = 0.0;
    a = A;
    b = B;

    for (int i = 0; i < VEC_LEN; ++i) {
      c += (*a) * (*b);
      ++a;
      ++b;
    }
  }

  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  //===================
  //  Limpiar memoria
  //===================
  free(A);
  free(B);

  long d = (end.tv_sec - start.tv_sec) * 1000000 / AVERAGING + (end.tv_nsec - start.tv_nsec) / (1000 * AVERAGING);

  printf("c: %f\n", c);
  printf("For loop: %ld.%ldms\n", d / 1000, d % 1000);
}

