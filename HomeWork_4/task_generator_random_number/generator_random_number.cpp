#include <iostream>
using namespace std;

double gen(int m, int c) {
    static int i = 0;
    static double last = 0;
    cout << "i = " << i;
    last = ((int)(m * last + i++) % c);
    cout << ", s = " << last << endl;
    return last;
}

int main()
{
   while (cin.get()) {
       gen(37, 64);
    }
}
