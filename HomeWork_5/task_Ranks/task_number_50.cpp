#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct member {
    string country_name;
    int gold_medal;
    int silver_medal;
    int bronze_medal;

    int all_medals;
    void sum_medal() {
        all_medals = gold_medal + silver_medal + bronze_medal;
    }
    int score;
    void sum_score() {
        score = gold_medal * 7 + silver_medal * 6 + bronze_medal * 5;
    }
};

int main()
{
    setlocale(0, "");
    string country_names[] = { "Австрия", "Германия", "Канада", "Китай", "Корея", "Норвегия", "Россия", "США", "Финляндия", "Япония" };
    member *olimpiad_members = new member[10];
    for (int i = 0; i < 10; i++) {
        olimpiad_members[i].country_name = country_names[i];
        cout << country_names[i] << " -> ";
        cin >> olimpiad_members[i].gold_medal >> olimpiad_members[i].silver_medal >> olimpiad_members[i].bronze_medal;
        olimpiad_members[i].sum_medal();
        olimpiad_members[i].sum_score();
    }

    // Добавить сортировку членов олимпиады по их счету
    bool flag = true;
    while (flag) {
        flag = false;
        int last_score = olimpiad_members[0].score;
        for (int i = 0; i < 10; i++) {
            if (last_score < olimpiad_members[i].score) {
                flag = true;
                
                swap(olimpiad_members[i - 1], olimpiad_members[i]);
            }
            last_score = olimpiad_members[i].score;
        }
    }
    // Конец сортировки
    cout << endl << "-------------------------------------------------------------------------" << endl;
    cout << "| # |   Страна   |  Золото  |  Серебро |  Бронза  |  Всего   |  Очков   |" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "|---|------------|----------|----------|----------|----------|----------|" << endl;
        cout << "|"  << setw(3) << i + 1 << "|";
        cout << setw(12) << olimpiad_members[i].country_name << "|";
        cout << setw(10) << olimpiad_members[i].gold_medal << "|";
        cout << setw(10) << olimpiad_members[i].silver_medal << "|";
        cout << setw(10) << olimpiad_members[i].bronze_medal << "|";
        cout << setw(10) << olimpiad_members[i].all_medals << "|";
        cout << setw(10) << olimpiad_members[i].score << "|" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}
