#include "sea.h"

void sea::print() {
    cout << setw(30) << left << name << setw(34) << glubina << setw(38) << solenost << endl;
}


int sea::findssea(vector<sea> s, int len) {
    float maxsol = 0;
    int z = 0;
    for (int i = 0; i < len; i++) {
        if (s[i].solenost > maxsol) {
            maxsol = s[i].solenost;
            z = i;
        }
    }
    return z;
}


void sea::read(istream& in, regex regN, regex regS, sea& vr) {
    string str;
    in >> str;
    if (regex_match(str, regN)) {
        vr.name = str;
    }
    if (regex_match(str, regS)) {
        vr.solenost = stof(str);
    }
    if (regex_match(str, regN) == 0 && regex_match(str, regS) == 0) {
        vr.glubina = stoi(str);
    }
}