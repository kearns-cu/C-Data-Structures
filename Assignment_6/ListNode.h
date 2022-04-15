/**
 * @file ListNode.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for a list node structure
 */
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

/**
 * template <class T> class ListNode
 * @brief template class for a list node
 * @return n/a
 * @param n/a
 */
template <class T>
class ListNode{
  public:
    T *data;
    ListNode *next;
    ListNode *prev;

    ListNode();
    ListNode(T *d);
    ~ListNode();
};

/**
 * ListNode<T>::ListNode()
 * @brief default list node constructor
 * @return n/a
 * @param n/a
 */
template <class T>
ListNode<T>::ListNode(){}

/**
 * ListNode<T>::ListNode(T *d)
 * @brief overloaded list node constructor
 * @return n/a
 * @param T *d
 */
template <class T>
ListNode<T>::ListNode(T *d){
  data = d;
  next = NULL;
  prev = NULL;
}

/**
 * ListNode<T>::~ListNode()
 * @brief list node default destructor
 * @return n/a
 * @param  n/a
 */
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}
#endif
