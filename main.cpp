#include "SyntaxChecker.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{

  if(argc < 2){
    cout<< "Invalid command line parameters!" <<endl;
    return 1;
  }

  string fName = argv[1];
  string userChoice = "y";


  while(userChoice == "y"){

    SyntaxChecker* analyzer = new SyntaxChecker(fName);
    analyzer->analyzeFile();

    cout << "There are no delimiter errors in this file. Want to analyze another file (y or n)? ";
    cin >> userChoice;

    if(userChoice == "y"){
      cout<< "What is the file name? ";
      cin >> fName;
    }

    delete analyzer;
  }
  cout << "bye then!" <<endl;


  return 0;
}
