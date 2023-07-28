#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<Windows.h>

#pragma warning(disable: 4018)

using namespace std;

string path_format(string p) { //ôóíêöèÿ ôîðìàòèðîâàíèÿ óêàçàííîãî ïóòè ê ôàéëó
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

string transliter(string orig_t) { //ôóíêöèÿ âûïîëíÿþùàÿ ñàìó "ëàòèíèçàöèþ"
	string kwords = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÛÚÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùüûúýþÿ,-:;.!?&%$#*@^[]{}()+=0123456789 ";
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
		bool found = false; //ïåðåìåííàÿ äëÿ ïðîâåðêè íà íàëè÷èå ñèìâîëà â àëôàâèòå ïðîãðàììû

		for (int k = 0; k < kwords.size(); k++) {
			if (orig_t[i] == kwords[k]) { //åñëè ñèìâîë èç òåêñòà ñîâïàäàåò ñ ñèìâîëîì èç êèðèëëè÷åñêîãî àëôàâèòà
				tran_t = tran_t + lwords[k];
				found = true; //ôèêñèðóåì òî, ÷òî ñèìâîë ñîâïàë ñ îäíèì èç òåõ, êîòîðûå íàõîäÿòñÿ â àëôàâèòå
			}
		}

		if (found == false) tran_t = tran_t + orig_t[i]; //åñëè ñèìâîë òàê è íå áûë íàéäåí, äîáàâëÿåì åãî áåç ïåðåâîäà
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

int main() { //ìåéí... -_-
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251); //ñìåíà êîäèðîâêè ââîäèìûõ ñèìâîëîâ
	SetConsoleOutputCP(1251); //ñìåíà êîäèðîâêè âûâîäèìûõ ñèìâîëîâ

	ifstream fin; //ïîòîê ââîäà èç ôàéëà
	ofstream fout("translated.txt"); //ïîòîê âûâîäà ïåðåâåä¸ííîãî òåêñòà â ôàéë

	string path; //ïåðåìåííàÿ ïóòè ê ôàéëó
	string orig_w, orig_t, tran_t = "";

	cout << "Input file path: " << endl;
	getline(cin, path); //ââîä ïóòè ê ôàéëó

	path = path_format(path); //ôîðìàòèðóåì ââåä¸ííûé ïóòü
	fin.open(path); //îòêðûâàåì ôàéë ñ òåêñòîì
	if (!fin) { //ÍÅ ñóùåñòâóåò ëè óêàçàííûé ôàéë?
		cout << "Error: Can't open specified file!" << endl;
		return 2;
	}

	fin.seekg(0); //óñòàíàâëèâàåì êóðñîð â ñàìîì íà÷àëå òåêñòîâîãî ôàéëà
	while (!fin.eof()) { //öèêë ñ÷èòûâàíèÿ òåêñòà èç ôàéëà
		fin >> orig_w;
		orig_t = orig_t + orig_w + " ";
	}

	//transform(orig_t.begin(), orig_t.end(), orig_t.begin(), ::tolower);
	tran_t = transliter(orig_t);
	cout << "Transliterating the file: " << endl << endl << tran_t << endl << endl; //âûâîäè ðåçóëüòàò â êîíñîëü
	fout << tran_t; //âûâîäèì ðåçóëüòàò â ôàéë

	//çàêðûâàåì ôàéëû â îáÿçàòåëüíîì ïîðÿäêå!
	fin.close();
	fout.close();

	system("pause");
	return 1;
}
