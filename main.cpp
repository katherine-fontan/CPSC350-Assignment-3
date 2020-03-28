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
  string userChoice = "yes";


  while(userChoice == "yes"){

    SyntaxChecker* analyzer = new SyntaxChecker(fName);
    analyzer->analyzeFile();

    cout << "There are no delimiter errors in this file!\nWant to analyze another file (yes or no)?  ";
    cin >> userChoice;


    if(userChoice == "yes"){
      cout<< "What is the file name? ";
      cin >> fName;
    }

    delete analyzer;
  }
  cout << "Bye then :)" <<endl;


  return 0;
}
