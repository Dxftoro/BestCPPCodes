#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<Windows.h>

#pragma warning(disable: 4018)

using namespace std;

string path_format(string p) { //функция форматирования указанного пути к файлу
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

string transliter(string orig_t) { //функция выполняющая саму "латинизацию"
	string kwords = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯабвгдеёжзийклмнопрстуфхцчшщьыъэюя,-:;.!?&%$#*@^[]{}()+=0123456789 ";
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
		bool found = false; //переменная для проверки на наличие символа в алфавите программы

		for (int k = 0; k < kwords.size(); k++) {
			if (orig_t[i] == kwords[k]) { //если символ из текста совпадает с символом из кириллического алфавита
				tran_t = tran_t + lwords[k];
				found = true; //фиксируем то, что символ совпал с одним из тех, которые находятся в алфавите
			}
		}

		if (found == false) tran_t = tran_t + orig_t[i]; //если символ так и не был найден, добавляем его без перевода
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

int main() { //мейн... -_-
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251); //смена кодировки вводимых символов
	SetConsoleOutputCP(1251); //смена кодировки выводимых символов

	ifstream fin; //поток ввода из файла
	ofstream fout("translated.txt"); //поток вывода переведённого текста в файл

	string path; //переменная пути к файлу
	string orig_w, orig_t, tran_t = "";

	cout << "Input file path: " << endl;
	getline(cin, path); //ввод пути к файлу

	path = path_format(path); //форматируем введённый путь
	fin.open(path); //открываем файл с текстом
	if (!fin) { //НЕ существует ли указанный файл?
		cout << "Error: Can't open specified file!" << endl;
		return 2;
	}

	fin.seekg(0); //устанавливаем курсор в самом начале текстового файла
	while (!fin.eof()) { //цикл считывания текста из файла
		fin >> orig_w;
		orig_t = orig_t + orig_w + " ";
	}

	//transform(orig_t.begin(), orig_t.end(), orig_t.begin(), ::tolower);
	tran_t = transliter(orig_t);
	cout << "Transliterating the file: " << endl << endl << tran_t << endl << endl; //выводим результат в консоль
	fout << tran_t; //выводим результат в файл

	//закрываем файлы в обязательном порядке!
	fin.close();
	fout.close();

	system("pause");
	return 1;
}
