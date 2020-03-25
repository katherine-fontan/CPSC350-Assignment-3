#include <iostream>
#include "FileIO.h"
using namespace std;


FileIO::FileIO(string fileName){

  fName = fileName;
}

void FileIO:: readFile(){

  GenStack<char> stack(50); //initialize GenStack to 50

  string fileInfo;

  //while loop to read the file

  while(!inputFile.eof()){

    if(inputFile.eof()){
      cout<< "End of file..."<< endl;
    }
    inputFile >> fileInfo;
    char charFile;

      for(int i = 0; i<fileInfo.length(); ++i){
        charFile = fileInfo[i];
      }
    //return charFile;
  }

  inputFile.close();


}
