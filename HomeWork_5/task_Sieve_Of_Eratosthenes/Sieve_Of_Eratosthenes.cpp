// Задача "Решето Эратосфена"

#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n < 2 && n > 100000000) return 0;
    int *arr = new int[n];
    for (int i = 0; i <= n; i++) arr[i] = (i >= 2) ? i : 0;
    for (int y = 0; y < n; y++) if (arr[y] != 0) for (int x = y; x < n; x++) arr[x] = (arr[x] % arr[y] == 0 && arr[x] != arr[y]) ? 0 : arr[x];
    for (int i = 0; i < n; i++) if (arr[i] != 0) cout << arr[i] << endl;
}
