#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double month_payments(double S, double p, double n) {
    double r = p / 100.;
    if ((12 * (pow(1 + r, n) - 1)) == 0) {
        return 0;
    }
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main() {
    setlocale(0, "");
    float x = -4;
    while (x <= 4.) {
        if (x != 1) {
            cout << "y(" << x << ") = " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        }
        else {
            cout << "y(1) - Деленить на ноль нельзя!" << endl;
        }
        x += 0.5;
    }
    system("Pause");
    return 0;
}