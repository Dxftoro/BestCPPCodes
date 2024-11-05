#include <iostream>
#include <thread>
#include <chrono>
#include <omp.h>
#include <stdio.h>

#include "matrix.h"
#define DIM 500

using namespace std;

void ParMul(int* vec, int** mat, int n) {
	int i, j;

	#pragma omp parallel shared(vec, mat) private(i, j)
	{
		#pragma omp for
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) mat[i][j] *= vec[j];
		}

		#pragma omp for
		for (i = 0; i < n; i++) vec[i] = 0;

		#pragma omp for
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) vec[j] += mat[j][i];
		}
	}
}

void LinMul(int* vec, int** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) mat[i][j] *= vec[j];
	}

	for (int i = 0; i < n; i++) vec[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vec[j] += mat[j][i];
		}
	}
}

int main() {
	cout << "Max threads: " << thread::hardware_concurrency() << endl;

	int** mat = MatCreate(DIM);
	int* vec = VecCreate(DIM);

	//linear
	MatFill(mat, DIM, 4); VecFill(vec, DIM, 2);

	auto beg = chrono::system_clock::now();
	ParMul(vec, mat, DIM);
	auto end = chrono::system_clock::now();

	chrono::duration<float> diff = end - beg;
	cout << "OpenMP mul time: " << diff.count() << endl;

	//OpenMP
	MatFill(mat, DIM, 4); VecFill(vec, DIM, 4);

	beg = chrono::system_clock::now();
	LinMul(vec, mat, DIM);
	end = chrono::system_clock::now();

	diff = end - beg;
	cout << "Linear mul time: " << diff.count() << endl;

	MatFree(mat, DIM);
	VecFree(vec);
	return 0;
}