#include "FileIO.h"
#include<fstream>
#include<iostream>

class Delimiter{

  public:
    //FileIO object

    Delimiter();
    ~Delimiter();

    void delimiterChecker(string fName);

    FileIO *file;
    int lineNumber;

};
