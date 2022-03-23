#ifndef ROLL_H_
#define ROLL_H_

#include <string>
#include <regex>

namespace roll {

  using namespace std;

  class Roll {
  public:
    // throwing invalid_argument if the roll is not well formatted
    Roll(string);
    int roll();
    int getMinVal();
    int getMaxVal();
    static bool goodRollStr(string);
  private:
    string rollStr;
    int minVal;
    int maxVal;
  };

}
#endif
