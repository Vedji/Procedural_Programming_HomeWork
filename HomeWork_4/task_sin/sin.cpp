#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int getSin(double x, int d_y = 25) {
    return  (int) ((sin(x) * 10) + d_y/2);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
    for (double x = -10; x < 10; x+=0.1) {
        int y = getSin(x);
        if (y <= 1) continue;
        gotoxy((int) (x * 10), y);
        cout << '*';
    }
    for (int i = 0; i < 120; i++) {
        gotoxy(i, 0);
        cout << ' ';
    }
    gotoxy(0, 26);
}

