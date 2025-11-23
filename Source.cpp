#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <vector>
#include <iomanip>
#include <regex>
#include <windows.h>
#include <algorithm>
using namespace std;

class sea {
public:
    string name;
    int glubina;
    float solenost;
    void print();
    void read(istream& in, regex regN, regex regS, sea& vr);
    int findssea(vector<sea> s, int len);
    int alph();
};

void sea::print() {
    cout << setw(30) << left << name << setw(34) << glubina << setw(38) << solenost << endl;
}
int sea::findssea(vector<sea> s, int len) {
    float maxsol = 0;
    int z = 0;
    for (int i = 0; i < len; i++) {
        if (s[i].solenost > maxsol) {
            maxsol = s[i].solenost;
            z = i;
        }
    }
    return z;
}
void sea::read(istream& in, regex regN, regex regS, sea& vr) {
    string str;
    in >> str;
    if (regex_match(str, regN)) {
        vr.name = str;
    }
    if (regex_match(str, regS)) {
        vr.solenost = stof(str);
    }
    if (regex_match(str, regN) == 0 && regex_match(str, regS) == 0) {
        vr.glubina = stoi(str);
    }
}



// Функция для сравнения двух объектов sea по алфавиту
bool compareSeaByName(const sea& a, const sea& b) {
    // Создаем строки без кавычек для сравнения
    string A = a.name.substr(1, a.name.length() - 2);
    string B = b.name.substr(1, b.name.length() - 2);

    // Русский алфавит в правильном порядке
    string russianAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";


    // Сравниваем по первому символу
    char FA = toupper(A[0]);
    char FB = toupper(B[0]);

    // Находим позиции в русском алфавите
    size_t posA = russianAlphabet.find(FA);
    size_t posB = russianAlphabet.find(FB);

    // Если оба символа русские, сравниваем по позиции в алфавите
    if (posA != string::npos && posB != string::npos) {
        return posA < posB;
    }

    // Если один из символов не русский, используем обычное сравнение
    return A < B;
}

void printm(vector<sea> m, int len) {
    cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
    for (int i = 0; i < len; i++) {
        m[i].print();
    }
}

void findinf(vector<sea> m, int len, int &rabota) {
    string f;
    bool nalichiesea = 0;
    cout << "Введите море о котором нужна информация: ";
    cin >> f;
    f = "\"" + f + "\"";
    for (int i = 0; i < len; i++) {
        if (f == m[i].name) {
            cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
            cout << setw(30) << left << m[i].name << setw(34) << m[i].glubina << setw(38) << m[i].solenost << endl << endl;
            rabota = 0;
            nalichiesea = 1;
        }
    }
    if (nalichiesea == 0) {
        cout << "Данное море не найдено" << endl;
        rabota = 0;
    }
}


void readall(istream& in, regex rp1, regex rp2, sea &vr, vector<sea>& m, int& len) {
    while (!in.eof()) {
        vr.read(in, rp1, rp2, vr);
        vr.read(in, rp1, rp2, vr);
        vr.read(in, rp1, rp2, vr);
        m.push_back(vr);
        len++;
    }
}


int main() {
    ifstream in("text.txt");
    vector<sea> m;
    sea vr;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int len = 0;
    regex rp1("\".*\""), rp2("-?\\d+\\.\\d+");
    readall(in, rp1, rp2, vr, m, len);
    printm(m, len);
    int rabota;
    cout << "Выберите режим работы" << endl << "1-Сортировка, 2-Фильтр, 0-Выход" << endl;
    cin >> rabota;

    while (rabota != 0) {
        if (rabota == 1) {
            sort(m.begin(), m.end(), compareSeaByName);
            cout << "\nОтсортированный список:" << endl;
            printm(m, len);
            rabota = 0;
        }
        if (rabota == 2) {
            findinf(m, len,rabota);
        }
        if (rabota = 3) {
            cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
            cout << setw(30) << left << m[vr.findssea(m, len)].name << setw(34) << m[vr.findssea(m, len)].glubina << setw(38) << m[vr.findssea(m, len)].solenost << endl << endl;
            rabota = 0;
        }
        if (rabota == 0) {
            cout << "Выберите режим работы" << endl << "1-Сортировка, 2-Фильтр, 0-Выход" << endl;
            cin >> rabota;
        }
        else {
            break;
        }
    }
    return 0;
}