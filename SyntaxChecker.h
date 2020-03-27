#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class SyntaxChecker{

  public:

    SyntaxChecker(){}
    SyntaxChecker(string fileName);

    ~SyntaxChecker();

    void analyzeFile(); //function to read file from command line input.

    string fName;
    fstream inputFile;
    string fileInfo;
    int lineNumber;




};
