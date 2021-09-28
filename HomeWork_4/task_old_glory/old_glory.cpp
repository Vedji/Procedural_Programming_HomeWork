#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main()
{
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 7; i++) {
        SetConsoleTextAttribute(hwnd, 7);
        SetConsoleTextAttribute(hwnd, BACKGROUND_BLUE);
        cout << "  *  *  *  *  *  *";
        if (i % 2 == 0) {
            SetConsoleTextAttribute(hwnd, 4);
            SetConsoleTextAttribute(hwnd, BACKGROUND_RED);
        }
        else {
            SetConsoleTextAttribute(hwnd, 7);
            SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY);
        }
        cout << " # # # # # # # # # # #" << endl;
    }

    for (int i = 0; i < 7; i++) {
        if (i % 2 == 0) {
            SetConsoleTextAttribute(hwnd, 7);
            SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY);
        }
        else {
            SetConsoleTextAttribute(hwnd, 4);
            SetConsoleTextAttribute(hwnd, BACKGROUND_RED);
        }
        cout << " # # # # # # # # # # # # # # # # # # # #" << endl;
    }
    SetConsoleTextAttribute(hwnd, 7);
    // SetConsoleTextAttribute(hwnd, COLOR_BACKGROUND);
}
