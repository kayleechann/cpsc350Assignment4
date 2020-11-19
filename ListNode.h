/*
Kaylee Chan
2348244
kaychan@chapman.edu
CPSC 350-03
Assignment 4

This assignment utilizes a doubly linked list Queue to simulate the line at a  Registrar's office.
*/
#include <iostream>
using namespace std;

template <typename T>
class ListNode{
public:
  T data; //holds data
  ListNode *next; //pointer to next node
  ListNode *prev; //pointer to previous node

  ListNode();
  ListNode(T d);
  ~ListNode();

};

// default constructors
template <typename T>
ListNode<T>::ListNode(){
 data = NULL;
 next = NULL;
 prev = NULL;
}

//overloaded constructor
template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;

  delete next;
  delete prev;
}
