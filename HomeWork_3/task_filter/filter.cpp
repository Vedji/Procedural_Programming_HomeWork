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

	for (int l = 0; l < (int) line.size(); l++) {
		bool is_char_num = false;
		if (l == 0 && line[l] == negativity) { checked_negativity = true; continue; }
		if (line[l] == mark && checked_dividing_mark == true) return false;
		if (line[l] == mark) { checked_dividing_mark = true; continue; }
		for (int n = 0; n < (int) nums.size(); n++) if (line[l] == nums[n]) is_char_num = true;
		if (is_char_num == false) return false;
		if (checked_whole_numbers == false && checked_dividing_mark == true) return false;
		if (is_char_num == true && checked_dividing_mark == false && checked_whole_numbers == false) checked_whole_numbers = true;
		if (is_char_num == true && checked_dividing_mark == true) checked_fractional_numbers = true;
		if (checked_dividing_mark == true && checked_whole_numbers == false) return false;
	}
	if (checked_whole_numbers && checked_dividing_mark && checked_fractional_numbers) return true;
	if (checked_whole_numbers&& checked_dividing_mark == false && checked_fractional_numbers == false) return true;
	return false;

}

int main()
{
	ifstream file_with_nums("C:/Users/Zzz/Documents/homework_3_task_4.txt");
	char buffer[256];
	while (file_with_nums.getline(buffer, 256))
	{
		string buff = buffer;
		if (check_line(buff)) cout << buff << endl;
	}
	file_with_nums.close();
	system("Pause");
	return 0;
}
