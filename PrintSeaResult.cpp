#include "PrintSeaResult.h"
#include "PrintSeaHeader.h"


void PrintSeaResult(const vector<Sea>& list, int index) {
    if (index == -1) {
        cout << "Данное море не найдено" << endl;
        return;
    }

    PrintSeaHeader();
    list[index].Print();
}