// Задача "Умножение матриц"

#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    // set matrix
    const int matrix_a_len_x = 4, matrix_a_len_y = 3, matrix_b_len_x = 2, matrix_b_len_y = 4;
    double matrix_a[matrix_a_len_y][matrix_a_len_x] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}};
    double matrix_b[matrix_b_len_y][matrix_b_len_x] = {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50}};
    double matrix_c[matrix_a_len_y][matrix_b_len_x];
    // matrix multiplication
    for (int y = 0; y < matrix_a_len_y; y++) {
        for (int x = 0; x < matrix_b_len_x; x++) {
            matrix_c[y][x] = 0;
            for (int i = 0; i < matrix_b_len_y; i++) {
                matrix_c[y][x] += matrix_a[y][i] * matrix_b[i][x];
            }
        }
    }

    // Вывод полученной матрицы
    for (int y = 0; y < matrix_a_len_y; y++) {
        for (int x = 0; x < matrix_b_len_x; x++) {
            cout << matrix_c[y][x] << "   ";
        }
        cout << endl;
    }
    // Задание 1
    for (int i = 0; i < 25; i++) cout << "*";
    cout << endl << "Задание 1: " << endl;
    int max_seller, min_seller;
    double maxim = 0, minim = 10000000;
    for (int i = 0; i < matrix_a_len_y; i++) {
        if (maxim < matrix_c[i][0]) { max_seller = i + 1; maxim = matrix_c[i][0]; }
        if (minim > matrix_c[i][0]) { min_seller = i + 1; minim = matrix_c[i][0]; }
    }
    cout << "Продавец " << max_seller << " выручил больше всего денег. Их сумма равна " << maxim << endl;
    cout << "Продавец " << min_seller << " выручил меньше всего денег. Их сумма равна " << minim << endl;

    // Задание 2
    for (int i = 0; i < 25; i++) cout << "*";
    cout << endl << "Задание 2(Коммисионные): " << endl;

    max_seller = 0; min_seller = 0;
    maxim = 0, minim = 10000000;
    for (int i = 0; i < matrix_a_len_y; i++) {
        if (maxim < matrix_c[i][1]) { max_seller = i + 1; maxim = matrix_c[i][1]; }
        if (minim > matrix_c[i][1]) { min_seller = i + 1; minim = matrix_c[i][1]; }
    }
    cout << "Продавец " << max_seller << " получил больше всего комиссионных, они равны " << maxim << endl;
    cout << "Продавец " << min_seller << " получил меньше всего комиссионных, они равны " << minim << endl;

    // Задание 3
    for (int i = 0; i < 25; i++) cout << "*";
    cout << endl << "Задание 3: " << endl;

    double sum = 0;
    for (int i = 0; i < matrix_a_len_y; i++) sum += matrix_c[i][0] - matrix_c[i][1];
    cout << "Сумма денег вырученных за товары = " << sum << endl;

    // Задание 4
    for (int i = 0; i < 25; i++) cout << "*";
    cout << endl << "Задание 4: " << endl;

    sum = 0;
    for (int i = 0; i < matrix_a_len_y; i++) sum += matrix_c[i][1];
    cout << "Сумма коммисионных = " << sum << endl;

    // Задание 5
    for (int i = 0; i < 25; i++) cout << "*";
    cout << endl << "Задание 4: " << endl;

    sum = 0;
    for (int i = 0; i < matrix_a_len_y; i++) sum += matrix_c[i][0] + matrix_c[i][1];
    cout << "Сумма прошедших через руки денег = " << sum << endl;

}
