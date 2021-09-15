#include <iostream>
#include <cmath>
using namespace std;

double month_payments(double S, double p, double n) {
    double r = p / 100.;
    if ((12 * (pow(1 + r, n) - 1)) == 0 || (((int)n % 2) == 0 && (1 + r) < 0)) {

        return -1;
    }
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main()
{
    setlocale(0, "");

    double S, M, N, s, m, n, r;
    bool flag = true;

    cout << "Введите S: ";
    cin >> S;
    cout << "Введите m: ";
    cin >> M;
    cout << "Введите n: ";
    cin >> N;
    if (S <= 0 || M <= 0 || N <= 0) {
        cout << " Такие числа не принимаем. " << endl;
        return 0;
    }
    r = S;
    m = month_payments(S, r, N);

    while (flag) {
        // system("CLS");
        if (_isnan(m) || _isnan(r)) {
            cout << "Error" << endl;
            break;
        }
        if ((M - 0.01) < m && m < (M + 0.01)) {
            cout << "p = " << r << ", m = " << m << ", M = " << M << endl;
            break;
        }
        else {
            if (m < M && r - r / 2 != 0) r += (r - r / 2) / 2;
            if (m > M && r * 2 - r != 0) r -= (r * 2 - r) / 2;
        }
        m = month_payments(S, r, N);
        cout << "[DEBUG]: p = " << r << ", m = " << m << endl;
        if (m)
            if (0 >= r || r > 100000 || m > 1000000000000000000) break;
        if ((M - 0.001) < m < (M + 0.001)) flag = false;
    }
    if (!flag) {
        cout << "[RELEASE]: p = " << r << ", m = " << m << endl;
    }
    else {
        cout << "Error" << endl;
    }
    system("Pause");
}
