#include "Registrar.h"

int main(int argc, char** argv) {
  //check if user enters command line argument
  if(argc < 2){
    cout << "ERROR: not a valid number of command line argumnets! " << endl;
  }else if(argc == 2){
    int realTime = 0;
    int longestWait = 0;
    int over10 = 0;
    bool simulation = true;
    Registrar office;
    int windowMeanIdleTime = 0;
    string filename = argv[1];
    office.parseFile(filename);

  while(simulation){
    //only enters here if clock tick == real time, if not then we can't start putting students to windows
    if(realTime >= office.clockTick){
    for(int i = 0; i < office.sizeOfWindowList(); ++i){
      //check for next available window and push students to the window
      if((office.windowList[i]->currStudent->m_arriveTime == -1) && (!office.myQueue.isEmpty())){
        //if no student at window, but queue is not empty
        Student *temp = office.myQueue.getFront();
        //reassign default students at window to students from queue
          office.windowList[i]->currStudent = temp;
          office.windowList[i]->isOccupied = true;
          office.waitTimesList->insertBack(temp->m_waitTime);
          office.myQueue.dequeue();
      }else if(office.windowList[i]->currStudent->m_timeNeeded > 0 ){
        office.windowList[i]->currStudent->decTime();
        if(office.windowList[i]->currStudent->m_timeNeeded == 0){
          //kick student from window
          office.windowList[i]->currStudent->m_arriveTime = -1;
          office.windowList[i]->isOccupied = false;
        }
        //if window is available and there are still students in line --> assign student to window
        if(office.windowList[i]->isOccupied == false && !office.myQueue.isEmpty()){
          Student *temp2 = office.myQueue.getFront();
          //reassign default students at window to students fro queue
            office.windowList[i]->currStudent = temp2;
            office.windowList[i]->isOccupied = true;
            office.waitTimesList->insertBack(temp2->m_waitTime);
            office.myQueue.dequeue();
        }
      }
    }
    //update wait time for all students in line (queue)
    office.updateWaitTime();
  }
  // if window and queue are empty --> end simulation
  if(office.allWindowsEmpty() && office.myQueue.isEmpty()){
    simulation = false;
    break;
  }
    //update idle times
    for(int i = 0; i < office.sizeOfWindowList(); ++i){
        if(office.windowList[i]->isOccupied == false && !office.myQueue.isEmpty()){
          office.windowList[i]->addIdleTime();
        }else if(office.windowList[i]->isOccupied == false && office.myQueue.isEmpty()){
          office.windowList[i]->addIdleTime();
      }
    }
    realTime++;
  }

  cout << "SIMULATION STATS: " << endl;
  cout << "Mean student wait time: " << office.mean() << endl;
  cout << "Median student wait time: " << office.median() << endl;
  cout << "Longest student wait time: " << office.longestStudentTime() <<endl;
  cout << "Number of students waiting over 10 minutes: " << office.numStudOverTen() <<endl;
  cout << "Mean window idle time: " << office.meanIdle() << endl;
  cout << "Longest window idle time: " << office.longestWindowTime() << endl;
  cout << "Number of windows idle for over 5 minutes: " << office.numWindOverFive() << endl;
}
  return 0;
}
