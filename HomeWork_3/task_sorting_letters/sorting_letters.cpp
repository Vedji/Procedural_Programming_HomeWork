#include <iostream>
#include <string>
using namespace std;

int bringing(char s) {
	if (s == 'ё') return int('е') * 4 + 2;
	if (s == 'Ё') return (int('Е') + 32) * 4 + 1;
	if (65 <= s && s <= 90) return int(s) * 2 - 1;
	if (97 <= s && s <= 122) return (int(s) - 32) * 2 ;
	if (-32 <= s && s <= -1) return int(s) * 4;
	if (-64 <= s && s <= -33) return (int(s) + 32) * 4 - 1;
	return int(s);
}

string swap_line(string line, int a, int b) {
	char buffer = line[a];
	line[a] = line[b];
	line[b] = buffer;
	return line;
}


bool sorting_chek(string line) {
	// cout << line;
	if (line.size() == 0) return true;
	int last = bringing(line[0]);
	for (int i = 1; i < line.size(); i++) {
		if (last > bringing(line[i])) {
			// cout << " - false" << endl;
			return false;
		}
		last = bringing(line[i]);
	}
	// cout << " - true" << endl;
	return true;
}

string sorting_string(string line) {
	string buffer_line = line;
	// cout << int('a') << " - " << int('z') << endl;
	// cout << int('A') << " - " << int('Z') << endl;
	while (!sorting_chek(buffer_line)) {
		int last = bringing(buffer_line[0]);
		for (int i = 1; i < buffer_line.size(); i++) {
			if (last >= bringing(buffer_line[i])) {
				swap(buffer_line[i], buffer_line[i-1]);
			}
				last = bringing(buffer_line[i]);
		}
	}
	return buffer_line;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	string line;
	line = "йцукенгшщзхъфывапролджэячсмитьбюёЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮЁQWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm-";
	cout << line << endl << "Sorted: " << endl;
	if (line.size() == 0) {
		cout << "Ошибка в строке." << endl;
	}
	else {
		cout << sorting_string(line) << endl << endl;
	}
}
