#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


int main() {
    setlocale(0, "");
    double x, y, b;
    cout << "Enter x: ";
    cin >> x; // 1
    cout << "Enter y: ";
    cin >> y; // 4
    cout << "Enter b: ";
    cin >> b; // 4
    if ((b - y) <= 0 || (b - x) < 0) {
        cout << "b - x <= 0 or b - y < 0" << endl;
        system("Pause");
        return 0;
    }
    cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    system("Pause");
    return 0;
}
