// Задача про шарики

#include <iostream>
using namespace std;

bool debug = true;  // Вывод в консоль всех перестановок

void PrintIntArray(int* arr, int n) {
    // Вывод в консоль всех n элементов массива arr
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool not_in(int y, int* arr, int n) {
    // number, array, array_length
    // if number not in array
    for (int i = 0; i < n; i++)
        if (y == arr[i])
            return false;
    return true;
}

int permanent(int* arr,  int n, int index = 0) {
    int result = 0;
    if (index >= n) {
        if (debug)
            PrintIntArray(arr, n);
        for (int i = 0; i < n; i++)
            result += (arr[i] == i) ? 1 : 0;
        return result;
    }
    if (index == 0) {
        for (int i = 0; i < n; i++) {
            int *buff = new int[index+1];
            buff[0] = i;
            result += permanent(buff, n, index+1);
            delete buff;
        }
    }
    if (index > 0) {
        for (int z = 0; z < n; z++) {
            if (not_in(z, arr, index)) {
                int* buff = new int[index + 1];
                for (int i = 0; i < index; i++)
                    buff[i] = arr[i];
                buff[index] = z;
                result += permanent(buff, n, index + 1);
                delete buff;
            }
        }
    }
    return result;
}

int main()
{
    setlocale(0, "");
    int n;
    cout << "Введите n: ";
    cin >> n;
    if (n <= 0 || n > 10)
        cout << "Расчеты не возможны." << endl;
    else
        cout << "Количество ситуаций: " << permanent({}, n);
    return 0;
}
