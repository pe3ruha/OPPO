#include "Sea.h"

void Sea::Print() const {
    cout << setw(30) << left << name << setw(34) << depth << setw(38) << salinity<< endl;
}

int Sea::FindMostSalty(const vector<Sea>& seas, int length) const {
    float maxSalinity = 0;
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (seas[i].salinity > maxSalinity) {
            maxSalinity = seas[i].salinity;
            index = i;
        }
    }
    return index;
}


