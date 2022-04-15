/**
 * @file registrar.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for registar office
 */

#include "registrar.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * Registrar::Registrar()
 * @brief create a new registrar class that holds data regarding the windows and queue that students are accessing
 * @brief default constructor
 * @param n/a
 */
Registrar::Registrar(){
  myQueue = new GenQueue<Student>();
  size = 0;
  totalStudents = -1;
  time = 0;
  atWindowTime = 0;
  studentsAtTime = 0;
  studentCount = 0;
  min = 0;
  windowCount = 0;
}

/**
 * Registrar::~Registrar()
 * @brief default registrar destructor
 * @param n/a
 */
Registrar::~Registrar(){
  delete myQueue;
}

/**
 * void Registrar::simulation(string file)
 * @brief main similuation function for simulating a registrar object
 * @brief takes input file and processes the students that enter queue and window to eventually be processed.
 * @param n/a
 */
void Registrar::simulation(string file){

  int count = 0; //index number of line in file
  string line; //holds current line in the file
  int var = 1; //whether a correct amount of student objects were made
  Student *tempStudent = new Student(); //temp student
  int firstline = -1;
  int count_T[size]; //counts occupied windows
  int countT = -1; //occupied windows count
  int start = 0; //variable for the first time in the file

  ifstream infile(file);

  while(getline(infile, line)){
    if(count == 0){

      size = stoi(line);
      for(int i = 0; i < size; i++){
        WindowTimes[i] = new Window();
      }

      count++;
      continue;

    }
		if(count == 1){
      time = stoi(line);
      count++;
      continue;


    }

		if(count == 2){
      studentsAtTime = stoi(line);
      studentCount += studentsAtTime;
      count++;
      continue;

    }
		if(count == 3){
      atWindowTime = stoi(line);

      Student *s = new Student(atWindowTime);

      myQueue->insert(s);


      if(var < studentsAtTime){
        var++;
        continue;


      }
			else if(var == studentsAtTime){
        count = 4;
        var = 1;
      }
    }

    if(count == 4){

      firstline++;

      if(firstline == 0){
        for(int i = 0; i < size; i++){
          WindowTimes[i]->addWaitTime(time);
        }
        start = time;
      }
			else{
        for(int i = 0; i < size; i++){

          if(WindowTimes[i]->isOccupied() == false){
            WindowTimes[i]->addWaitTime(time);
          }
        }
      }

      while(var <= studentsAtTime){


        if(myQueue->isEmpty()){
          break;

        }
				else if(myQueue->isEmpty() == false){

          tempStudent = myQueue->remove();
          totalStudents++;
          var++;


          if(windowCount == size){

            int w = 0;
            int oTime[size]; //array of the occupied time of a window

            for(int i = 0; i < size; i++){
              if(firstline == 0){
                oTime[i] = WindowTimes[i]->getOccupiedTime();
              }
							else if(WindowTimes[i]->getCurrentlyOccupied() == true){
                oTime[i] = (WindowTimes[i]->getOccupiedTime() + time) - start;
              }
							else if(WindowTimes[i]->getCurrentlyOccupied() == false){
                oTime[i] = (WindowTimes[i]->getOccupiedTime() - time) + start;
              }
            }

            min = oTime[0];

            //minimum occupied time
            for(int i = 1; i < size; i++){

              if(oTime[i] < min){
                min = oTime[i];
                w = i;
              }
            }

            if(min < 0){
              min = 0;
            }

            tempStudent->addTime(min);

            WindowTimes[w]->addOccupiedTime(tempStudent->getTime());
            WindowTimes[w]->isCurrentlyOccupied();

            StudentTimes[totalStudents] = tempStudent;
          }

          for(int i = 0; i < size; i++){

            if(WindowTimes[i]->isOccupied() == false){

              WindowTimes[i]->isCurrentlyOccupied();

              countT++;

              count_T[countT] = i;

              tempStudent->addTime(0);

              StudentTimes[totalStudents] = tempStudent;

              WindowTimes[i]->updateTrue();

              WindowTimes[i]->addOccupiedTime(tempStudent->getTime());

              windowCount++;
              break;

            }
						if(WindowTimes[i]->getOccupiedTime() - time <= 0){

              WindowTimes[i]->updateFalse();
              windowCount--;
            }
          }


          if(var >= studentsAtTime){
            count = 5;
          }
        }
      }

    }
		if(count == 5){
      count = 1;
      var = 1;
      countT = -1;

      for(int i = 0; i < size; i++){

        if(WindowTimes[i]->isOccupied() == false){
          WindowTimes[i]->addWaitTime(time);
        }

        WindowTimes[i]->notCurrentlyOccupied();

      }
      for(int i = 0; i < size; i++){
        count_T[i] = -1;
      }
      continue;
    }
  }


  //Report when file isn't written correctly
  if(var != 1){
    cout << endl;
    cout << "Error in text file, please double check" << endl;
    cout << endl;
    return;
  }


  calculations();
}


