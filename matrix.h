#pragma once
#include <iostream>

using namespace std;

int** MatCreate(int size) {
	int** mat = new int* [size];
	
	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
	}

	return mat;
}

void MatFree(int** mat, int size) {
	for (int i = 0; i < size; i++) delete[] mat[i];
	delete[] mat;
}

int* VecCreate(int size) {
	int* vec = new int[size];
	return vec;
}

void VecFree(int* vec) {
	delete[] vec;
}

void VecRfill(int *vec, int size, int a = 5, int b = 20) {
	for (int i = 0; i < size; i++) {
		vec[i] = a + rand() % b;
	}
}

void MatRfill(int** mat, int size, int a = 1, int b = 20) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = a + rand() % b;
	}
}

void VecFill(int* vec, int size, int val) {
	for (int i = 0; i < size; i++) vec[i] = val;
}

void MatFill(int** mat, int size, int val) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = val;
	}
}

void VecOut(int* vec, int size, char end = '\n') {
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << end;
}

void MatOut(int** mat, int size, char end = '\n') {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << end;
}

