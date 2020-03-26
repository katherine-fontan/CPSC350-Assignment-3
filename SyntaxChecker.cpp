#include <iostream>
#include "SyntaxChecker.h"
using namespace std;


SyntaxChecker::SyntaxChecker(string fileName){

  fName = fileName;
}
SyntaxChecker:: ~SyntaxChecker(){

}

char SyntaxChecker:: analyzeFile(){
  cout<< "starting to read file"<<endl;

  GenStack<char> delimiters(10);
  GenStack<int> lineTracker(10);
  lineNumber = 1;
  inputFile.open(fName);
  //while loop to read the file
  char charFile = ' ';
  while(!inputFile.eof()){

    inputFile >> fileInfo;
    //cout<< fileInfo<<endl;


      for(int i = 0; i < fileInfo.length(); ++i){
        charFile = fileInfo[i];
        //cout<< charFile<<endl;

        switch (charFile) {
          case '{':
  					delimiters.push('{');
  					lineTracker.push(lineNumber);
  					break;
  				case '[':
  					delimiters.push('[');
  					lineTracker.push(lineNumber);
  					break;
  				case '(':
  					delimiters.push('(');
  					lineTracker.push(lineNumber);
  					break;

          case '}':
            //end of the file
            //check if stack is empty
            if(delimiters.isEmpty()){
              cout<< "Error in line: "<< lineNumber<<", there is no match for your closing brace }" << endl;
              exit(0);
            }
  					break;

        }//end of switch statement
      ++lineNumber;
    }//end of for loop
  }//end lof while loop
  inputFile.close();
}//end of function
