#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    if (m <= 0) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    int x = 0, y = 0;

    while (m % 4 != 0) {
        m -= 3;
        x++;
        if (m < 0) break;
    }

    if (m%4 == 0)
        cout << x << endl << m/4 << endl;
    else
        cout << 0 << endl << 0 << endl;
}