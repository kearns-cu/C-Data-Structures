/**
 * @file GenQueue.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for GenQueue structure
 */

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

/**
 * template <class E> class GenQueue
 * @brief template class for a generic queue
 * @return n/a
 * @param n/a
 */
template <class E>
class GenQueue{
  public:
    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();

    void insert(E *d);
    E* remove();
    E* peek();
    bool isEmpty();
    int getSize();

    int front;
    int rear;
    int numElements;

    DoublyLinkedList<E> *myQueue;
};

/**
 * GenQueue<E>::GenQueue()
 * @brief default queue constructor
 * @return n/a
 * @param n/a
 */
template <class E>
GenQueue<E>::GenQueue(){
  myQueue = new DoublyLinkedList<E>();
  numElements = 0;
  front = 0;
  rear = -1;
}

/**
 * GenQueue<E>::GenQueue(maxSize)
 * @brief overloaded queue constructor
 * @return n/a
 * @param n/a
 */
template<class E>
GenQueue<E>::GenQueue(int maxSize){
  myQueue = new DoublyLinkedList<E>();
  numElements = 0;
  front = 0;
  rear = -1;
}

/**
 * GenQueue<E>::~GenQueue()
 * @brief queue destructor
 * @return n/a
 * @param n/a
 */
template<class E>
GenQueue<E>::~GenQueue(){
  delete [] myQueue;
}

/**
 * void GenQueue<E>::insert(E *d)
 * @brief inserts element at the rear of the queue
 * @return void
 * @param E *d
 */
template<class E>
void GenQueue<E>::insert(E *d){

  myQueue->insertBack(d);
  numElements++;
}

/**
 * E* GenQueue<E>::remove()
 * @brief removes element at the front of the queue
 * @return E*
 * @param n/a
 */
template<class E>
E* GenQueue<E>::remove(){

  numElements--;
  return myQueue->removeFront();
}

/**
 * E* GenQueue<E>::peek()
 * @brief peeks element at beginning of queue
 * @return E*
 * @param n/a
 */
template<class E>
E* GenQueue<E>::peek(){
  return myQueue->peek();
}

/**
 * bool GenQueue<E>::isEmpty()
 * @brief returns whether queue is empty or not
 * @return bool
 * @param n/a
 */
template<class E>
bool GenQueue<E>::isEmpty(){
  if(numElements == 0){
    return true;
  }
  else{
    return false;
  }
}

/**
 * int GenQueue<E>::getSize()
 * @brief returns the size of the queue
 * @return bool
 * @param n/a
 */
template<class E>
int GenQueue<E>::getSize(){
  return numElements;
}
#endif
