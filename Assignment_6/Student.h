/**
 * @file Student.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header file for a student
 */
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

/**
 * class Student
 * @brief class for student object
 * @return n/a
 * @param n/a
 */
class Student{
  public:
      Student();
      Student(int time);
      ~Student();
      void addTime(int t);
      int getTime();
      int getWaitTime();
      int waitTime;
      int time;
};
#endif
