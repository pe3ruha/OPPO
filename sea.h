#pragma once
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class sea {
public:
    string name;
    int glubina;
    float solenost;
    void print();
    void read(istream& in, regex regN, regex regS, sea& vr);
    int findssea(vector<sea> s, int len);
};