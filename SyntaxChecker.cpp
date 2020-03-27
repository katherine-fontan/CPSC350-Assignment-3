#include <iostream>
#include "SyntaxChecker.h"
using namespace std;


SyntaxChecker::SyntaxChecker(string fileName){

  fName = fileName;
}
SyntaxChecker:: ~SyntaxChecker(){

}

void SyntaxChecker:: analyzeFile(){
  cout<< "\nAnalizing "<< fName << "..."<<endl;

  GenStack<char> delimiters(10);
  GenStack<int> lineTracker(10);
  lineNumber = 1;
  inputFile.open(fName);
  //while loop to read the file

  while(!inputFile.eof()){
    char charFile;

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
              cout<< "Error found: \n-Line "<< lineNumber<<": no match for }" << endl;
              exit(0);
            }
            else if(delimiters.peak() != '{'){

              if(lineTracker.peak() != lineNumber){
                if(delimiters.peak()== '('){
                  cout<< "Error found: \n-Line "<<lineTracker.peak()<< ": missing )"<< endl;
                  exit(0);
                }
                else if (delimiters.peak() == '['){
                  cout<< "Error found: \n-Line "<<lineTracker.peak()<< ": missing ]"<< endl;
                  exit(0);
                }


              }
              else{
                if(delimiters.peak()== '['){
                  cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where ] should be." << endl;
                  exit(0);
                }
                else if (delimiters.peak() == '('){
                  cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where ) should be." << endl;
                  exit(0);
                }
              }
            }
            else if (delimiters.peak() == '{') {

								delimiters.pop();
								lineTracker.pop();
						}

  					break;

          case ']':
            if(delimiters.isEmpty()){
              cout<< "Error found: \n-Line "<< lineNumber<<": no match for ]" << endl;
              exit(0);
            }
            else if(delimiters.peak() != '['){

              if(lineTracker.peak() != lineNumber){
                if(delimiters.peak()== '{'){
                  cout<< "Error found: \n-Line "<<lineNumber<< ": missing }"<< endl; // or lineTracker.peak()
                  exit(0);
                }
                else if (delimiters.peak() == '('){
                  cout<< "Error found: \n-Line "<<lineTracker.peak()<< ": missing )"<< endl;
                  exit(0);
                }
              }
              else{
                if(delimiters.peak()== '{'){
                  cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where } should be." << endl;
                  exit(0);
                }
                else if (delimiters.peak() == '('){
                  cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where ) should be." << endl;
                  exit(0);
                }
              }
            }
            else if (delimiters.peak() == '[') {

								delimiters.pop();
								lineTracker.pop();

						}
            break;

          case ')':
              if(delimiters.isEmpty()){
                cout<< "Error found: \n-Line "<< lineNumber<<": no match for )" << endl;
                exit(0);
              }
              else if(delimiters.peak() != '('){

                if(lineTracker.peak() != lineNumber){

                   if(delimiters.peak()== '{'){
                      cout<< "Error found: \n-Line "<<lineTracker.peak()<< ": missing }"<< endl;
                      exit(0);
                    }
                    else if (delimiters.peak() == '['){
                      cout<< "Error found: \n-Line "<<lineTracker.peak()<< ": missing ]"<< endl;
                      exit(0);
                    }
                }
                else{
                  if(delimiters.peak()== '{'){
                    cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where } should be." << endl;
                    exit(0);
                  }
                  else if (delimiters.peak() == '['){
                    cout<< "Error found: \n-Line "<< lineNumber<<": "<< charFile<< " where ) should be." << endl;
                    exit(0);
                  }
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
					cout << "Error found: \n-Reached end of file. Missing a }" << endl;
				}
				else if(delimiters.peak() == '(') {
					cout << "Error found: \n-Line "<< lineTracker.peak()<<": unaccompanied (" << endl;
				}
				else if(delimiters.peak() == '{') {
          cout << "Error found: \n-Line "<< lineTracker.peak()<<": unaccompanied {" << endl;
				}
				exit(0);
			}
		}


  inputFile.close();
}//end of function
