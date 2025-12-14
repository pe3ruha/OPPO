#include "ReadSalinity.h"


bool ReadSalinity(const string& line, const regex& salRegex, Sea& temp, int lineNumber) {
    smatch match;
    if (!regex_search(line, match, salRegex)) {
        cout << "Ошибка: Солёность не найдена. Строка номер " << lineNumber + 1 << endl;
        return false;
    }

    float value = stof(match.str(0));
    if (value < 0 || value > 100) {
        cout << "Ошибка: Солёность 0–100. Строка номер " << lineNumber + 1 << endl;
        return false;
    }

    temp.salinity = value;
    return true;
}