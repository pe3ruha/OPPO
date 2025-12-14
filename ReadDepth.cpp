#include "ReadDepth.h"


bool ReadDepth(const string& line, const regex& depthRegex, Sea& temp, int lineNumber) {
    smatch match;
    if (!regex_search(line, match, depthRegex)) {
        cout << "Ошибка: Глубина не найдена. Строка " << lineNumber + 1 << endl;
        return false;
    }
    int d = stoi(match.str(0));
    if (d <= 0 || d >= 11034) {
        cout << "Ошибка: Глубина 1–11034. Строка " << lineNumber + 1 << endl;
        return false;
    }
    temp.depth = d;
    return true;
}