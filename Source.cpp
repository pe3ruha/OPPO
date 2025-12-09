#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <vector>
#include <iomanip>
#include <regex>
#include <windows.h>
#include <algorithm>
#include "sea.h"
#include "compareSeaByName.h"
#include "printm.h"
#include "readall.h"
#include "findinf.h"
using namespace std;

int main() {
    ifstream in("text.txt");
    vector<sea> m;
    sea vr;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int len = 0;
    regex rp1("\"[^\"]*[A-Za-zА-Яа-яЁё][^\"]*\""), rp2(R"([+-]?\d*\.\d+)"), rp3(R"((?:^|\s)(\d+)(?:\s|$))");
    readall(in, rp1, rp2, rp3, vr, m, len);
    printm(m, len);
    int mode = -1;
    while (mode != 4) {
        cout << endl
            << endl << "Меню: "
            << endl << "1. Сортировка"
            << endl << "2. Фильтр"
            << endl << "3. Поиск самого солёного моря"
            << endl << "4. Выйти из программы"
            << endl;

        cout << "Выбор: ";
        cin >> mode;
        if (mode < 1 || mode > 4) {
            cout << "Введите значение из [1;4]!" << endl;
        }
        else {
            switch (mode) {
            case 1:
                sort(m.begin(), m.end(), compareSeaByName);
                cout << "\nОтсортированный список:" << endl;
                printm(m, len);
                break;
            case 2:
                findinf(m, len);
                break;
            case 3:
                cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
                cout << setw(30) << left << m[vr.findssea(m, len)].name << setw(34) << m[vr.findssea(m, len)].glubina << setw(38) << m[vr.findssea(m, len)].solenost << endl << endl;
                break;
            }
        }

    }
    return 0;
}

