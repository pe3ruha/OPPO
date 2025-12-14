#include "PrintSeaHeader.h"
#include <iostream>
#include <iomanip>
using namespace std;

void PrintSeaHeader() {
    cout << setw(30) << left << "Название"
        << setw(34) << "Глубина"
        << setw(38) << "Солёность"
        << endl << endl;
}