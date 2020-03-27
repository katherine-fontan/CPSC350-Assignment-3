#include <iostream>
#include "SyntaxChecker.h"
using namespace std;


SyntaxChecker::SyntaxChecker(string fileName){

  fName = fileName;
}
SyntaxChecker:: ~SyntaxChecker(){

}

void SyntaxChecker:: analyzeFile(){
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

        if(charFile == '{'|| charFile == '['|| charFile == '('){
          delimiters.push(charFile);
          lineTracker.push(lineNumber);
        }




        switch (charFile) {

          case '}':
            //end of the file
            //check if stack is empty
            if(delimiters.isEmpty()){
              cout<< "Error"<< lineNumber<<", there is no match for your closing brace }" << endl;
              exit(0);
            }
            else if(delimiters.peak() != '{'){

              if(lineTracker.peak() != lineNumber){
                cout<< "Error in line " << lineTracker.peak() << ": Found "<< delimiters.peak() << " where { should be." << endl;
                exit(0);
              }
              else{
                cout<< "Error in line " << lineNumber << ": Found "<< delimiters.peak() << " where { should be." << endl;
                exit(0);

              }
            }
            else if (delimiters.peak() == '{') {

								delimiters.pop();
								lineTracker.pop();
						}

  					break;

          case ']':
            if(delimiters.isEmpty()){
              cout<< "Error"<< lineNumber<<", there is no match for your closing brace }" << endl;
              exit(0);
            }
            else if(delimiters.peak() != '['){

              if(lineTracker.peak() != lineNumber){
                cout<< "Error in line " << lineTracker.peak() << ": Found "<< delimiters.peak() << " where [ should be." << endl;
                exit(0);
              }
              else{
                cout<< "Error in line " << lineNumber << ": Found "<< delimiters.peak() << " where [ should be." << endl;
                exit(0);
              }
            }
            else if (delimiters.peak() == '[') {

								delimiters.pop();
								lineTracker.pop();

						}
            break;

          case ')':
              if(delimiters.isEmpty()){
                cout<< "Error"<< lineNumber<<", there is no match for your closing brace }" << endl;
                exit(0);
              }
              else if(delimiters.peak() != '('){

                if(lineTracker.peak() != lineNumber){
                  cout<< "Error in line " << lineTracker.peak() << ": Found "<< delimiters.peak() << " where [ should be." << endl;
                  exit(0);
                }
                else{
                  cout<< "Error in line " << lineNumber << ": Found "<< delimiters.peak() << " where [ should be." << endl;
                  exit(0);
                }
              }
              else if (delimiters.peak() == '(') {
                  delimiters.pop();
                  lineTracker.pop();


            }
            break;




        }//end of switch statement
    }//end of for loop
    ++lineNumber;
  }//end lof while loop

  if(inputFile.eof()) {
			if(!delimiters.isEmpty()) {
				if (delimiters.peak() == '{') {
					cout << "Reached end of file. Missing a }" << endl;
				}
				else if(delimiters.peak() == '(') {
					cout << "Unaccompanied ( at line: " << lineTracker.peak() << endl;
				}
				else if(delimiters.peak() == '[') {
					cout << "Unaccompanied [ at line: " << lineTracker.peak() << endl;
				}
				exit(0);
			}
		}


  inputFile.close();
}//end of function
