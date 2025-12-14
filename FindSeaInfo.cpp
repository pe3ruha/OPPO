#include "FindSeaInfo.h"
#include "ReadSeaQuery.h"
#include "FindSeaIndex.h"
#include "PrintSeaResult.h"

void FindSeaInfo(const vector<Sea>& list, int length, int& mode) {
    string query = ReadSeaQuery();
    int index = FindSeaIndex(list, length, query);
    PrintSeaResult(list, index);
    mode = 0;
}