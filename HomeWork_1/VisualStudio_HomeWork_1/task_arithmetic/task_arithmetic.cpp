#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    setlocale(0, "");
    double a, b;
    cout << "Enter num 1: ";
    cin >> a;
    cout << "Enter num 2: ";
    cin >> b;
    cout << "Сумма первого и второго числа: " << a + b << endl;
    cout << "Разность первого и второго числа: " << a - b << endl;
    cout << "Произведение двух чисел: " << a * b << endl;
    if (b != 0) {
        cout << "Частное: " << a / b << endl;
    }
    else {
        cout << "Частное невозможно." << endl;
    }
    system("pause");
}