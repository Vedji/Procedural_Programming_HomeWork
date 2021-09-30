// Задача "Автоматический распознаватель"

#include <iostream>
#include <string>
using namespace std;


int symbol_to_int(char symbol) {
	switch (symbol){
	case 'I': return    1; break;
	case 'V': return    5; break;
	case 'X': return   10; break;
	case 'L': return   50; break;
	case 'C': return  100; break;
	case 'D': return  500; break;
	case 'M': return 1000; break;
	}
	return 0;
}


int main()
{
	setlocale(0, "");
	string line = "";
	getline(cin, line);
	if (line.size() <= 0) { cout << "Error" << endl; return 0; }
	for (int i = 0; i < line.size(); i++) if (symbol_to_int(line[i]) == 0) return 0;
	int number = 0;
	int last = symbol_to_int(line[0]);
	int counter = 1;
	for (int i = 1; i < line.size(); i++) {
		if (counter > 3) {
			cout << "Число не соответствует римской классичсекой записи." << endl;
			return 0;
		}
		int cur = symbol_to_int(line[i]);
		if (cur == last) counter++;

		if (cur > last) { 
				number -= last * counter;
		}
		if (cur < last) number += last * counter;
		if (last != cur) counter = 1;
		last = cur;

	}
	if (last == symbol_to_int(line[line.size() - 1])) number += symbol_to_int(line[line.size() - 1]) * counter;
	
	cout << "Number = " << number << endl;
}
