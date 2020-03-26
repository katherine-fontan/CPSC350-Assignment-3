#include "Delimiter.h"
#include <iostream>


Delimiter:: Delimiter(){}

Delimiter:: ~Delimiter(){}


void Delimiter:: delimiterChecker(string fName){
  //string fname = "test.cpp";
  file = new FileIO(fName);
  cout<<"starting checker";
  char c;

  GenStack<char> delimiters(50);
  GenStack<int> lineCount(50);

  int lineNumber = 1;

  while(!file->inputFile.eof()){

    for(int i = 0; i < file->fileInfo.length(); ++i){
      c = file->readFile();

      cout<< c << endl;
      switch (c) {
        case '{':
					delimiters.push('{');
					lineCount.push(lineNumber);
					break;
				case '[':
					delimiters.push('[');
					lineCount.push(lineNumber);
					break;
				case '(':
					delimiters.push('(');
					lineCount.push(lineNumber);
					break;
      }
    }

    if(file->inputFile.eof()){
      cout<< "the end"<<endl;
      break;
    }


    ++lineNumber;
  }




}
