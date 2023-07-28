//D:\Programming\testing\bydlo.txt
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<Windows.h>

#pragma warning(disable: 4018) //��� �� ���� ����� ��� ��������������, ����� ���...

using namespace std;

string path_format(string p) { //������� �������������� ���������� ���� � �����
	string result;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == static_cast<char>(92)) {
			result = result + p[i] + p[i];
		}
		else {
			result = result + p[i];
		}
	}

	return result;
}

string transliter(string orig_t) { //������� ����������� ���� "�����������"
	string kwords = "�����Ũ����������������������������������������������������������,-:;.!?&%$#*@^[]{}()+=0123456789 ";
	string lwords[99] = {
		"A", "B", "V", "G",
		"D", "E", "Yo", "Zh",
		"Z", "I", "Y", "K",
		"L", "M", "N", "O",
		"P", "R", "S", "T",
		"U", "F", "H", "TS",
		"Ch", "Sh", "Sh", "",
		"Y", "'", "E", "Ju",
		"Ja",
		"a", "b", "v", "g",
		"d", "e", "yo", "zh",
		"z", "i", "y", "k",
		"l", "m", "n", "o",
		"p", "r", "s", "t",
		"u", "f", "h", "ts",
		"ch", "sh", "sh", "",
		"y", "'", "e", "ju",
		"ja", ",", "-", ":",
		";", ".", "!", "?",
		"&", "%", "$", "#",
		"*", "@", "^", "[",
		"]", "{", "}", "(",
		")", "+", "=", "0",
		"1", "2", "3", "4",
		"5", "6", "7", "8",
		"9", " "
	};
	string tran_t = "";

	for (int i = 0; i < orig_t.size(); i++) {
		bool found = false; //���������� ��� �������� �� ������� ������� � �������� ���������

		for (int k = 0; k < kwords.size(); k++) {
			if (orig_t[i] == kwords[k]) { //���� ������ �� ������ ��������� � �������� �� �������������� ��������
				tran_t = tran_t + lwords[k];
				found = true; //��������� ��, ��� ������ ������ � ����� �� ���, ������� ��������� � ��������
			}
		}

		if (found == false) tran_t = tran_t + orig_t[i]; //���� ������ ��� � �� ��� ������, ��������� ��� ��� ��������
		found = false;
	}

	return tran_t;
}

/*void toClipboard(string text) {
	if (OpenClipboard(0)) {
		EmptyClipboard();
		char* cBuff = (char*)GlobalAlloc(GMEM_FIXED, strlen(text.c_str()) + 1);
		strcpy(cBuff, text.c_str());
		SetClipboardData(CF_TEXT, cBuff);
		CloseClipboard();
	}
}*/

int main() { //����... -_-
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251); //����� ��������� �������� ��������
	SetConsoleOutputCP(1251); //����� ��������� ��������� ��������

	ifstream fin; //����� ����� �� �����
	ofstream fout("translated.txt"); //����� ������ ������������ ������ � ����

	string path; //���������� ���� � �����
	string orig_w, orig_t, tran_t = "";

	cout << "Input file path: " << endl;
	getline(cin, path); //���� ���� � �����

	path = path_format(path); //����������� �������� ����
	fin.open(path); //��������� ���� � �������
	if (!fin) { //�� ���������� �� ��������� ����?
		cout << "Error: Can't open specified file!" << endl;
		return 2;
	}

	fin.seekg(0); //������������� ������ � ����� ������ ���������� �����
	while (!fin.eof()) { //���� ���������� ������ �� �����
		fin >> orig_w;
		orig_t = orig_t + orig_w + " ";
	}

	//transform(orig_t.begin(), orig_t.end(), orig_t.begin(), ::tolower);
	tran_t = transliter(orig_t);
	cout << "Transliterating the file: " << endl << endl << tran_t << endl << endl; //������ ��������� � �������
	fout << tran_t; //������� ��������� � ����

	//��������� ����� � ������������ �������!
	fin.close();
	fout.close();

	system("pause");
	return 1;
}