#include <fstream>
#include <array>
#include <bits/stdc++.h>
#include "Registrar.h"

//default constructor --> instantiate lists/arrays/queue
Registrar::Registrar(){
  numWindowsOpen = 0;
  myQueue = new GenQueue<Student*>();
  waitTimesList = new DoublyLinkedList<int>();
}

//destructor
Registrar::~Registrar(){
  delete myQueue;
  delete [] windowList;
  delete waitTimesList;
}

//method to parse file and get all relevant information
bool Registrar::parseFile(string file){
  ifstream readFile;
  readFile.open(file, ios::in);
  readFile >> numAllWindows;
  //cout << "num windows: " << numAllWindows << endl;
  //cout << totalWindows << endl;
  windowList = new Window*[numAllWindows];
  for(int i = 0; i < numAllWindows; ++i){
    Window* w = new Window();
    //Student* tempStud = new Student();    //intitalize default students to fill array
    windowList[i] = w;
  }

  //while(!readFile.eof()){
    //read entire file and create all students and add to queue
    readFile >> clockTick;
    //cout << "ct: " << clockTick << endl;
    int numStudents;
    readFile >> numStudents;
    //cout << "num students: " << numStudents << endl;
    for(int i = 0; i < numStudents; ++i){
      int timeSNeed =  0;
      readFile >> timeSNeed;
      //cout << "time s need: " << timeSNeed << endl;
      //creates a student object
      Student* s = new Student(clockTick, timeSNeed);
      //s->printStudent();
      myQueue->enqueue(s);
    }
  //}
  //myQueue->printQueue();
  return true;
}

//returns t/f is windows are empty
bool Registrar::allWindowsEmpty(){
  int allAreEmpty = 0;
  //cout << sizeOfWindowList();
  for(int i = 0; i < sizeOfWindowList(); ++i){
    if(windowList[i]->currStudent->m_arriveTime == -1){
      allAreEmpty++;
    }
  }
  if(allAreEmpty == sizeOfWindowList()){
    //cout << "-------" << endl;
    return true;
  }else{
    //cout << "-------" << endl;
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

void Registrar::updateWaitTime(){
  // cout << "size of q " << myQueue->getSize() << endl;
  if(!myQueue->isEmpty()){
    cout << "print q" << endl;
    myQueue->printQueue();
    cout << "not empty!!!!!!!!!!!!!: " << endl;
    ListNode<Student*> *curr = myQueue->front;
    while(curr != NULL){
      curr->data->m_waitTime += 1;
      cout << "wait time: ****************" << curr->data->m_waitTime << endl;
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
      curr = curr->next;
      counter++;
    }
  }
  meanNum = sum / counter;
  return meanNum;
}

int Registrar::median(){

}

int Registrar::longestStudentTime(){

}

int Registrar::numStudOverTen(){

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
int Registrar::longestWindowTime(){ //not working for case 3 from slack
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
