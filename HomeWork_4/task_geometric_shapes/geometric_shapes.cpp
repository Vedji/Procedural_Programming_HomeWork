// Задача "Геометрические фигуры" by Veji

#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
double areaRectangle(double a, double b) {
	if (a <= 0 || b <= 0) return -1;
	return a * b;
}

double areaTrinagle(double a, double h) {
	if (a <= 0 || h <= 0) return -1;
	return a * h * 0.5;
}

double areaCircle(double r) {
	if (r <= 0) return -1;
	return 3.14 * pow(r, 2);
}

int main()
{
	setlocale(0, "");
	cout << "Программа площади фигур." << endl << endl;

	cout << "Площадь прямоугольника:" << endl;
	double rect_a, rect_b, rect_area;
	cout << "Введите a: ";
	cin >> rect_a;
	cout << "Введите b: ";
	cin >> rect_b;
	rect_area = areaRectangle(rect_a, rect_b);
	if (rect_area <= 0) cout << "Ввод не правильный." << endl;
	if (rect_area > 0) cout << "Площадь прямоугольника = " << rect_area << endl;

	cout << endl
		<< "Площадь треугольника:" << endl;
	double trinagle_a, trinagle_h, trinagle_area;
	cout << "Введите a: ";
	cin >> trinagle_a;
	cout << "Введите h: ";
	cin >> trinagle_h;
	trinagle_area = areaTrinagle(trinagle_a, trinagle_h);
	if (trinagle_area <= 0) cout << "Ввод не правильный." << endl;
	if (trinagle_area > 0) cout << "Площадь Треугольника = " << trinagle_area << endl;

	cout << endl << "Площадь круга:" << endl;
	double circle_r, circle_area;
	cout << "Введите радиус: ";
	cin >> circle_r;
	circle_area = areaCircle(areaCircle(circle_r));
	if (circle_area <= 0) cout << "Ввод не правильный." << endl;
	if (circle_area > 0) cout << "Площадь прямоугольника = " << circle_area << endl;
}
