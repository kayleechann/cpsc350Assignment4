#include <iostream>
#include "ListNode.h"

template <typename T> //The templates - README for template reference
class DoublyLinkedList{
  private:

  public:
    ListNode<T> *front; //pointer to front node
    ListNode<T> *back; //pointer to back node
    unsigned int size;

    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T peek();
    T deletePos(T pos);
    int find(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
    T* get(int pos);
};

//defualt constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //research
}

//method for inserting node at front
template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //the list is now empty
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//method for inserting node at back
template <typename T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){//case check
    front = node;
  }else{
    //reassign pointers
    back->next = node;
    node->prev = back;
    ListNode<T> *prevback = back->prev;
    ListNode<T> *prevnode = node->prev;
    node->next = NULL;
  }
    back = node;
    size++;
  }

//method for removing front node
template <typename T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *ft = front;
  //case checking
  if(isEmpty()){
    return ft->data;
  }
  if(--size == 0){
    T thing = front->data;
    delete front;
    return thing;
  }
    //reassign pointers
  T temp = front->data;
  front = front->next;
  ft->next = NULL;
  ft = NULL;
  delete ft;
  return temp;
}

//method for removing back node
template <typename T>
T DoublyLinkedList<T>::removeBack(){
  if(isEmpty()){
    cout << "List already empty" << endl;
    T temp = 0;
    return temp;
  }else{
    ListNode<T> *nodeToDelete = back;

    if(front->next == NULL){
      //only one element in the list
      front = NULL;
    }else{
      //more than one element in the list
      back->prev->next = NULL;
    }
    back = back->prev;
    T temp = nodeToDelete->data;
    nodeToDelete->prev = NULL;
    delete nodeToDelete;
    size--;
    return temp;
  }
}

//peek() method used to return the front node's data
template <typename T>
T DoublyLinkedList<T>::peek(){
  return front->data;
}

//method used for deleting a node at a specified location
template <typename T>
T DoublyLinkedList<T>::deletePos(T pos){
  if(isEmpty()){
    cout << "List is already empty" << endl;
    return;
  }else{
    int p = 0;
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while (p != pos){
      prev = curr;
      curr = curr->next;
      p++;
    }

    //we found correct position, continue with renoval
    prev->next = curr->next;
    curr->next = NULL;
    int temp = curr->data;
    size--;

    delete curr;
    return temp;
  }
}

//method to find a node
template <typename T>
int DoublyLinkedList<T>::find(int d){
  int pos = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == d){
      break;
    }
    curr = curr->next;
  }

  if(curr == NULL){
    pos = -1;
  }
  return pos;
}

//returns true of false depending is list is empty or not
template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

//method to print contents of the list
template <typename T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//returns the size of linked list
template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

//returns the object at a specified position in the linked list 
template <typename T>
T* DoublyLinkedList<T>::get(int index){
  ListNode<T> *curr = front;
  int counter = 0;

  while(curr != NULL){
    if(counter == index){
      T *element = NULL;
      element = &curr->data;
      return element;
    }
    counter++;
    curr = curr->next;
  }
}
