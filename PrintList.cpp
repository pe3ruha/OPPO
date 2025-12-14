#include "PrintList.h"



void PrintList(const vector<Sea>& list, int length) {
    cout << setw(30) << left << "Название" << setw(34) << "Глубина"
        << setw(38) << "Солёность" << endl
        << endl;

    for (int i = 0; i < length; ++i) {
        list[i].Print();
    }
}