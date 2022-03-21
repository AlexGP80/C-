#include <iostream>
#include "Characteristic.h"
#include "Roll.h"

int main(int, char **){
  Characteristic ch("puto", 13, 18, 13);

  if (Roll::goodRollStr("1d6"))
    cout << "1d6 ok" << endl;
  else
    cout << "1d6 cagada" << endl;

  if (Roll::goodRollStr("0d6"))
    cout << "0d6 cagada" << endl;
  else
    cout << "0d6 ok" << endl;

  //TODO: Herramienta para tests unitarios en C++

  return 0;
}
