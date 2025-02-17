#include <iostream>
#include "Window.h"

//default constructor
Window::Window(){
  currStudent = new Student();
  idleTime = 0;
  studentTimeNeeded = 0;
  isOccupied = false;
}

//destructor
Window::~Window(){
  delete currStudent;
}

//returns a boolean is window is occupied
bool Window::windowIsOccupied(){
  return isOccupied;
}

//adds one to idle time variable is window is idle
void Window::addIdleTime(){
  idleTime++;
}
