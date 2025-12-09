#include "readall.h"

void readall(istream& in, regex rp1, regex rp2, regex rp3, sea& vr, vector<sea>& m, int& len) {
    string s, v;
    int n = 0;
    bool z = 0;
    smatch matc;
    while (!in.eof()) {
        getline(in, s);
        if (regex_search(s, matc, rp1)) {
            vr.name = matc.str(0);
        }
        else {
            cout << "Ошибка считывания данных. Название не найдено Строка: " << n + 1 << endl;
            z = 1;
        }
        if (regex_search(s, matc, rp2) && stof(matc.str(0)) <= 100 && stof(matc.str(0)) >= 0) {
            vr.solenost = stof(matc.str(0));
        }
        else if (!regex_search(s, matc, rp2)) {
            cout << "Ошибка считывания данных. Солёность не найдена Строка: " << n + 1 << endl;
            z = 1;
        }
        else if (stof(matc.str(0)) > 100 || stof(matc.str(0)) < 0) {
            cout << "Ошибка считывания данных. 0<=cолёность<=100 Строка: " << n + 1 << endl;
            z = 1;
        }
        if (regex_search(s, matc, rp3) && stoi(matc.str(0)) > 0 && stoi(matc.str(0)) < 11034) {
            vr.glubina = stoi(matc.str(0));
        }
        else if (!regex_search(s, matc, rp3)) {
            cout << "Ошибка считывания данных. Глубина не найдена Строка: " << n + 1 << endl;
            z = 1;
        }
        else if (stoi(matc.str(0)) <= 0 || stoi(matc.str(0)) >= 11034) {
            cout << "Ошибка считывания данных. 0<глубина<=11034 Строка: " << n + 1 << endl;
            z = 1;
        }
        if (!z) {
            m.push_back(vr);
            len++;
        }
        z = 0;
        n++;
    }
}
