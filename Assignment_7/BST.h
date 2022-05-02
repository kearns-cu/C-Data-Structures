/**
 * @file BST.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for a BST structure
 */

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
using namespace std;

/**
 * template<class T> class TreeNode
 * @brief template class for a node for a BST
 */
template<class T>
class TreeNode{
public:
  TreeNode();
  TreeNode(T k);
  virtual ~TreeNode();
  T key;
  TreeNode<T>* left;
  TreeNode<T>* right;
};

template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(T k){
  left = NULL;
  right = NULL;
  key = k;
};

template<class T>
TreeNode<T>::~TreeNode(){

}
/**
 * template<class T> class BST
 * @brief template class for a BST
 * @return n/a
 * @param n/a
 */
template<class T>
class BST{
private:
  TreeNode<T>* root;
  int size;

public:
  BST();
  virtual ~BST();
  bool contains(T value);
  T find(T value);
  void insert(T value);
  bool remove(T k);
  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  T getMin();
  T getMax();
  bool isEmpty();
  void inOrder(TreeNode<T>* node);
  void printTree();
  TreeNode<T>* getRoot();
  int length();
};

template<class T>
BST<T>::BST(){
  root = NULL;
  size = 0;
}

template<class T>
BST<T>::~BST(){

}

template<class T>
bool BST<T>::contains(T value){
  if (isEmpty())
  {
    return false;
  }
  else{
    TreeNode<T>* curr = root;

    while(curr->key != value){
      if (value < curr->key)
      {
        curr = curr->left;
      }
      else{
        curr = curr->right;
      }
      if(curr == NULL){
        return false;
      }
    }
  }
  return true;
}

template<class T>
T BST<T>::find(T value){
  if (isEmpty())
  {
    return value;
  }
  else{
    TreeNode<T>* curr = root;

    while(curr->key != value){
      if (value < curr->key)
      {
        curr = curr->left;
      }
      else{
        curr = curr->right;
      }
      if(curr == NULL){
        return value;
      }
    }
    value = curr->key;
  }
  return value;
}

template<class T>
void BST<T>::insert(T value){
  TreeNode<T>* node = new TreeNode<T>(value);
  if (isEmpty()){
    root = node;
  }
  else{
    TreeNode<T>* curr = root;
    TreeNode<T>* parent = NULL;

    while(true){
      parent = curr;

      if(value < curr->key){
        curr = curr->left;

        if(curr == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

template<class T>
bool BST<T>::remove(T k){
  if (isEmpty())
  {
    return false;
  }

  TreeNode<T>* parent = NULL;
  TreeNode<T>* curr = root;
  bool isLeft = true;

  while(curr->key != k)
  {
    parent = curr;

    if(k < curr->key)
    {
      isLeft = true;
      curr = curr->left;
    }
    else
    {
      isLeft = false;
      curr = curr->right;
    }

    if(curr == NULL)
    {
      return false;
    }
  }
  //Case: no children
  if(curr->left == NULL && curr->right == NULL)
  {
    if(curr == root)
    {
      delete root;
      root = NULL;
    }
    else if(isLeft)
    {
      parent->left = NULL;
      delete curr;
    }
    else
    {
      parent->right = NULL;
      delete curr;
    }
  }
  //Case: one child, left child
  else if (curr->right == NULL)
  {
    if(curr == root)
    {
      root = curr->left;
      delete curr;
    }
    else if (isLeft)
    {
      parent->left = curr->left;
      delete curr;
    }
    else
    {
      parent->right = curr->left;
      delete curr;
    }
  }
  //Case one child, right child
  else if(curr->left == NULL)
  {
    if (curr == root)
    {
      root = curr->right;
      delete curr;
    }
    else if (isLeft)
    {
      parent->left = curr->right;
      delete curr;
    }
    else
    {
      parent->right = curr->right;
      delete curr;
    }
  }
  //Case: Two children
  else
  {
    TreeNode<T>* successor = getSuccessor(curr);

    if(curr == root)
    {
      root = successor;
    }
    else if(isLeft)
    {
      TreeNode<T>* temp = parent;
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }
    successor->left = curr->left;
    delete curr;
  }
  size--;
  return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d){
  TreeNode<T>* sp = d;
  TreeNode<T>* successor = d;
  TreeNode<T>* curr = d->right;

  while(curr != NULL)
  {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template<class T>
T BST<T>::getMin(){
  if(isEmpty())
  {
    return 0;
  }
  TreeNode<T>* curr = root;

  while(curr->left != NULL){
    curr = curr->left;
  }

  return curr->key;
}

template<class T>
T BST<T>::getMax(){
  if(isEmpty())
  {
    return 0;
  }

  TreeNode<T>* curr = root;

  while(curr->right != NULL){
    curr = curr->right;
  }

  return curr->key;
}

template<class T>
void BST<T>::inOrder(TreeNode<T>* node){
  if(node == NULL)
  {
    return;
  }
  inOrder(node->left);
  cout << node->key << endl;
  inOrder(node->right);
}

template<class T>
void BST<T>::printTree(){
  inOrder(root);
}

template <typename T>
TreeNode<T>* BST<T>::getRoot(){
  return root;
}

template<class T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}

template <typename T>
int BST<T>::length(){
  return size;
}

#endif
