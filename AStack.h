/**
 * @file AStack.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief implements a stack using an array
 */

#ifndef ASTACK_H
#define ASTACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * template<class A> class AStack
 * @brief template class for an array based stack
 * @return n/a
 * @param n/a
 */
template<class A>
class AStack{
private:
  A *arr;
  int size;
  int top;
  int elements;
public:
  AStack();
  AStack(int size);
  void push(A);
  A pop();
  bool isFull();
  bool isEmpty();
  A getTop();
  void resize();
};

/**
 * AStack<A>::AStack()
 * @brief default array stack constructor
 * @return n/a
 * @param n/a
 */
template <class A>
AStack<A>::AStack(){
  size = 5;
  top = -1;
  arr = new A[size];
}

/**
 * AStack<A>::AStack(int sz)
 * @brief overloaded array stack constructor
 * @return n/a
 * @param int sz
 */
template <class A>
AStack<A>::AStack(int sz){
  size = sz;
  top = -1;
  arr = new A[size];
}

/**
 * void AStack<A>::push(A item)
 * @brief takes an item and adds it to the array
 * @return void
 * @param A item
 */
template <class A>
void AStack<A>::push(A item){
  if(isFull()){
      resize();
  }
  elements++;
  top++;
  arr[top] = item;
}

/**
 * A AStack<A>::pop()
 * @brief takes an item off of the array and returns it
 * @return A
 * @param n/a
 */
template <class A>
A AStack<A>::pop(){
    if(isEmpty()){
        throw std::out_of_range("Cannot pop an empty stack");
    }
    int hold = top;
    --elements;
    --top;
    return arr[hold];
}

/**
 * bool AStack<A>::isFull()
 * @brief checkers and returns whether the array is full
 * @return bool
 * @param n/a
 */
template <class A>
bool AStack<A>::isFull(){
  return (top == size - 1);
}

template <class A>
bool AStack<A>::isEmpty(){
  return(top == -1);
}

template <class A>
A AStack<A>::getTop(){
    return top;
}

template <class A>
void AStack<A>::resize(){
    this->size *= 2;

    A* temp = new A[this->size];

    for(int i = 0; i < elements; i++){
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = new A[this->size];

    for(int k = 0; k < elements; k++){
      arr[k] = temp[k];
    }
    delete[] temp;
}



#endif
