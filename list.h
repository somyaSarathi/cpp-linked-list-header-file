#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif

#ifndef COLOR_H
#define COLOR_H

#include "color.h"

#endif

#ifndef LIST_H
#define LIST_H

// declaring node
template <typename T>
struct Node {
  T data;
  Node<T>* next = NULL;
};


// creating a data type.
// e.g. list l, "l" is a data kinda data type here.
template <class T>
class list {
private:

  Node <T>* root;
  int length = 0;

public:

  list() {
    root = new Node <T>;
  }

  bool isempty(); // changed to is empty
  void push(T value);
  void append(T value);
  void pop();
  void insert(T value, int position);
  void del(int position);
  void len();
  void print();
};


// to check whether the list is emplty
template <typename T>
bool list <T>::isempty() {
  if (list::root -> next == NULL)  return true;
  return false;
}


// to insert a node at top.
template <typename T>
void list <T>::push(T value) {

  // allocate new node
  Node <T>* current = new Node <T>;
  current->data = value;

  // the new node is inserted after the empty head
  // because head is an empty node in your implementation:
  current->next = list::root->next;
  list::root->next = current;

  list::length ++;
  return;
}

// to insert a node at the end.
template <typename T>
void list <T>::append(T value) {

  // alloacte new node
  Node <T>* current = new Node <T>;
  current->data = value;
  
  // if list is empty
  if (list::root == NULL) {
    current->next = list::root->next;
    list::root->next = current;

    list::length ++;
    return;
  }

  Node <T>* temp = root;
  
  // till the last node
  for (int i = 0; i < list::length; i ++) temp = temp->next;
  
  temp->next = current;
  list::length ++;
  return;
}


// to delete last element
template <typename T>
void list <T>::pop() {
  // allocate a new node and assign it last node of linked list
  Node <T>* new_node = new Node <T>;
  new_node = list::root;

  // delete the new node.
  // root is the next node.
  root = root->next;
  delete(new_node);

  list::length --;
}


template <typename T>
void list <T>::insert(T value, int position) {

  Node <T>* current = new Node<T>;
  current->data = value;

  Node <T>* temp = list::root;

  // invalid position
  if (position > (list::length + 1) || position < 0) {
    std::cout << RED << "error:" << RESET << "Node cannot be inserted at the requested positon" << std::endl;
    std::cout << "Try inserting node between" << GREEN << " 0 - " << length << RESET << std::endl;
    exit (1);
  }

  else if (position == 0) {
    current->next = list::root->next;
    list::root->next = current;
  }

  else {
    // derired position - 1
    for (int i = 0; i < position; i ++) temp = temp->next;
    
    current->next = temp->next;
    temp->next = current;
  }
  
  list::length ++;
  return;
}


// to delete node at certain position
template <typename T>
void list <T>::del(int position) {

  Node <T>* temp = root;
  Node <T>* current;

  if (position > list::length || position < 0) {
    std::cout << RED <<"error:" << RESET <<" No node exit exist at the requested position" << std::endl;
    exit (1);
  }

  else {
    for (int i = 0; i < position; i ++) temp = temp->next;

    current = temp->next;
    temp->next = current->next;
    delete (current);
  }

  list::length --;
}


// to print length of linked list.
template <typename T>
void list <T>::len() {
  std::cout << list::length << std::endl;
}


// to print all elements.
template <typename T>
void list <T>::print() {

  Node <T>* temp = list::root->next;

  // until the last element.
  // as last element don't stores address of any further node.
  while (temp != NULL) {

    // if it's the last element.
    if (temp->next == NULL) {
      std::cout << temp->data << std::endl;
      return;
    }

    else {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
  }
  return;
}

#endif