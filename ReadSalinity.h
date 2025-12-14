#pragma once
#include "Sea.h"


bool ReadSalinity(const string& line, const regex& salRegex, Sea& temp, int lineNumber);