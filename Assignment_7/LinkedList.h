/**
 * @file LinkedList.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for a doubly linked list structure
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string.h>
#include "List.h"
using namespace std;

/**
 * template <typename T> class ListNode
 * @brief template class for a list node
 * @return n/a
 * @param n/a
 */
template <typename T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode *next;
    ListNode *prev;
    T data;
};

template <typename T>
ListNode<T>::ListNode()
{
}

template <typename T>
ListNode<T>::ListNode(T d)
{
  next = nullptr;
  prev = nullptr;
  data = d;
}

template <typename T>
ListNode<T>::~ListNode()
{
  next = nullptr;
  prev = nullptr;
}

/**
 * template <typename T> class DoublyLinkedList : List<T>
 * @brief template class for a doubly linked list
 * @return n/a
 * @param n/a
 */
template <typename T>
class DoublyLinkedList : List<T>{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  virtual void insertFront(T d);
  virtual void insertBack(T d);
  virtual T removeFront();
  virtual T removeBack();
  virtual T remove(T key);
  virtual int find(T value);
  virtual string toString();
  virtual void printList();
  virtual void printReverseList();
  virtual bool isEmpty();
  virtual int getSize();
  virtual T getFront();
  virtual T getBack();
private:
  ListNode<T> *front;
  ListNode<T> *back;
  int size;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  while (front != nullptr)
  {
    ListNode<T> *temp = new ListNode<T>();
    temp = front;
    front = front->next;
    delete temp;
  }
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if (size == 0)
  {
    back = node;
  }
  else
  {
    //not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if (size == 0)
  {
    front = node;
  }
  else
  {
    //not an empty list
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <typename T>
T DoublyLinkedList<T>::removeFront()
{
  //check if empty
  ListNode<T> *tp = front;

  if (front->next == NULL)
  {
    back = NULL;
  }
  else
  {
    //size > 1
    front->next->prev = NULL;
  }
  front = front->next;
  tp->next = 0;
  T temp = tp->data;
  size--;
  delete tp;

  return temp;
}

template <typename T>
T DoublyLinkedList<T>::removeBack()
{
  //check if isEmpty
  ListNode<T> *tp = back;
  if (back->prev == NULL)
  {
    front = NULL;
  }
  else
  {
    back->prev->next = NULL;
  }
  back = back->prev;
  tp->prev = 0;
  T temp = tp->data;
  size--;
  delete tp;

  return temp;
}

template <typename T>
int DoublyLinkedList<T>::find(T value)
{
  int idx = -1;
  ListNode<T> *current = front;

  while(current != NULL)
  {
    ++idx;
    if (current->data == value)
    {
      break;
    }
    else
    {
      current = current->next;
    }
    if (current == 0)
    {
      idx = -1;
    }
    return idx;
  }
  return idx;
}

template <typename T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T> *current = front;
  while(current != NULL)
  {
    cout << current->data << endl;
    current = current->next;
  }
}

template <typename T>
string DoublyLinkedList<T>::toString()
{
  string result = "";
  ListNode<T> *current = front;
  while(current != NULL)
  {
    result = result + current->data.toString();
    current = current->next;
  }
  return result;
}

template <typename T>
void DoublyLinkedList<T>::printReverseList()
{
  ListNode<T> *current = back;
  while(current != NULL)
  {
    cout << current;
    current = current->prev;
  }
}

template <typename T>
T DoublyLinkedList<T>::remove(T key)
{
  //check if isEmpty
  if (isEmpty())
  {
    return key;
  }
  //leverage find method
  ListNode<T> *current = front;

  while(current->data != key)
  {
    if(current->next == NULL)
    {
      return key;
    }
    current = current->next;
  }
  //we found the data now we remove it
  if (current == front)
  {
    front = current->next;
    if(front != NULL)
    {
      front->prev = NULL;
    }
  }
  if (current == back)
  {
    back = current->prev;
    if(back != NULL)
    {
      back->next = NULL;
    }
  }
  if  (current != front && current != back && front != NULL && back != NULL)
  {
    //listnode is between front and insertBack
    current->next->prev = current->prev;
    current->prev->next = current->next;
  }
  current->next = NULL;
  current->prev = NULL;
  T temp = current->data;
  size--;
  delete current;
  return temp;
}

template <typename T>
int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
  return size == 0;
}

template <typename T>
T DoublyLinkedList<T>::getFront()
{
  return front->data;
}

template <typename T>
T DoublyLinkedList<T>::getBack()
{
  return back->data;
}

#endif
