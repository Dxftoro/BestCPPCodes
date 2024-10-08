#include <iostream>
#include <thread>
#include <mutex>

#include "matrix.h"

/*
Найти скалярное произведение векторов.
Распараллелить вычисление с использованием мьютексов
*/

using namespace std;

mutex mintay;

void Scalar(long long int* a, long long int* b, int dim, long long int* accum, int start) {
	mintay.lock();

	for (int i = start; i < dim; i += 2) {
		*(accum) += a[i] * b[i];
	}

	mintay.unlock();
}

int main() {
	int dim;
	
	cout << "Input vector size: "; cin >> dim;
	long long int* a = VecCreate(dim);
	long long int* b = VecCreate(dim);

	long long int scalar = 0;

	VecFill(a, dim, 2000); VecFill(b, dim, 2000);

	thread calc1(Scalar, a, b, dim, &scalar, 0);
	thread calc2(Scalar, a, b, dim, &scalar, 1);
	
	calc1.join();
	calc2.join();

	cout << scalar << endl;

	VecFree(a); VecFree(b);
	return 0;
}