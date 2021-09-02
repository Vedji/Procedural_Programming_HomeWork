#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    setlocale(0, "rus");
    double h, R, r, l;
    const double Pi = 3.1415926535;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter R: ";
    cin >> R;
    cout << "Enter l: ";
    cin >> l;
    cout << "V = " << (1./3.) * Pi * h * (pow(R, 2) + R * r + pow(R, 2)) << endl;
    cout << "S = " << Pi * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    system("Pause");
    return 0;
}
