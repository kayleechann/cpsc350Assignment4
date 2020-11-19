#include "Registrar.h"

int main(int argc, char** argv) {
  if(argc < 2){
    cout << "ERROR: not a valid number of command line argumnets! " << endl;
  }else if(argc == 2){
    int realTime = 0;
    bool simulation = true;
    //0 = false, 1 = true
    Registrar office;
    int windowMeanIdleTime = 0;
    string filename = argv[1];
    office.parseFile(filename);
    //cout << office.allWindowsEmpty() << endl; //1 true , 0 false

  while(simulation){
    cout << "real time: " << realTime << endl;
    cout << "Clock tick: " << office.clockTick << endl << "------- " << endl;
    cout << "size of queue: " << office.myQueue->getSize() << endl;

    if(realTime >= office.clockTick){
    for(int i = 0; i < office.sizeOfWindowList(); ++i){
      //check for next available window and push students to the window
      if((office.windowList[i]->currStudent->m_arriveTime == -1) && (!office.myQueue->isEmpty())){
        //if no student at window, but queue is not empty
        Student *temp = office.myQueue->getFront();
        //reassign default students at window to students fro queue
          office.windowList[i]->currStudent = temp;
          office.windowList[i]->isOccupied = true;
          office.myQueue->dequeue();

      }else if(office.windowList[i]->currStudent->m_timeNeeded > 0 ){
        office.windowList[i]->currStudent->decTime();
        if(office.windowList[i]->currStudent->m_timeNeeded == 0){
          //kick student from window
          office.windowList[i]->currStudent->m_arriveTime = -1;
          office.windowList[i]->isOccupied = false;
        }
        if(office.windowList[i]->isOccupied == false && !office.myQueue->isEmpty()){
          Student *temp2 = office.myQueue->getFront();
          //reassign default students at window to students fro queue
            office.windowList[i]->currStudent = temp2;
            office.windowList[i]->isOccupied = true;
            office.myQueue->dequeue();
        }
      }
      cout << "time needed at window: " << office.windowList[i]->currStudent->m_timeNeeded << endl;
    }

  }
    //update idle times
    for(int i = 0; i < office.sizeOfWindowList(); ++i){
      //if queue and windows are empty
       // }else{
        if(office.windowList[i]->isOccupied == false && !office.myQueue->isEmpty()){
          office.windowList[i]->addIdleTime();
        }else if(office.windowList[i]->isOccupied == false && office.myQueue->isEmpty()){
          office.windowList[i]->addIdleTime();

      }
      office.windowList[i]->printWindow();
    }

    cout << "all windows empty: " << office.allWindowsEmpty() << endl;
    cout << "queue is empty: " << office.myQueue->isEmpty() << endl;

    if(office.allWindowsEmpty() && office.myQueue->isEmpty()){
      simulation = false;
      break;
    }


    realTime++;
  }

  cout << endl << endl;
  cout << "Mean student wait time: " << endl;
  cout << "Median student wait time: " << endl;
  cout << "Longest student wait time: " << endl;
  cout << "Number of students waiting over 10 minutes: " << endl;
  cout << "Mean window idle time: " << office.meanIdle() << endl;
  cout << "Longest window idle time: " << office.longestWindowTime() << endl;
  cout << "Number of windows idle for over 5 minutes: " << office.numWindOverFive() << endl;
} //end of else statement


  return 0;
}
