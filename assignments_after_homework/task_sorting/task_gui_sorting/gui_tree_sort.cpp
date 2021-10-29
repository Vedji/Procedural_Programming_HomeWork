// Tree sort

#include <iostream>
#include <Windows.h>
using namespace std;

class Tree {
    private:
        int value;
        Tree *left;
        Tree *right;
    public:
        Tree(int value) {
            this->value = value;
        }

        int getValue() {
            return this->value;
        }

        void setList(int value) {
            // Рекурсивно устанавливать значения в ветки дерева
            if (this->value > value) 
                if (left == NULL)
                    this->left = new Tree(value);
                else
                    this->left->setList(value);
            else 
                if (right == NULL)
                    this->right = new Tree(value);
                else
                    this->right->setList(value);
        }

        void getSortedArr(int* arr, int len, int* i = new int(0)) {
            // Рекурсивно сортировать массив
            if (*i >= len) 
                return;
            if (this->left != NULL) 
                this->left->getSortedArr(arr, len, i);

            arr[(*i)++] = this->getValue();
            this->printArray(arr, len, 0, *i);
            if (this->right != NULL)
                this->right->getSortedArr(arr, len, i);
        }
        
        void printArray(int* arr, int len, int index_start = -1, int index_end = -1) {
            int max = arr[0];
            for (int i = 1; i < len; i++) max = (arr[i] > max) ? arr[i] : max;
            // Sleep(100);
            system("CLS");
            string line = "";
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // ios_base::sync_with_stdio(false);
            for (int y = 50; y >= 0; y--) {
                for (int x = 0; x < len; x++) {
                    if (index_start <= x) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    }
                    if (index_end > x)
                        SetConsoleTextAttribute(hConsole, 15);
                    if (y < arr[x] / 2) cout << (char)219;
                    else if (arr[x] % 2 == 1 && y == arr[x] / 2) cout << (char)220;
                    else cout << " ";
                    cout << " ";
                }
                cout << endl;
            }
        
        // cout << line;
        Sleep(1000);
        }
};

double gen(int m, int c) {
    static int i = 2;
    static double last = 0;
    // cout << "i = " << i;
    last = ((int)(m * last + i++) % c);
    // cout << ", s = " << last << endl;
    return last;
}

int main()
{
    int arr_len = 40;
    int* arr = new int[arr_len];
    // Вывод неотсортированного массива в консоль
    // arr[0] = 100;
    for (int i = 0; i < arr_len; i++)
        arr[i] = (int)gen(37, 64);
    cout << "Not sorted array: ";
    for (int i = 0; i < arr_len; i++)
        if (i != arr_len - 1)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << ".";
    cout << endl;

    // Создане дерева по неотсортированоому массиву
    Tree *main_tree = new Tree(arr[0]);
    for (int i = 1; i < arr_len; i++)
            main_tree->setList(arr[i]);

    // Получение отсортированного массива
    // int* sorted_arr = new int[arr_len];
    main_tree->getSortedArr(arr, arr_len);

    // Вывод отсортированного массива в консоль
    main_tree->printArray(arr, arr_len, 0, arr_len);
    cout << "Sorted array:     ";
    for (int i = 0; i < arr_len; i++)
        if (i != arr_len - 1)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << ".";
    cout << endl;

}

