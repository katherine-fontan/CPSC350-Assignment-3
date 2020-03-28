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
  lineNumber = 0;
  inputFile.open(fName);

  //to check if file exists
  if (!inputFile.is_open()) {
    cout << "Could not open file " << fName << endl;
    cout<< "New file "<<endl;
    cin>>fName;
    inputFile.open(fName);

  }

  //while loop to read the file

  while(inputFile >> fileInfo){//getline(inputFile,fileInfo
    //inputFile >> fileInfo;
    ++lineNumber; //increment right when the while loop starts because line number is address to start at 0
    //for some reason incrementing at the end of while loop wasn't working

    char charFile;

      for(int i = 0; i < fileInfo.length(); ++i){
        charFile = fileInfo[i];

       if(charFile == '{'|| charFile == '['|| charFile == '('){
          delimiters.push(charFile);
          lineTracker.push(lineNumber);

        }


        switch (charFile) {
          /*case '{':
            delimiters.push(charFile);
            lineTracker.push(lineNumber);
            cout<<"pushing {"<<endl;
            break;
          case '[':
            delimiters.push(charFile);
            lineTracker.push(lineNumber);
            cout<<"pushing ["<<endl;
            break;
          case '(':
            delimiters.push(charFile);
            lineTracker.push(lineNumber);
            cout<<"pushing ("<<endl;
            break;*/
          case '}':
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
            if(delimiters.peak() != '['){

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
   //++lineNumber;
  }//end of while loop

cout<< "reached the end of file"<< endl;
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
