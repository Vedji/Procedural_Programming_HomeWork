#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    ofstream file("homework_3_task_3.txt");
    char buf[256];
    cout << "Enter 3 line: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Enter line " << i << ": ";
        cin.getline(buf, 256);
        file << buf << endl;
    }
    file.close();
    cout << endl;
    char buffer[256];
    ifstream fin("homework_3_task_3.txt");
    cout << "Read file: " << endl;
    while (fin.getline(buffer, 256))
    {
        cout << buffer << endl;
    }
    fin.close();
    cout << endl;
    system("Pause");
}

