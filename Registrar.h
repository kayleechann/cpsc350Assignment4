#include "Window.h"
#include "GenQueue.h"

class Registrar{
public:
  //main methods
  Registrar();
  ~Registrar();
  Registrar(int windowsOpen);
  bool parseFile(string file);
  int sizeOfWindowList();
  void updateAllIdleTime();
  bool allWindowsEmpty();
  void updateWaitTime();

  //methods to calculate stats
  double mean();
  int median();
  int longestStudentTime();
  int numStudOverTen();
  double meanIdle();
  int longestWindowTime();
  int numWindOverFive();

  //attributes
  int numAllWindows;
  int clockTick = 0;
  int numWindowsOpen;
  int sumWaitTime = 0;
  int numStudentsInLine=0;

  //declaring data structures
  GenQueue<Student*> myQueue; //Queue for students to simulate a "line"
  Window* *windowList; //array of students at a window
  DoublyLinkedList<int> *waitTimesList; //list of studend waittimes to calculate stats
  int *idleTimesList;
  int *waitTimeArr;
};
