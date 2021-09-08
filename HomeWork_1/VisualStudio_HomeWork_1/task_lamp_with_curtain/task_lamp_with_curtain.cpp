#include <iostream>
#include <cstdlib>
#include <String>
using namespace std;

int main()
{
    setlocale(0, "");
    bool is_day, is_curtians_closed, is_lamp_on;
    string str_is_day, str_is_curtians_closed, str_is_lamp_on;
    cout << "Сейчас день(1/0): ";
    cin >> str_is_day;
    if (str_is_day == "true" || str_is_day == "1") {
        is_day = true;
    }
    else if (str_is_day == "false" || str_is_day == "0") {
        is_day = false;
    }
    else {
        cout << "Incorrect enter" << endl;
        return 0;
    }
    cout << "Шторы закрыты(1/0): ";
    cin >> str_is_curtians_closed;
    if (str_is_curtians_closed == "true" || str_is_curtians_closed == "1") {
        is_curtians_closed = true;
    }
    else if (str_is_curtians_closed == "false" || str_is_curtians_closed == "0") {
        is_curtians_closed = false;
    }
    else {
        cout << "Incorrect enter" << endl;
        return 0;
    }
    cout << "Включена ли лампа(1/0): ";
    cin >> str_is_lamp_on;
    if (str_is_lamp_on == "true" || str_is_lamp_on == "1") {
        is_lamp_on = true;
    }
    else if (str_is_lamp_on == "false" || str_is_lamp_on == "0") {
        is_lamp_on = false;
    }
    else {
        cout << "Incorrect enter" << endl;
        return 0;
    }

    if ((is_day && (!is_curtians_closed)) || is_lamp_on) {
        cout << "В комнате светло" << endl;
    }
    else {
        cout << "В комнате темно" << endl;
    }
    system("pause");
}