// Задание "Ряды", номер задание 1.

#include <iostream>
#include <cmath>
using namespace std;

double f(int n, int i = 1, double d = 0) {
    d = d + sin(i);
    if (i == n) return i / d;
    return f(n, i + 1, d) + i / d;
}

int main()
{
    cout << "Rad" << endl;
    cout << "Enter n: ";
    int n;
    cin >> n;
    if (n <= 0) return 0;
    cout << f(n) << endl;
}
