#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


int main() {
    setlocale(0, "");
    double x, a;
    cin >> x;
    cin >> a;
    if(x < 1){
        cout << "x < 1, w = " << a * log(abs(x)) << endl;
    }else{
        if(a - pow(x, 2) >= 0) {
            cout << "x >= 1, w = " << sqrt(a - pow(x, 2)) << endl;
        }else{
            cout << "Корень из отрицательного числа!" << endl;
        }
    }
    system("Pause");
    return 0;
}
