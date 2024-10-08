#pragma once
#include <iostream>

using namespace std;

long long int** MatCreate(int size) { //выделение памяти под матрицу
	long long int** mat = new long long int* [size];

	for (int i = 0; i < size; i++) {
		mat[i] = new long long int[size];
	}

	return mat;
}

void MatFree(long long int** mat, int size) { //освобождение памяти, выделенной под матрицу
	for (int i = 0; i < size; i++) delete[] mat[i];
	delete[] mat;
}

long long int* VecCreate(int size) { //выделение памяти под вектор
	long long int* vec = new long long int[size];
	return vec;
}

void VecFree(long long int* vec) { //освобождение памяти, выделенной под вектор
	delete[] vec;
}

void VecRfill(long long int* vec, int size, long long int a = 5, long long int b = 20) { //заполнние вектора случайными числами
	for (int i = 0; i < size; i++) {
		vec[i] = a + rand() % b;
	}
}

void MatRfill(long long int** mat, int size, int a = 1, int b = 20) { //заполнение матрицы случайными числами
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = a + rand() % b;
	}
}

void VecFill(long long int* vec, int size, long long int val) { //заполнение вектора заданным значением
	for (int i = 0; i < size; i++) vec[i] = val;
}

void MatFill(long long int** mat, int size, long long int val) { //заполнение матрицы заданным значением
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = val;
	}
}

void VecOut(long long int* vec, int size, char end = '\n') { //вывод вектора в консоль
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << end;
}

void MatOut(long long int** mat, int size, char end = '\n') { //вывод матрицы в консоль
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << end;
}