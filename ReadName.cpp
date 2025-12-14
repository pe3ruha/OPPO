#include "ReadName.h"


bool ReadName(const string& line, const regex& nameRegex, Sea& temp, int lineNumber) {
    smatch match;
    if (!regex_search(line, match, nameRegex)) {
        cout << "Ошибка: Название не найдено. Строка " << lineNumber + 1 << endl;
        return false;
    }
    temp.name = match.str(0);
    return true;
}