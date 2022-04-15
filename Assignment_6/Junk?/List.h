#ifndef LIST_H
#define LIST_H

#include "DoublyLinkedList.h"

template<class T>
class List{
public:
  List();
  virtual ~List();
  virtual void insertFront(T data);
  virtual void insertBack(T data);
  virtual T removeFront();
  virtual T removeBack();
  virtual T removeAtPosition(int pos);
  virtual T remove(T value);

};

template<class T>
List<T>::List(){

}

template<class T>
List<T>::~List(){

}
#endif
