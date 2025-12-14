#include "FindSeaIndex.h"
#include "Sea.h"




int FindSeaIndex(const vector<Sea>& list, int length, const string& query) {
    for (int i = 0; i < length; ++i) {
        if (list[i].name == query) {
            return i;
        }
    }
    return -1;
}