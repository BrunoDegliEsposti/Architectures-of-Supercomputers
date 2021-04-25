#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

double get_time(void) {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return (double)a.tv_sec + (double)a.tv_nsec * 1e-9;
}

__global__ void triad(double *A, double *B, double *C, double c, size_t nelems) {
	size_t i = blockIdx.x * blockDim.x + threadIdx.x;
	for (; i < nelems; i += gridDim.x * blockDim.x) {
		A[i] = B[i] * c + C[i];
	}
}

int main(int argc, char **argv) {
	// CPU initialization
	size_t nbytes = 1024*1024*1024;
	size_t nelems = nbytes / sizeof(double);
	double *h_A = (double*)malloc(nbytes);
	double *h_B = (double*)malloc(nbytes);
	double *h_C = (double*)malloc(nbytes);
	double c = 0.0;
	for (size_t i = 0; i < nelems; i++) {
		h_B[i] = 1.0;
		h_C[i] = 1.0;
	}

	// GPU code
	double t0, t1, t2, t3;
	double *d_A, *d_B, *d_C;
	t0 = get_time();
	cudaMalloc(&d_A, nbytes);
	cudaMalloc(&d_B, nbytes);
	cudaMalloc(&d_C, nbytes);
	cudaMemcpy(d_B, h_B, nbytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_C, h_C, nbytes, cudaMemcpyHostToDevice);
	t1 = get_time();
	triad<<<nelems/1024, 1024>>>(d_A, d_B, d_C, c, nelems);
	cudaThreadSynchronize();
	t2 = get_time();
	cudaMemcpy(h_A, d_A, nbytes, cudaMemcpyDeviceToHost);
	t3 = get_time();

	// Error-checking
	cudaError_t error = cudaGetLastError();
	if(error != cudaSuccess) {
		fprintf(stderr, "CUDA Error: %s\n", cudaGetErrorString(error));
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < nelems; i++) {
		assert(abs(h_A[i] - h_B[i] * c - h_C[i]) < 1e-15);
	}
	
	// Statistics
	double mb1 = 3*1e-9*(double)nbytes/(t2-t1);
	double mb2 = 3*1e-9*(double)nbytes/(t3-t0);
	printf("Memory bandwidth (without memory transfers): %f GB/s\n", mb1);
	printf("Memory bandwidth (with memory transfers): %f GB/s\n", mb2);
	return 0;
}