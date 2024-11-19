#pragma once
#include <iostream>

using namespace std;

int** MatCreate(int size) { // matrix memory allocation function
	int** mat = new int* [size];

	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
	}

	return mat;
}

void MatFree(int** mat, int size) { // matrix memory freeing function
	for (int i = 0; i < size; i++) delete[] mat[i];
	delete[] mat;
}

int* VecCreate(int size) { // vector memory allocation function
	int* vec = new int[size];
	return vec;
}

void VecFree(int* vec) { // vector memory freeing function
	delete[] vec;
}

void VecRfill(int* vec, int size, int a = 5, int b = 20) { // fills given vector with randomly generated values in range from a to b
	for (int i = 0; i < size; i++) {
		vec[i] = a + rand() % b;
	}
}

void MatRfill(int** mat, int size, int a = 1, int b = 20) { // do the same but with matrix
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = a + rand() % b;
	}
}

void VecFill(int* vec, int size, int val) { // fills vecotr with given value
	for (int i = 0; i < size; i++) vec[i] = val;
}

void MatFill(int** mat, int size, int val) { // fills matrix with given value
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = val;
	}
}

void VecOut(int* vec, int size, char end = '\n') { // prints vector elements to console
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << end;
}

void MatOut(int** mat, int size, char end = '\n') { // prints matrix elements to console
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << end;
}