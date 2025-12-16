#include "sea.h"

void Sea::Print() const {
    cout << setw(30) << left << name << setw(34) << depth << setw(38) << salinity<< endl;
}

int Sea::FindMostSalty(const std::vector<Sea>& seas) {
    int maxIndex = 0;
    for (size_t i = 1; i < seas.size(); ++i) {
        if (seas[i].salinity > seas[maxIndex].salinity) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


