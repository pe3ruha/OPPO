#include "printm.h"



void printm(vector<sea> m, int len) {
    cout << setw(30) << left << "Название" << setw(34) << "Глубина" << setw(38) << "Солёность" << endl << endl;
    for (int i = 0; i < len; i++) {
        m[i].print();
    }
}