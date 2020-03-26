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
  //GenStack<char> stack(50); //initialize GenStack to 50
  GenStack<char> delimiters(50);
  GenStack<int> lineCount(50);
  lineNumber = 1;
  inputFile.open(fName);
  //while loop to read the file
  char charFile = ' ';
  while(!inputFile.eof()){

    inputFile >> fileInfo;
    //cout<< fileInfo<<endl;


      for(int i = 0; i < fileInfo.length(); ++i){
        charFile = fileInfo[i];
        cout<< charFile<<endl;

      }


      switch (charFile) {
        case '{':
					delimiters.push('{');
					lineCount.push(lineNumber);
          cout<< "char is a { pushed to stack" <<endl;
          cout<< "peeking: "<<delimiters.peek()<<endl;
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


      ++lineNumber;
    }
      cout<< "end of line"<<endl;


    //return fileInfo;


  inputFile.close();

}
