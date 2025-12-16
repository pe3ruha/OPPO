#include "FindSeaIndex.h"
#include "Sea.h"




int FindSeaIndex(const vector<Sea>& list, int length, const string& query) {
    auto it = std::find_if(list.begin(), list.end(),
        [&](const Sea& s) {
            return s.name == query;
        });

    if (it != list.end()) {
        return std::distance(list.begin(), it);
    }
    return -1;
}