// Задача "Генератов случайных чисел"

#include <iostream>
using namespace std;

double gen( int m, int end_i, int c, double s = 0, int i = 0) {
    if (i >= end_i) return ((int) (m*s + i) % c);
    if (i != end_i) return gen(m, end_i, c, ((int)(m * s + i) % c), i + 1);
}

int main()
{
    std::cout << gen(37, 3, 64);
}
