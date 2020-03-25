#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{


  GenStack<char> arr(50);

  arr.push('K');
  arr.push('L');
  arr.push('M');
  arr.push('N');


  return 0;
}
