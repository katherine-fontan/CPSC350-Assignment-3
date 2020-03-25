#include <iostream>
using namespace std;

template <typename T>
class GenStack
{

  int top;
  int size;

  T *stackArray;
  T *newStackArray;
  public:
    GenStack(); //default constructor
    GenStack (int maxSize); //overloaded constructor
    ~GenStack(){
      delete[] stackArray;
    }; //destructor

    //core functions
    void push(T data); //insert an item
    void memoryAllocator();
    T pop(); //remove

    //aux/helper funcitons
    T peek(); //AKA top
    bool isEmpty();
    bool isFull();


     //represent the memory address of the first block of this array.
    //Because then we know that everythign else is gonna be one byte over

};
