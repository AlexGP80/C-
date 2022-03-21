#ifndef CHARACTERISTIC_H_
#define CHARACTERISTIC_H_

#include <string>

using namespace std;

class Characteristic {
public:
  Characteristic(string cname, int original, int max, int current)
    :cname{cname}, original{original}, max{max}, current{current} {}
private:
  string cname;
  string roll;
  int original;
  int max;
  int current;
};

#endif
