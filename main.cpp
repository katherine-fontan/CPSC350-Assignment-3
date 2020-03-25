#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{


  GenStack<char> arr(50);

  arr.push('R');
  arr.push('e');
  arr.push('n');
  arr.push('e');


  return 0;
}
