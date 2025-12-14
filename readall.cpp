#include "readall.h"

vector<Sea> ReadAll(istream& in, const regex& nameRegex, const regex& salRegex, const regex& depthRegex) {
    string line;
    vector<Sea> seas;
    Sea temp;
    int lineNumber = 0;
    bool error = false;
    smatch match;

    while (getline(in, line)) {
        if (regex_search(line, match, nameRegex)) {
            temp.name = match.str(0);
        }
        else {
            cout << "Ошибка: Название не найдено. Строка " << lineNumber + 1 << endl;
            error = true;
        }

        if (regex_search(line, match, salRegex)) {
            float value = stof(match.str(0));
            if (value >= 0 && value <= 100) {
                temp.salinity = value;
            }
            else {
                cout << "Ошибка: Солёность 0–100. Строка " << lineNumber + 1 << endl;
                error = true;
            }
        }
        else {
            cout << "Ошибка: Солёность не найдена. Строка " << lineNumber + 1
                << endl;
            error = true;
        }

        if (regex_search(line, match, depthRegex)) {
            int d = stoi(match.str(0));
            if (d > 0 && d < 11034) {
                temp.depth = d;
            }
            else {
                cout << "Ошибка: Глубина 1–11034. Строка " << lineNumber + 1 << endl;
                error = true;
            }
        }
        else {
            cout << "Ошибка: Глубина не найдена. Строка " << lineNumber + 1 << endl;
            error = true;
        }

        if (!error) {
            seas.push_back(temp);
        }

        error = false;
        ++lineNumber;
    }
    return seas;
}