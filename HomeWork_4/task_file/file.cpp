// Задача "Файл"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool check_line(string line) {
	string nums = "0123456789";
	char mark = ',';
	char negativity = '-';

	bool checked_negativity = false;
	bool checked_whole_numbers = false;
	bool checked_dividing_mark = false;
	bool checked_fractional_numbers = false;

	for (int l = 0; l < (int)line.size(); l++) {
		bool is_char_num = false;
		if (l == 0 && line[l] == negativity) { checked_negativity = true; continue; }
		if (line[l] == mark && checked_dividing_mark == true) return false;
		if (line[l] == mark) { checked_dividing_mark = true; continue; }
		for (int n = 0; n < (int)nums.size(); n++) if (line[l] == nums[n]) is_char_num = true;
		if (is_char_num == false) return false;
		if (checked_whole_numbers == false && checked_dividing_mark == true) return false;
		if (is_char_num == true && checked_dividing_mark == false && checked_whole_numbers == false) checked_whole_numbers = true;
		if (is_char_num == true && checked_dividing_mark == true) checked_fractional_numbers = true;
		if (checked_dividing_mark == true && checked_whole_numbers == false) return false;
	}
	if (checked_whole_numbers && checked_dividing_mark && checked_fractional_numbers) return true;
	if (checked_whole_numbers && checked_dividing_mark == false && checked_fractional_numbers == false) return true;
	return false;

}

double toDouble(string line, char mark = ',') {
	double number = 0;
	int step = 1;
	string nums = "0123456789";
	char negativity = '-';

	bool checked_negativity = false;
	bool checked_whole_numbers = false;
	bool checked_dividing_mark = false;
	bool checked_fractional_numbers = false;
	for (int l = 0; l < (int)line.size(); l++) {
		
		bool is_char_num = false;
		if (l == 0 && line[l] == negativity) { checked_negativity = true; continue; }
		if (line[l] == mark && checked_dividing_mark == true) return 0;
		if (line[l] == mark) { checked_dividing_mark = true; continue; }
		for (int n = 0; n < (int)nums.size(); n++) if (line[l] == nums[n]) is_char_num = true;
		int buffer_number = 0;
		switch (line[l])
		{
			case '0': buffer_number = 0; break;
			case '1': buffer_number = 1; break;
			case '2': buffer_number = 2; break;
			case '3': buffer_number = 3; break;
			case '4': buffer_number = 4; break;
			case '5': buffer_number = 5; break;
			case '6': buffer_number = 6; break;
			case '7': buffer_number = 7; break;
			case '8': buffer_number = 8; break;
			case '9': buffer_number = 9; break;
		}
		if (checked_dividing_mark == false) number = number * 10 + buffer_number;
		if (checked_dividing_mark) number = number + pow(10, -1 * step++) * buffer_number;
		if (is_char_num == false) return 0;
		if (checked_whole_numbers == false && checked_dividing_mark == true) return 0;
		if (is_char_num == true && checked_dividing_mark == false && checked_whole_numbers == false) checked_whole_numbers = true;
		if (is_char_num == true && checked_dividing_mark == true) checked_fractional_numbers = true;
		if (checked_dividing_mark == true && checked_whole_numbers == false) return 0;
	}
	if (checked_negativity == true) number *= -1;
	return number;

	// if (checked_whole_numbers && checked_dividing_mark && checked_fractional_numbers) return true;
	// if (checked_whole_numbers && checked_dividing_mark == false && checked_fractional_numbers == false) return true;

}




int main()
{
	setlocale(0, "");
	ofstream fin("C:/Users/Zzz/Documents/HomeWork_4_task_1.txt");
	for (int i = 0; i < 10; i++) {
		double f;
		cout << "Введите элемент " << i << " : ";
		cin >> f;
		fin << f << endl;
	}
	fin.close();

	ifstream reading_file("C:/Users/Zzz/Documents/HomeWork_4_task_1.txt");
	int input_numbers = 0;
	string number_line;
	double summary = 0;
	char buffer[256];
	ifstream fout("C:/Users/Zzz/Documents/HomeWork_4_task_1.txt");
	cout << endl << "Read file: " << endl;
	while (fout.getline(buffer, 256))
	{
		string l = buffer;
		if (check_line(l) == false) continue;
		input_numbers++;
		summary += toDouble(buffer);
	}
	fout.close();
	if (input_numbers == 10) {
		cout << "Среднее число = " << summary;
	}
	else {
		cout << "В файле не 10 чисел. " << endl;
	}
}
