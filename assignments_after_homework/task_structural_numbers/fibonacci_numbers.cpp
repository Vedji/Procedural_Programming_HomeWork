// Числа Фибоначчи

#include <iostream>

using namespace std;

int f(int n) {
	double five = sqrt(5);
	double r = (pow(((1 + five) / 2), n) + pow(((1 - five) / 2), n)) / five;
	return round(r);
}

int main() {
	setlocale(0, "");
	int n;
	cout << "Введите номер члена последовательности фиббоеначи: ";
	cin >> n;
	cout << f(n);
}
