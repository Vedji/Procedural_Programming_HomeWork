// Задание "Файлы", номер задания 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check_line(string line) {
    /* Check String to good double */
    string nums = "0123456789";
    char mark = ',';
    char negativity = '-';

    bool checked_negativity = false;
    bool checked_whole_numbers = false;
    bool checked_dividing_mark = false;
    bool checked_fractional_numbers = false;

    for (int l = 0; l < (int)line.size(); l++) {
        bool is_char_num = false;
        if (l == 0 && line[l] == negativity) { checked_negativity = true; continue; }
        if (line[l] == mark && checked_dividing_mark == true) return false;
        if (line[l] == mark) { checked_dividing_mark = true; continue; }
        for (int n = 0; n < (int)nums.size(); n++) if (line[l] == nums[n]) is_char_num = true;
        if (is_char_num == false) return false;
        if (checked_whole_numbers == false && checked_dividing_mark == true) return false;
        if (is_char_num == true && checked_dividing_mark == false && checked_whole_numbers == false) checked_whole_numbers = true;
        if (is_char_num == true && checked_dividing_mark == true) checked_fractional_numbers = true;
        if (checked_dividing_mark == true && checked_whole_numbers == false) return false;
    }
    if (checked_whole_numbers && checked_dividing_mark && checked_fractional_numbers) return true;
    if (checked_whole_numbers && checked_dividing_mark == false && checked_fractional_numbers == false) return true;
    return false;

}

double toDouble(string line, char mark = ',') {
   /* String to Double */
    double number = 0;
    int step = 1;
    string nums = "0123456789";
    char negativity = '-';

    bool checked_negativity = false;
    bool checked_whole_numbers = false;
    bool checked_dividing_mark = false;
    bool checked_fractional_numbers = false;
    for (int l = 0; l < (int)line.size(); l++) {

        bool is_char_num = false;
        if (l == 0 && line[l] == negativity) { checked_negativity = true; continue; }
        if (line[l] == mark && checked_dividing_mark == true) return 0;
        if (line[l] == mark) { checked_dividing_mark = true; continue; }
        for (int n = 0; n < (int)nums.size(); n++) if (line[l] == nums[n]) is_char_num = true;
        int buffer_number = 0;
        switch (line[l])
        {
        case '0': buffer_number = 0; break;
        case '1': buffer_number = 1; break;
        case '2': buffer_number = 2; break;
        case '3': buffer_number = 3; break;
        case '4': buffer_number = 4; break;
        case '5': buffer_number = 5; break;
        case '6': buffer_number = 6; break;
        case '7': buffer_number = 7; break;
        case '8': buffer_number = 8; break;
        case '9': buffer_number = 9; break;
        }
        if (checked_dividing_mark == false) number = number * 10 + buffer_number;
        if (checked_dividing_mark) number = number + pow(10, -1 * step++) * buffer_number;
        if (is_char_num == false) return 0;
        if (checked_whole_numbers == false && checked_dividing_mark == true) return 0;
        if (is_char_num == true && checked_dividing_mark == false && checked_whole_numbers == false) checked_whole_numbers = true;
        if (is_char_num == true && checked_dividing_mark == true) checked_fractional_numbers = true;
        if (checked_dividing_mark == true && checked_whole_numbers == false) return 0;
    }
    if (checked_negativity == true) number *= -1;
    return number;
}

struct toyInfo
{
    string toyName;
    double cost;
    int minAge;
    int maxAge;
};

toyInfo getToyFromLine(string line) {
    /*
        В файле одна строка отвечает за одну игрушку.
        "toy Name" cost minAge maxAge\n
    */

    toyInfo member;
    member.toyName = "";
    member.cost = 0;
    member.minAge = 0;
    member.maxAge = 0;

    bool check_back = false;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '"' && check_back == false) {
            check_back = true;
            continue;
        }
        if (line[i] != '"' && check_back == true) member.toyName += line[i];
        if (line[i] == '"' && check_back == true) {
            line = line.substr(i + 1, line.size() - i + 1);
            break;
        }
    }
    int index_member = 0;
    string buff;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') buff += line[i];
        double buff_number = (check_line(buff) == true) ? toDouble(buff) : 0;
        if (line[i] == ' ' && buff.size() != 0) {
            double buff_number = (check_line(buff) == true) ? toDouble(buff) : 0;
            if (i == line.size() - 1) index_member++;
            if (index_member == 0) member.cost = buff_number;
            else if (index_member == 1) member.minAge = (int)buff_number;
            buff = "";
            index_member++;
        }
        if (line.size() - 1 == i) member.maxAge = (int)buff_number;
    }
    return member;
}

int main()
{
    setlocale(0, "");
    string buff;
    int line_iter = 0;
    int count_toy_info = 1000;
    ifstream fout("additional_files//task_5_1.txt");
    toyInfo* all_toys = new toyInfo[count_toy_info];
    while (getline(fout, buff)) {
        if (count_toy_info <= line_iter) {
            cout << "Записей в файле больше, чем программа может обработать." << endl << "Хотитет продолжить без оставшихся записей? (0 - No / 1 - Yes): ";
            int ask;
            cin >> ask;
            if (ask == 0) return 0;
            else break;
        }
        all_toys[line_iter++] = getToyFromLine(buff);
        buff = "";
    }
    // Вывод считыных записей
    for (int i = 0; i < line_iter; i++) {
        cout << " * toyName = " << all_toys[i].toyName << ", cost = " << all_toys[i].cost;
        cout << ", minAge = " << all_toys[i].minAge;
        cout << ", maxAge = " << all_toys[i].maxAge << endl;
    }

    // Позадача А
    cout << "********************************" << endl;
    cout << "Задача А" << endl;
    for (int i = 0; i < line_iter; i++) {
        if (all_toys[i].cost <= 400. && all_toys[i].minAge <= 8 && all_toys[i].maxAge >= 8) {
            cout << all_toys[i].toyName << endl;
        }
    }
    // Позадача Б
    cout << "********************************" << endl;
    cout << "Задача Б" << endl;

    toyInfo max_Cost = all_toys[0];
    for (int i = 1; i < line_iter; i++) {
        if (all_toys[i].cost >= max_Cost.cost) {
            max_Cost = all_toys[i];
        }
    }
    for (int i = 0; i < line_iter; i++) {
        if (all_toys[i].cost == max_Cost.cost) {
            cout << all_toys[i].toyName << ", cost = " << all_toys[i].cost << endl;
        }
    }
    // Подзадача В
    cout << "********************************" << endl;
    cout << "Задача В" << endl;
    for (int i = 0; i < line_iter; i++) {
        if (all_toys[i].minAge <= 4 && all_toys[i].maxAge >= 10) {
            cout << all_toys[i].toyName << endl;
        }
    }
    fout.close();
}
