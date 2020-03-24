#include "GenStack.h"

//class implementation

template <typename T>
void GenStack<T>::push(T data){

  //always check if its full before attempting to push/insert
  if(isFull()){
    //double size of stack
  }
  //assuming its not isFull
  stackArray[++top] = data;
}
template <typename T>
T GenStack<T>::pop(){
  //chekc if empty before attempting to remove
  return stackArray[top--];
}
template <typename T>
T GenStack<T>::peek(){
  return stackArray[top];
}
template <typename T>
bool GenStack<T>::isFull(){
  return (top == size-1);
}
template <typename T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template<typename T>
void GenStack<T>:: memoryAllocator(){
  size *= 2; //this would double the size of the array
  newStackArray = new T[size];

  for(int i=0; i<=top; ++i){
    newStackArray[i] = stackArray[i];
  }
  stackArray = newStackArray;
}
