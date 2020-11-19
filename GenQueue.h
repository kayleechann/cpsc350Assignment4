#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class GenQueue{
public:
  DoublyLinkedList<T> *myQueue; //has linked list because queue is using it to implement it
  unsigned int size;
  ListNode<T> *front; //node at front of queue
  ListNode<T> *back; //node at back of queue

  GenQueue();
  ~GenQueue();

  void enqueue(T data);
  T dequeue();

  T getFront(); //peek()
  T getBack();
  void printQueue();
  unsigned int getSize();
  bool isEmpty();
  T* get(int pos);
};

//default constructor
template <typename T>
GenQueue<T>::GenQueue(){
  myQueue = new DoublyLinkedList<T>();
}

//destructor
template <typename T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

//method to insert at the back of queue --> implements DoublyLinkedList's insertBack() method
template <typename T>
void GenQueue<T>::enqueue(T data){
  myQueue->insertBack(data);
}

//method to remove from queue --> implements DoublyLinkedList's removeFront() method
template <typename T>
T GenQueue<T>::dequeue(){
  myQueue->removeFront();
}

//method that returns the data at the top of the queue --> implements DoublyLinkedList's peek() method
template <typename T>
T GenQueue<T>::getFront(){ //peek()
  return myQueue->peek();
}

//method to return data at back of queue
template <typename T>
T GenQueue<T>::getBack(){
  return myQueue->back;
}

//method to print all items in queue --> implements DoublyLinkedList's printList() method
template <typename T>
void GenQueue<T>::printQueue(){
  myQueue->printList();
}

//method to return size of queue
template <typename T>
unsigned int GenQueue<T>::getSize(){
  return myQueue->getSize();
}

//method returns a boolean (true/false) if queue is empty
template <typename T>
bool GenQueue<T>::isEmpty(){
  return myQueue->isEmpty();
}

//method that returns object at specified position
template <typename T>
T *GenQueue<T>::get(int index){
  return myQueue->get(index);
}
