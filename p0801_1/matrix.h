#pragma once
#include <iostream>

using namespace std;

long long int** MatCreate(int size) { //âûäåëåíèå ïàìÿòè ïîä ìàòðèöó
	long long int** mat = new long long int* [size];

	for (int i = 0; i < size; i++) {
		mat[i] = new long long int[size];
	}

	return mat;
}

void MatFree(long long int** mat, int size) { //îñâîáîæäåíèå ïàìÿòè, âûäåëåííîé ïîä ìàòðèöó
	for (int i = 0; i < size; i++) delete[] mat[i];
	delete[] mat;
}

long long int* VecCreate(int size) { //âûäåëåíèå ïàìÿòè ïîä âåêòîð
	long long int* vec = new long long int[size];
	return vec;
}

void VecFree(long long int* vec) { //îñâîáîæäåíèå ïàìÿòè, âûäåëåííîé ïîä âåêòîð
	delete[] vec;
}

void VecRfill(long long int* vec, int size, long long int a = 5, long long int b = 20) { //çàïîëííèå âåêòîðà ñëó÷àéíûìè ÷èñëàìè
	for (int i = 0; i < size; i++) {
		vec[i] = a + rand() % b;
	}
}

void MatRfill(long long int** mat, int size, long long int a = 1, long long int b = 20) { //çàïîëíåíèå ìàòðèöû ñëó÷àéíûìè ÷èñëàìè
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = a + rand() % b;
	}
}

void VecFill(long long int* vec, int size, long long int val) { //çàïîëíåíèå âåêòîðà çàäàííûì çíà÷åíèåì
	for (int i = 0; i < size; i++) vec[i] = val;
}

void MatFill(long long int** mat, int size, long long int val) { //çàïîëíåíèå ìàòðèöû çàäàííûì çíà÷åíèåì
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) mat[i][j] = val;
	}
}

void VecOut(long long int* vec, int size, char end = '\n') { //âûâîä âåêòîðà â êîíñîëü
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << end;
}

void MatOut(long long int** mat, int size, char end = '\n') { //âûâîä ìàòðèöû â êîíñîëü
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << end;
}
