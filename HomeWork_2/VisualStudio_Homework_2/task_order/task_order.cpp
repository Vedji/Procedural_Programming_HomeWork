#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


int main() {
    setlocale(0, "");
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "n is not natural number." << endl;
        system("Pause");
        return 0;
    }
    for (int i = n; i < n + 10; i++) {
        if (i != n + 9) {
            cout << i << ", ";
        }
        else {
            cout << i << "." << endl;
        }
    }
    system("Pause");
    return 0;
}