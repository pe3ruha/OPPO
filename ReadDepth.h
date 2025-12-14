#pragma once
#include "Sea.h"

bool ReadDepth(const string& line, const regex& depthRegex, Sea& temp, int lineNumber);