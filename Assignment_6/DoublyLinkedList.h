/**
 * @file DoublyLinkedList.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for DLL structure
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "ListNode.h"
#include <iostream>

using namespace std;

/**
 * template <class E> class DoublyLinkedList
 * @brief template class for a doubly linked list
 * @return n/a
 * @param n/a
 */
template <class E>
class DoublyLinkedList{
  private:
    ListNode<E> *front; //front node
    ListNode<E> *back; //rear node
    int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(E *d);
    void insertBack(E *d);
    E* removeFront();
    E* removeBack();
    E* peek();
    E* deletePos(E *pos);
    int find(E *d);
    bool isEmpty();
    void printList();
    int getSize();
};

/**
 * DoublyLinkedList<E>::DoublyLinkedList()
 * @brief default doubly linked list constructor
 * @return n/a
 * @param n/a
 */
template<class E>
DoublyLinkedList<E>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

/**
 * DoublyLinkedList<E>::~DoublyLinkedList()
 * @brief default doubly linked list destructor
 * @return n/a
 * @param n/a
 */
template<class E>
DoublyLinkedList<E>::~DoublyLinkedList(){
  while (front->next != front)
	{
		ListNode<E>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}

/**
 * void DoublyLinkedList<E>::insertFront(E *d)
 * @brief inserts item at the beginning of the list
 * @return void
 * @param E *d
 */
template<class E>
void DoublyLinkedList<E>::insertFront(E *d){
  ListNode<E> *node = new ListNode<E>(d);

  if(isEmpty()){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

/**
 * E* DoublyLinkedList<E>::removeFront()
 * @brief remove the item at the beginning of the list
 * @return E*
 * @param n/a
 */
template<class E>
E* DoublyLinkedList<E>::removeFront(){
  E *temp;
  if(isEmpty()){
    cout << "List empty" << endl;
  }
  else{
    ListNode<E> *ft = front;

    if(front->next == NULL){
      back = NULL;
    }
    else{
      front->next->prev = NULL;
    }
    front = front->next;
    temp = ft->data;
    ft->next = NULL;
    delete ft;
    size--;
  }
  return temp;
}

/**
 * E* DoublyLinkedList<E>::peek()
 * @brief returns the front element of the list
 * @return E*
 * @param n/a
 */
template<class E>
E* DoublyLinkedList<E>::peek(){
  if(isEmpty()){
    cout << "Linked List already empty" << endl;
  }
  else{
    return front->data;
  }
}

/**
 * void DoublyLinkedList<E>::insertBack(E *d)
 * @brief inserts an element at the rear, end, of the list
 * @return void
 * @param E *d
 */
template<class E>
void DoublyLinkedList<E>::insertBack(E *d){
  ListNode<E> *node = new ListNode<E>(d);

  if(isEmpty()){
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

/**
 * E* DoublyLinkedList<E>::removeBack()
 * @brief removes the element at the rear, end, of the list
 * @return E*
 * @param n/a
 */
template<class E>
E* DoublyLinkedList<E>::removeBack(){
  E *temp = new ListNode<E>;
  if(isEmpty()){
    cout << "List already empty" << endl;
  }
  else{
    ListNode<E> *bk = back;

    if(front->next == NULL){
      front = NULL;
    }
    else{
      back->prev->next = NULL;
    }
    back = back->prev;
    temp = bk->data;
    bk->prev = NULL;
    delete bk;
    size--;

  }
  return temp;
}

/**
 * E* DoublyLinkedList<E>::deletePos(E *d)
 * @brief removes the element given a pointer pointing to the same element
 * @return E*
 * @param E *d
 */
template<class E>
E* DoublyLinkedList<E>::deletePos(E *d){
  if(isEmpty()){
    cout << "List already empty" << endl;
  }
  else{
    ListNode<E> *curr = front;

    while(curr->data != d){
      curr = curr->next;

      if(curr == NULL){
        return NULL;
      }

      if(curr == front){
        front = curr->next;
      }
      else{
        curr->prev->next = curr->next;

      }
      if(curr == back){
        back = curr->prev;
      }
      else{
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;

    }
    return curr;
  }
}

/**
 * int DoublyLinkedList<E>::find(E *d)
 * @brief finds element in list given that element as a parameter
 * @return int
 * @param E *d
 */
template<class E>
int DoublyLinkedList<E>::find(E *d){
  if(isEmpty()){
    cout << "List already empty" << endl;
  }
  else{
    int idx = 0;
    ListNode<E> *curr = front;

    while(curr != NULL){
      if(curr->data == d){
        break;
      }
      else{
        curr = curr->next;
        idx++;
      }
    }

    if(curr == NULL){
      idx = -1;
    }
    return idx;
  }
}

/**
 * bool DoublyLinkedList<E>::isEmpty()
 * @brief checks whether list is empty
 * @return bool
 * @param n/a
 */
template<class E>
bool DoublyLinkedList<E>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

/**
 * void DoublyLinkedList<E>::printList()
 * @brief prints every element in the list
 * @return void
 * @param n/a
 */
template<class E>
void DoublyLinkedList<E>::printList(){
  ListNode<E> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

/**
 * int DoublyLinkedList<E>::getSize()
 * @brief gets size of the list
 * @return int
 * @param n/a
 */
template<class E>
int DoublyLinkedList<E>::getSize(){
  return size;
}
#endif
