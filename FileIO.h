#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class FileIO{

  public:

    FileIO(){}
    FileIO(string fileName);

    ~FileIO();

    char readFile(); //function to read file from command line input.

    string fName;
    fstream inputFile;
    string fileInfo;
    int lineNumber;




};
