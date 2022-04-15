/**
 * @file registrar.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header file for registrar office
 */
#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
using namespace std;

/**
 * class Registrar
 * @brief class for registrar simulation
 * @return n/a
 * @param n/a
 */
class Registrar{
  public:
    Registrar();
    ~Registrar();
    void simulation(string file);
    void calculations();

  private:
    GenQueue<Student> *myQueue; //queue
    int size; //num windows
    int totalStudents; //num students
    int time; //arrival time
    int atWindowTime; //time at each window
    int studentsAtTime; //number of students at a time
    Student *StudentTimes[100]; //array of student wait times
    int studentCount; //total students
    Window *WindowTimes[100]; //array of window wait times
    int min; //min wait time
    int windowCount; //num windows utilized
};
#endif
