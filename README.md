# CPSC350-Assignment-3
Delimiters


Katherine Fontan
2290561
luzfonta@chapman.edu

Write a C++ program that uses a stack to analyze source code written in any language (C, C++, Lisp...you name it) and report the location of any mismatched delimiters.
- Stack should be generic i.e can run with any data type.
  - should allocate more room for itself
- program should take the name of a file as a command line argument
  - find one error at a time
    - errors should specify line or end of file.
  - if there are no errors, it should prompt the user for another file,




Websites used for help:
- For GenStack template implementation:
https://www.techiedelight.com/stack-implementation-using-templates/
https://www.geeksforgeeks.org/generics-in-c/
Notes from class + stack example

- throw exceptions info
https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm

- for delimiters
https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
https://gist.github.com/mycodeschool/7207410
https://www.includehelp.com/data-structure-tutorial/check-for-balanced-parentheses-by-using-stacks-cpp-program.aspx



To run: there is a makefile, or you can run by using g++ *.cpp && ./a.out fileName
