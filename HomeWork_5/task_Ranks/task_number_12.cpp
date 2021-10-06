// Задание "Ряды", номер задания 12

#include <iostream>
#include <cmath>

using namespace std;

double task_4_12(int n, int k = 1, double denomination = 0) {
    double fact = 1;
    for (int i = 1; i <= k; i++) fact *= i;
    denomination += (1. / (double)k);
    double cur_member = fact / (double)pow(denomination, k);
    if (n == k) return cur_member;
    return task_4_12(n, ++k, denomination) + cur_member;
}

int main()
{
    setlocale(0, "");
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0 && n <= 100) {
        cout << "Неверно введеные данные" << endl;
        return 0;
    }
    cout << "y = " << task_4_12(n) << endl;
    return 0;
}
