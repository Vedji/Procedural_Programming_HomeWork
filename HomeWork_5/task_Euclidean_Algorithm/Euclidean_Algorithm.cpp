// Задание "Алгоритм Евклида"

#include <iostream>
#include <cmath>

using namespace std;

int nod_devision(int a, int b) {
    if (a == b || b == 0) return a + b;
    if (a > b) return nod_devision(a % b, b);
    if (a < b) return nod_devision(a, b % a);
}

int nod_minus(int a, int b) {
    if (a == b) return a;
    if (a > b) return nod_minus(a - b, b);
    if (a < b) return nod_minus(a, b - a);
}

int main()
{
    setlocale(0, "");
    double a, b;
    cout << "gcd(a, b)" << endl << "В случае, если у числа присутствует дробная чать, она отбрасывается." << endl << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Вычитанием нод = " << nod_minus(abs((int)a), abs((int)b)) << endl;
    cout << "Делением нод = " <<  nod_devision(abs((int)a), abs((int)b)) << endl;
   
}
