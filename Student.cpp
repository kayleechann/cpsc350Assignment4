#include <iostream>
#include "Student.h"

using namespace std;

//default constructor
Student::Student(){
  m_timeNeeded = 0;
  m_waitTime = 0;
  m_arriveTime = -1; //clock tick is set to -1 to show that there is no student at the window
}

//overloaded constructor that takes the clock tick and time they need at a window as parameters
Student::Student(int arriveTime, int timeNeed){
  m_arriveTime = arriveTime;
  m_timeNeeded = timeNeed;
  m_waitTime = 0;
}

Student::~Student(){
  //destructor
}

//method to decrement time at window
void Student::decTime(){
  m_timeNeeded--;
}

//method to increase studnet wait time in line
void Student::incWaitTime(){
  m_waitTime++;
}

//method to print a Student's attributes
void Student::printStudent(){
  cout << "clock tick-- " << m_arriveTime << "      time needed at window-- " << m_timeNeeded << endl;
}
