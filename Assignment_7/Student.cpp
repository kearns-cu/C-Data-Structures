/**
 * @file Faculty.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for Student object
 */
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Faculty.h"


using namespace std;

/**
 * Student::Student() : User()
 * @brief creates a Student object extending the User class
 * @brief default constructor
 * @param n/a
 */
Student::Student() : User(){
  major = "";
  gpa = 0;
  advisor = 0;
}

/**
 * Student::Student(int setid) : User(setid,"","")
 * @brief creates a Student object extending the User class
 * @brief overloaded constructor
 * @param n/a
 */
Student::Student(int setid) : User(setid,"",""){
  major = "";
  gpa = 0;
  advisor = 0;
}

/**
 * Student::Student(int setid, string setname, string setlevel, string setmajor, double setgpa, int setadvisor) : User(setid,setname,setlevel)
 * @brief creates a Student object extending the User class
 * @brief overloaded constructor
 * @param n/a
 */
Student::Student(int setid, string setname, string setlevel, string setmajor, double setgpa, int setadvisor) : User(setid,setname,setlevel){
  major = setmajor;
  gpa = setgpa;
  advisor = setadvisor;
}

/**
 * Student::~Student()
 * @brief destructs a Student object extending the User class
 * @brief default destructor
 * @param n/a
 */
Student::~Student(){

}

/**
 * string Student::getMajor()
 * @brief returns the major of the student object
 * @param n/a
 * @return string
 */
string Student::getMajor(){
  return major;
}

/**
 * double Student::getGPA()
 * @brief returns the gpa of the student object
 * @param n/a
 * @return double
 */
double Student::getGPA(){
  return gpa;
}

/**
 * int Student::getAdvisor()
 * @brief returns the advisor of the student object
 * @param n/a
 * @return int
 */
int Student::getAdvisor(){
  return advisor;
}

/**
 * void Student::setMajor(string setMajor)
 * @brief sets the major member variable of the student
 * @param string major
 * @return void
 */
void Student::setMajor(string setMajor)
{
  major = setMajor;
}

/**
 * void Student::setGPA(double setGPA)
 * @brief sets the gpa member variable of the student
 * @param double gpa
 * @return void
 */
void Student::setGPA(double setGPA){
  gpa = setGPA;
}

/**
 * void Student::setAdvisor(int setAdvisor)
 * @brief sets the advisor member variable of the student
 * @param int advisor's id
 * @return void
 */
void Student::setAdvisor(int setAdvisor){
  advisor = setAdvisor;
}

/**
 * string Student::toString()
 * @brief prints the member variables data related to the student object
 * @param n/a
 * @return string
 */
string Student::toString(){
  string result = "";
  string temp = "Student ID: " + to_string(getID());
  string sName = "\nName: " + getName();
  string sLevel = "\nLevel: " + getLevel();
  string sMajor = "\nMajor: " + getMajor();
  string sGPA = "\nGPA: " + to_string(getGPA());
  string sAdvisor = "\nAdvisor: " + to_string(getAdvisor());
  result = temp + sName + sLevel + sMajor + sGPA + sAdvisor;
  return result;
}

/**
 * void Student::print()
 * @brief prints toString of the student
 * @param n/a
 * @return void
 */
void Student::print(){
  cout << toString() << endl;
}
