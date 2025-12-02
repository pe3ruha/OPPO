#include "findinf.h"

void findinf(vector<sea> m, int len) {
    string f;
    bool nalichiesea = 0;
    cout << "Введите море о котором нужна информация: ";
    cin >> f;
    f = "\"" + f + "\"";
    for (int i = 0; i < len; i++) {
        if (f == m[i].name) {
            cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
            cout << setw(30) << left << m[i].name << setw(34) << m[i].glubina << setw(38) << m[i].solenost << endl << endl;
            nalichiesea = 1;
        }
    }
    if (nalichiesea == 0) {
        cout << "Данное море не найдено" << endl;
    }
}