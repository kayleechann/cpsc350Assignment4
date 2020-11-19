#include <fstream>
#include <array>
#include <bits/stdc++.h>
#include "Registrar.h"

//default constructor --> instantiate lists/arrays/queue
Registrar::Registrar(){
  numWindowsOpen = 0;
  waitTimesList = new DoublyLinkedList<int>();
}

//destructor
Registrar::~Registrar(){
  delete [] windowList;
  delete waitTimesList;
}

//method to parse file and get all relevant information
bool Registrar::parseFile(string file){
  ifstream readFile;
  readFile.open(file, ios::in);
  readFile >> numAllWindows;
  windowList = new Window*[numAllWindows];
  for(int i = 0; i < numAllWindows; ++i){
    Window* w = new Window();
    windowList[i] = w;
  }
    readFile >> clockTick;
    int numStudents;
    readFile >> numStudents;
    for(int i = 0; i < numStudents; ++i){
      int timeSNeed =  0;
      readFile >> timeSNeed;
      Student* s = new Student(clockTick, timeSNeed);
      myQueue.enqueue(s);
    }
  return true;
}

//returns t/f is windows are empty
bool Registrar::allWindowsEmpty(){
  int allAreEmpty = 0;
  for(int i = 0; i < sizeOfWindowList(); ++i){
    if(windowList[i]->currStudent->m_arriveTime == -1){
      allAreEmpty++;
    }
  }
  if(allAreEmpty == sizeOfWindowList()){
    return true;
  }else{
    return false;
  }
}

//returns size of list holding windows
int Registrar::sizeOfWindowList(){
  return numAllWindows;
}

//updates all idle times of windows
void Registrar::updateAllIdleTime(){
  for(int i = 0; i < sizeOfWindowList(); ++i){
    windowList[i]->addIdleTime();
  }
}

//updates wait times of student in line
void Registrar::updateWaitTime(){
  if(!myQueue.isEmpty()){
    ListNode<Student*> *curr = myQueue.front;
    while(curr != NULL){
      curr->data->m_waitTime += 1;
      curr = curr->next;
    }
  }
}

//calculates mean student wait time
double Registrar::mean(){
  ListNode<int> *curr = waitTimesList->front;
  double meanNum = 0;
  double sum = 0;
  int counter = 0;

  if(curr == NULL){
    return 0;
  }else{
    while(curr != NULL){
      sum += curr->data;
      //if student has a wait time of 0 --> don't count the studnet when averaging the mean
      if(curr->data != 0){
        counter++;
      }
      curr = curr->next;
    }
  }
  if(sum == 0 && counter== 0){
    meanNum = 0;
  }else{
    meanNum = sum / counter;
  }
  return meanNum;
}

//method to calculate median
int Registrar::median(){
  ListNode<int> *curr = waitTimesList->front;
  int numStudentsInLine = 0;
  int median = 0;

  //loop to find number of elements in list so i can declare array
  while(curr != NULL){
    numStudentsInLine++;
    curr = curr->next;
  }

  //copy over elements from list so i can sort array and find median
  waitTimeArr = new int[numStudentsInLine];
  curr = waitTimesList->front;
  for(int i = 0; i <numStudentsInLine; ++i){
    waitTimeArr[i] = curr->data;
    curr = curr->next;
  }

  //sort() method was found in C++ STL
  int n = sizeof(waitTimeArr) / sizeof(waitTimeArr[0]);
  sort(waitTimeArr, waitTimeArr + n);

  //if array is odd
  if(numStudentsInLine % 2 == 1){
    median = waitTimeArr[numStudentsInLine/2];
  }else{     //if array is even --> average two numbers
    median = (waitTimeArr[numStudentsInLine/2] + waitTimeArr[(numStudentsInLine/2) - 1])/2;
  }
  return median;
}

//find longest student time
int Registrar::longestStudentTime(){
  int longestTime = 0;
  ListNode<int> *curr = waitTimesList->front;
  while(curr!=NULL){
    if(curr->data > longestTime){
      longestTime = curr->data;
    }
    curr = curr->next;
  }
  return longestTime;
}

//find number of students who waited more than 10 minutes
int Registrar::numStudOverTen(){
  int over10 = 0;
  ListNode<int> *curr = waitTimesList->front;
  while(curr != NULL){
    if(curr->data > 10){
      over10++;
    }
    curr = curr->next;
  }
  return over10;
}

//calculates mean window idle time
double Registrar::meanIdle(){
  double meanNum = 0;
  double sum = 0;
  int counter = sizeOfWindowList();

  for(int i = 0; i < sizeOfWindowList(); ++i){
    sum += windowList[i]->idleTime;
  }
  meanNum = sum/counter;
  return meanNum;
}

//calculates longest window time
int Registrar::longestWindowTime(){
  idleTimesList = new int[numAllWindows];

  for(int i = 0; i < numAllWindows; ++i){
    idleTimesList[i] = windowList[i]->idleTime;
  }
  int n = sizeof(idleTimesList) / sizeof(idleTimesList[0]);

  //sort() method taken from internet and from standard library
  sort(idleTimesList, idleTimesList + n);
  return (idleTimesList[numAllWindows-1]);
}

int Registrar::numWindOverFive(){
  int overFive = 0;

  for(int i = 0; i < numAllWindows; ++i){
    if(windowList[i]->idleTime > 5){
      overFive++;
    }
  }
  return overFive;
}
