#include <iostream>
#include "FileIO.h"
using namespace std;


FileIO::FileIO(string fileName){

  fName = fileName;
}
FileIO:: ~FileIO(){

}

char FileIO:: readFile(){
  cout<< "starting to read file"<<endl;
  GenStack<char> stack(50); //initialize GenStack to 50


  inputFile.open(fName);
  //while loop to read the file

  while(!inputFile.eof()){

    inputFile >> fileInfo;
    //cout<< fileInfo<<endl;
    char charFile;

      for(int i = 0; i < fileInfo.length(); ++i){
        charFile = fileInfo[i];
        cout<< charFile<<endl;

      }
      //cout<< "end of line"<<endl;


  }

  inputFile.close();


}
