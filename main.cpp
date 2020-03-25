#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{


  GenStack<char> myStack(50);

  myStack.push('K');
  myStack.push('L');
  myStack.push('M');
  myStack.push('N');


  cout << "popping: "<< myStack.pop()<<endl;
  cout << "peek-a-boo: "<< myStack.peek()<<endl;

  myStack.push('F');
  cout<< "peek-a-boo: "<<myStack.peek()<<endl;

  while(!myStack.isEmpty()){
    cout<< myStack.pop()<<endl;
  }
  cout<< "is stack empty? " << myStack.isEmpty()<<endl;



  return 0;
}
