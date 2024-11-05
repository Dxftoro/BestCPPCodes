#pragma once
#include <iostream>

using namespace std;

int** MatCreate(int size) { //выделение памяти под матрицу
	int** mat = new int* [size];

	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
	}

	return mat;
}

void MatFree(int** mat, int size) { //освобождение памяти, выделенной под матрицу
	for (int i = 0; i < size; i++) delete[] mat[i];
	delete[] mat;
}

int* VecCreate(int size) { //выделение памяти под вектор
	int* vec = new int[size];
	return vec;
}

void VecFree(int* vec) { //освобождение памяти, выделенной под вектор
	delete[] vec;
}

void VecRfill(int* vec, int size, int a = 5, int b = 20) { //заполнние вектора случайными числами
	for (int i = 0; i < size; i++) {
		vec[i] = a + rand() % b;
	}
}

void MatRfill(int** mat, int size, int a = 1, int b = 20) { //заполнение матрицы случайными числами
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = a + rand() % b;
	}
}

void VecFill(int* vec, int size, int val) { //заполнение вектора заданным значением
	for (int i = 0; i < size; i++) vec[i] = val;
}

void MatFill(int** mat, int size, int val) { //заполнение матрицы заданным значением
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = val;
	}
}

void VecOut(int* vec, int size, char end = '\n') { //вывод вектора в консоль
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << end;
}

void MatOut(int** mat, int size, char end = '\n') { //вывод матрицы в консоль
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << end;
}