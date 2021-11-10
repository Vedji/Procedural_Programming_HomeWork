#include <iostream>
using namespace std;

int main()
{
    int ans = 0, n, m;
    cin >> n;
    cin >> m;
    for (int x_1 = 0; x_1 < n; x_1++) {
        for (int x_2 = x_1; x_2 < n; x_2++) {
            for (int y_1 = 0; y_1 < m; y_1++) {
                for (int y_2 = y_1; y_2 < m; y_2++) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    
}
