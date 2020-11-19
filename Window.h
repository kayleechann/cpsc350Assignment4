#include <iostream>
#include "Student.h"

class Window{
public:
  //main methods
  Window();
  ~Window();
  bool windowIsOccupied();
  void addIdleTime();
  void printWindow();

  //attributes
  Student *currStudent; //Window holds a Student object
  int idleTime;
  bool isOccupied;
  int studentTimeNeeded;
};
