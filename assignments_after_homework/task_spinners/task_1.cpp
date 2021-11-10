#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a <= 0 || b <= 0 || c <= 0)
        return 0;
    else
        cout << ((c - a) / b) << endl;
}
