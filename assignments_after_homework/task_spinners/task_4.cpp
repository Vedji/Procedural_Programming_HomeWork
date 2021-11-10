#include <iostream>
using namespace std;

int main()
{
    int cupe[] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int n;
    int result = 0;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int line;
        cout << "Enter: ";
        cin >> line;
        if (0 < line && line < 37)
            cupe[(line - 1) / 4] += 1;
        else if (line > 36 && line < 55)
            cupe[8 - (line - 37) / 2] += 1;
        else return 0;
    }
    int cur = 0;
    for (int i = 0; i < 9; i++) {
        if (cupe[i] == 6)
            result = (++cur > result) ? cur : result;
        else
            cur = 0;
    }
    cout << result;
}
