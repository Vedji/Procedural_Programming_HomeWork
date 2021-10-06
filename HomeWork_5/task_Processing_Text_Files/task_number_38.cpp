// Задание "Обработка текстовых файлов", номер задания 38

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char get_back_breckets(char breck) {
    switch (breck)
    {
    case ']':
        return '[';
        break;
    case '}':
        return '{';
        break;
    case ')':
        return '(';
        break;
    }
}

bool check_breckets(string from_file) {
    if (from_file.size() <= 0) return false;
    string breckets_stek = "";
    for (int i = 0; i < from_file.size(); i++) {
        switch (from_file[i])
        {
        case '(':
        case '{':
        case '[':
            breckets_stek += from_file[i];
            break;
        case ']':
        case '}':
        case ')':
            if (breckets_stek.size() <= 0) return false;
            if (get_back_breckets(from_file[i]) != breckets_stek[breckets_stek.size() - 1]) return false;
            breckets_stek.pop_back();
            break;
        }
    }
    if (breckets_stek.size() != 0) return false;
    return true;
}



int main()
{
    setlocale(0, "");
    cout << "Проверяемые скобки: (), {}, []." << endl;
    ifstream fout("C://Users//Zzz//Documents//HomeWork_5//task_3_38.txt");
    string all_lines = "";
    string buff;
    while (getline(fout, buff)) all_lines += buff;
    cout << ((check_breckets(all_lines)) ? "Последовательность проверяемых скобок не нарушена."
        : "Скобок либо нету, либо ошибка в их последовательности") << endl;    
}
