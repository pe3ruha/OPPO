#pragma once
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Sea {
public:
    string name;
    int depth;
    float salinity;

    void Print() const;
    int FindMostSalty(const vector<Sea>& seas, int length) const;
};