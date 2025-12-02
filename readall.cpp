#include "readall.h"



void readall(istream& in, regex rp1, regex rp2, sea& vr, vector<sea>& m, int& len) {
    while (!in.eof()) {
        vr.read(in, rp1, rp2, vr);
        vr.read(in, rp1, rp2, vr);
        vr.read(in, rp1, rp2, vr);
        m.push_back(vr);
        len++;
    }
}