// Задача ""
#include <iostream>
#include <string>
using namespace std;

int char_to_int(char symbol) {
	switch (symbol){
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case 'A': return 10; break;
	case 'B': return 11; break;
	case 'C': return 12; break;
	case 'D': return 13; break;
	case 'E': return 14; break;
	case 'F': return 15; break;
	case 'G': return 16; break;
	case 'H': return 17; break;
	case 'I': return 18; break;
	case 'J': return 19; break;
	case 'K': return 20; break;
	case 'L': return 21; break;
	case 'M': return 22; break;
	case 'N': return 23; break;
	case 'O': return 24; break;
	case 'P': return 25; break;
	case 'Q': return 26; break;
	case 'R': return 27; break;
	case 'S': return 28; break;
	case 'T': return 29; break;
	case 'U': return 30; break;
	case 'V': return 31; break;
	case 'W': return 32; break;
	case 'X': return 33; break;
	case 'Y': return 34; break;
	case 'Z': return 35; break;
	}
	return -1;
}

string int_to_char(int symbol) {
	switch (symbol) {
	case 0: return "0"; break;
	case 1: return "1"; break;
	case 2: return "2"; break;
	case 3: return "3"; break;
	case 4: return "4"; break;
	case 5: return "5"; break;
	case 6: return "6"; break;
	case 7: return "7"; break;
	case 8: return "8"; break;
	case 9: return "9"; break;
	case 10: return "A"; break;
	case 11: return "B"; break;
	case 12: return "C"; break;
	case 13: return "D"; break;
	case 14: return "E"; break;
	case 15: return "F"; break;
	case 16: return "G"; break;
	case 17: return "H"; break;
	case 18: return "I"; break;
	case 19: return "J"; break;
	case 20: return "K"; break;
	case 21: return "L"; break;
	case 22: return "M"; break;
	case 23: return "N"; break;
	case 24: return "O"; break;
	case 25: return "P"; break;
	case 26: return "Q"; break;
	case 27: return "R"; break;
	case 28: return "S"; break;
	case 29: return "T"; break;
	case 30: return "U"; break;
	case 31: return "V"; break;
	case 32: return "W"; break;
	case 33: return "X"; break;
	case 34: return "Y"; break;
	case 35: return "Z"; break;
	}
	return "";
}

double to_ten(string line, int base_num = 2, double defVal = 0, char mark = '.') {
	bool negativity = false;
	double num = 0;
	if (line[0] == '-') negativity = true;
	if (negativity == true) line = line.substr(1);
	for (int i = 0; i < line.size(); i++) {
		int cur = char_to_int(line[i]);
		if (cur < 0) { cout << "Not a number" << endl; return 0;}
		num += cur * pow(base_num, line.size() - i - 1);
	}
	if (negativity == true) num *= -1;
	return num;
}

string to_ss(int num, int base_num = 2) {
	string n = int_to_char(num % base_num);
	if (num > 0) return to_ss(num / base_num, base_num) + n;
	n = "";
	return n;
}

int main()
{
	setlocale(0, "");
	string line, ret;
	int ss, to;
	bool negativity = false;
	cout << "Введите число: ";
	cin >> line;
	cout << "Введите систему счисления числа: ";
	cin >> ss;
	cout << "Введите систему счисления в которую хотите перевести число: ";
	cin >> to;
	int num = to_ten(line, ss);
	if (num < 0) { negativity = true; num *= -1; }
	ret = to_ss(num, to);
	if (negativity == true) ret = "-" + ret;
	cout << "Число = " << ret  << endl;
    return 0;
}
