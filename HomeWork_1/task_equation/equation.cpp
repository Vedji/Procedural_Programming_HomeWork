#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    double b, c;
    cout << "Enter number b: ";
    cin >> b;
    cout << "Enter number c: ";
    cin >> c;
    if (b != 0) {
        cout << "x = " << -(c / b) << endl;
    }
    else {
        cout << "Encorect c." << endl;
    }
    system("pause");
}
