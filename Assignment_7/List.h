/**
 * @file List.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for a list, extended by the linked list
 */

#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <typename T>
class List
{
  public:

    virtual void insertFront(T d) = 0;
    virtual void insertBack(T d) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual T remove(T key) = 0;
    virtual int find(T value) = 0;
    virtual void printList() = 0;
    virtual void printReverseList() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual T getFront() = 0;
    virtual T getBack() = 0;
};

#endif
