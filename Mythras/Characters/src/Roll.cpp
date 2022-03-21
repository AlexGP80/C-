#include "Roll.h"

Roll::Roll(string rollStr)
  :rollStr{rollStr}, minVal{0}, maxVal{0} {
    // 1. Check if rollStr conforms to a good roll format
}

bool Roll::goodRollStr(string rollStr) {
  // 1d4, 17d6, 2d4+3d6, 5d3+4, 3d3+4d2-2...
  regex strExpr ("[1-9][0-9]*(d[1-9][0-9]*)?([\\+\\-][1-9][0-9]*(d[1-9][0-9]*)?)*");
  if (regex_match(rollStr, strExpr))
    return true;
  return false;
}
