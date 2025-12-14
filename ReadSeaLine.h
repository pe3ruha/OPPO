#pragma once
#include "Sea.h"


bool ReadSeaLine(const string& line, const regex& nameRegex, const regex& salRegex, const regex& depthRegex, Sea& temp, int lineNumber);