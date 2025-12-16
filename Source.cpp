/**
 * @file Source.cpp
 * @brief √лавный файл программы.
 *
 * ѕрограмма считывает данные о мор€х из файла
 * и выводит их в табличном виде.
 */

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
#include "PrintList.h"
#include "ReadAll.h"
#include "FindSeaInfo.h"
using namespace std;

int main() {
    ifstream input("text.txt");
    vector<Sea> seas;

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const regex kNameRegex("\".*\"");
    const regex kSalinityRegex("-?\\d+\\.\\d+");
    const regex kDepthRegex(R"([+-]?\d+\b)");

    seas = ReadAll(input, kNameRegex, kSalinityRegex, kDepthRegex);
    int length = seas.size();
    PrintList(seas, length);

    int mode;
    cout << "¬ыберите режим работы\n"
        << "1 Ч —ортировка\n"
        << "2 Ч ‘ильтр\n"
        << "3 Ч —амое солЄное море\n"
        << "0 Ч ¬ыход\n";

    cin >> mode;

    while (mode != 0) {
        if (mode == 1) {
            sort(seas.begin(), seas.end(), CompareSeaByName);
            cout << "\nќтсортированный список:\n";
            PrintList(seas, length);
            mode = 0;
        }
        else if (mode == 2) {
            FindSeaInfo(seas, length, mode);
        }
        else if (mode == 3) {
            Sea s;
            int index = s.FindMostSalty(seas);

            cout << setw(30) << left << "Ќазвание" << setw(34) << "√лубина"
                << setw(38) << "—олЄность" << endl
                << endl;

            seas[index].Print();
            mode = 0;
        }

        if (mode == 0) {
            cout << "¬ыберите режим работы\n"
                << "1 Ч —ортировка\n"
                << "2 Ч ‘ильтр\n"
                << "3 Ч —амое солЄное море\n"
                << "0 Ч ¬ыход\n";
            cin >> mode;
        }
        else {
            break;
        }
    }

    return 0;
}