/**
 * void Registrar::calculations()
 * @brief calculates the statistics after simulation has been run
 * @brief report statistics to console output
 * @param n/a
 */
void Registrar::calculations(){

  //Calculates the mean student wait time

  cout << endl;
  float n = 0;
  float meanCount = 0;


  for(int i = 0; i < studentCount; i++){
    n += StudentTimes[i]->getWaitTime();
    meanCount++;
  }

  if(n == 0.0){
    n = 0.0;


  }
	else{
    n = n/meanCount;
  }
  cout << "Mean student wait time in queue: " << n << endl;

  float median = 0.0f;
  int medianPos;
  int medianArr[studentCount];

  for(int i = 0 ; i < studentCount; i++){
    medianArr[i] = StudentTimes[i]->getWaitTime();
  }

  for(int i = 0; i < studentCount; i++ ){
    for(int j = i + 1; j < studentCount ; j++){
      if(medianArr[i] < medianArr[j]){
        median = medianArr[i];
        medianArr[i] = medianArr[j];
        medianArr[j] = median;
      }
    }
  }

  totalStudents++;

  medianPos = totalStudents%2;

  if(medianPos == 1){
    medianPos = (totalStudents/2);
    cout << "Median student wait time in the queue: " << medianArr[medianPos] << endl;
  }
	else{
    medianPos = (totalStudents/2);
    median = ((medianArr[medianPos + 1] + medianArr[medianPos]) /2);
    cout << "Median student wait time in the queue: " << median << endl;
  }

  //Calculates longest student wait time

  cout << "The longest student wait time in the queue: " << medianArr[0] << endl;

  int student10 = 0;
  for(int i = 0 ; i < studentCount ; i++){
    if (medianArr[i] >= 10){
      student10++;
    }
	}
  cout << "Number of students waiting in queue longer than 10 min: " << student10 << endl;
  cout << endl;

  //Calcalates mean window idle time

  int meanWindow[size];
  float windowSum = 0.0;

  for(int i = 0; i < size; i++){
    meanWindow[i] = WindowTimes[i]->getWaitTime();
  }

  for(int i = 0; i < size; i++){
    windowSum += meanWindow[i];
  }

  float windowMean = windowSum / size;

  cout << "Mean window idle time: " << windowMean << endl;

  //The longest window idle time

  int tempWindow = 0;

  for(int i = 0; i < size; i++ ){
    for(int j = i + 1; j < size; j++){
      if(meanWindow[i] < meanWindow[j]){
        tempWindow = meanWindow[i];
        meanWindow[i] = meanWindow[j];
        meanWindow[j] = tempWindow;
      }
    }
  }

  cout << "Longest window idle time: " << meanWindow[0] << endl;

  //Number of windows idle for over 5 minutes.

  int window5 = 0;
  for(int i = 0 ; i < size; i++){
    if (meanWindow[i] >= 5){
      window5++;
    }
	}
  cout << "Number of windows with wait time over 5 min: " << window5 << endl;
  cout << endl;

}
