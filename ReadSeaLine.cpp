#include "ReadSeaLine.h"
#include "ReadName.h"
#include "ReadSalinity.h"
#include "ReadDepth.h"


bool ReadSeaLine(const string& line,const regex& nameRegex,const regex& salRegex,const regex& depthRegex,Sea& temp,int lineNumber) {
    return ReadName(line, nameRegex, temp, lineNumber) && ReadSalinity(line, salRegex, temp, lineNumber) && ReadDepth(line, depthRegex, temp, lineNumber);
}
