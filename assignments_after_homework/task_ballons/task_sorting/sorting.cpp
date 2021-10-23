// Tree sort

#include <iostream>
using namespace std;

class Tree {
    private:
        int value;
        Tree *left;
        Tree *right;
    public:
        Tree(int val) {
            this->setValue(val);
        }

        void setValue(int value) {
            this->value = value;
        }

        int getValue() {
            return this->value;
        }

        void setList(int val) {
            // Рекурсивно устанавливать значения в ветки дерева
            if (value > val) 
                if (left == NULL)
                    this->left = new Tree(val);
                else
                    this->left->setList(val);
            else 
                if (right == NULL)
                    this->right = new Tree(val);
                else
                    this->right->setList(val);
        }

        int getSortedArr(int* arr, int len, int i = 0) {
            // Рекурсивно сортировать массив
            if (i >= len) 
                return i;
            if (this->left != NULL) 
                i = this->left->getSortedArr(arr, len, i);
            arr[i++] = this->getValue();
            if (this->right != NULL)
                i = this->right->getSortedArr(arr, len, i);
            return i;
        }
};

int main()
{
    int *arr = new int[] {5, 4, 3, 2, 1, 0, 0, -1, -2, -3, -4, -5};
    int arr_len = 12;
    // Вывод неотсортированного массива в консоль
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
    cout << "Sorted array:     ";
    for (int i = 0; i < arr_len; i++)
        if (i != arr_len - 1)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << ".";
    cout << endl;

}

