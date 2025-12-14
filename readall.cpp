#include "ReadAll.h"
#include "ReadSeaLine.h"




vector<Sea> ReadAll(istream& in,const regex& nameRegex,const regex& salRegex,const regex& depthRegex){
    vector<Sea> seas;
    string line;
    int lineNumber = 0;

    while (getline(in, line)) {
        Sea temp;
        if (ReadSeaLine(line, nameRegex, salRegex, depthRegex, temp, lineNumber)) {
            seas.push_back(temp);
        }
        ++lineNumber;
    }
    return seas;
}
