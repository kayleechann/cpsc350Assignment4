#include <iostream>

using namespace std;

class Student{
public:
  //main methods
  Student();
  Student(int timeArrive, int waitTime);
  ~Student();
  void decTime(); 
  void printStudent();
  void incWaitTime();

  //attributes
  int m_timeNeeded;
  int m_waitTime;
  int m_arriveTime;
};
