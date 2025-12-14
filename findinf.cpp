#include "findinf.h"

void FindSeaInfo(const vector<Sea>& list, int length, int& mode) {
    string query;
    bool found = false;

    cout << "Введите море о котором нужна информация: ";
    cin >> query;

    query = "\"" + query + "\"";

    for (int i = 0; i < length; ++i) {
        if (query == list[i].name) {
            cout << setw(30) << left << "Название" << setw(34) << "Глубина"
                << setw(38) << "Солёность" << endl
                << endl;

            list[i].Print();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Данное море не найдено" << endl;
    }

    mode = 0;
}