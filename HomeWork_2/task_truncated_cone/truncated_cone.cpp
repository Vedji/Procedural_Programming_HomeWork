#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/*
Enter h: 4
Enter r: 4
Enter R: 4
Enter l: 5
*/

int main() {
    setlocale(0, "");
    double h, R, r, l;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter R: ";
    cin >> R;
    cout << "Enter l: ";
    cin >> l;
    if (sqrt(pow(h, 2) + pow((R - r), 2)) !=  l) {
        cout << "Конус не существует" << endl;
        system("Pause");
        return 0;
    }
    if (r >= R) {
        if (r == R && h == l) {
            cout << "V цилиндра = " << (M_PI * pow(r, 2) * h) << endl;
            cout << "S цилиндра = " << (2 * M_PI * pow(r, 2) + 2 * M_PI * r * h) << endl;
        } 
        else {
            cout << "Это чото не известное науки." << endl;
        }
        system("Pause");
        return 0;
    }
    if (h < 0 || R < 0 || r < 0 || l < 0) {
        cout << "Отрицательные величины не принимаем!" << endl;
        system("Pause");
        return 0;
    }
    else {
        cout << "V = " << (1. / 3.) * M_PI * h * (pow(R, 2) + R * r + pow(R, 2)) << endl;
    }

    cout << "S = " << M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    system("Pause");
    return 0;
}
