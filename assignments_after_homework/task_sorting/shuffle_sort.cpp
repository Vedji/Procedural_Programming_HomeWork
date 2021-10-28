// Сортировка перемешиванием

#include <iostream>
using namespace std;

void sort(int*arr, int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		for (int i = left; i < right; i++)
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
		right--;
		for (int i = right; i > left; i--)
			if (arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
		left++;
	}
}

int main()
{
	int* arr = new int[10]{9, 2, 5, 1, 0, 3, 4, 7, 6, 8};
	sort(arr, 10);
	for (int i = 0; i < 10; i++) cout << arr[i] << ", ";
}
