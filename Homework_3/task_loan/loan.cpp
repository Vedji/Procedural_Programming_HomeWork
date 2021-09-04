#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double month_payments(double S, double p, double n){
    double r = p / 100.;
    if((12 * (pow(1 + r, n) - 1)) == 0){
        return 0;
    }
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main() {
    setlocale(0, "");
    double S, p, n;
    cout << "Enter loan S: ";
    cin >> S;
    cout << "Enter loan interest p: ";
    cin >> p;
    cout << "Enter estimated time n: ";
    cin >> n;
    cout << "Month payments: " << month_payments(S, p, n);

    return 0;
}
