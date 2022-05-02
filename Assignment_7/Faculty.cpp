/**
 * @file Faculty.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for Faculty object
 */
#include <iostream>
#include "Faculty.h"

using namespace std;

/**
 * Faculty::Faculty() : User()
 * @brief creates a faculty object extending the User class
 * @brief default constructor
 * @param n/a
 */
Faculty::Faculty() : User(){
  department = "";
  advisees = new DoublyLinkedList<Student>();
}

/**
 * Faculty::Faculty() : User()
 * @brief creates a Faculty object extending the User class
 * @brief overloaded constructor
 * @param n/a
 */
Faculty::Faculty(int setid) : User(setid,"",""){
  department = "";
  name = "";
  level = "";
  advisees = new DoublyLinkedList<Student>();
}

/**
 * Faculty::Faculty() : User()
 * @brief creates a Faculty object extending the User class
 * @brief overloaded constructor
 * @param n/a
 */
Faculty::Faculty(int setid, string setname, string setlevel, string setdepartment) : User(setid,setname,setlevel)
{
  department = setdepartment;
  advisees = new DoublyLinkedList<Student>();
}

/**
 * Faculty::Faculty() : User()
 * @brief destructs a Faculty object extending the User class
 * @brief default destructor
 * @param n/a
 */
Faculty::~Faculty(){

}

/**
 * string Faculty::getDepartment()
 * @brief returns the department of the faculty member
 * @param n/a
 * @return string
 */
string Faculty::getDepartment(){
  return department;
}

/**
 * bool Faculty::hasStudents()
 * @brief returns whether a faculty object has associated student objects.
 * @param n/a
 * @return bool
 */
bool Faculty::hasStudents(){
  return !(advisees->isEmpty());
}

/**
 * void Faculty::setDepartment(string setDepartment)
 * @brief sets the department member variable
 * @param string setDepartment
 * @return void
 */
void Faculty::setDepartment(string setDepartment){
  department = setDepartment;
}

/**
 * void Faculty::addAdvisee(Student sID)
 * @brief adds a student object as an advisee to the faculty object
 * @param Student student's ID
 * @return void
 */
void Faculty::addAdvisee(Student sID){
  advisees->insertBack(sID);
}

/**
 * void Faculty::removeAdvisee(Student sID)
 * @brief removes a student object from being an advisee to the faculty object
 * @param Student student's ID
 * @return void
 */
void Faculty::removeAdvisee(Student sID){
  advisees->remove(sID);
}

/**
 * string Faculty::toString()
 * @brief prints the member variables data related to the faculty object
 * @param n/a
 * @return string
 */
string Faculty::toString(){
  string result = "";
  string fID = "Faculty ID: " + to_string(getID());
  string fName = "\nName: " + getName();
  string fLevel = "\nLevel: " + getLevel();
  string fDepartment = "\nDepartment: " + getDepartment();
  result = fID + fName + fLevel + fDepartment;
  return result;
}

/**
 * void Faculty::print()
 * @brief prints the additional data related to the faculty member
 * @param n/a
 * @return string
 */
void Faculty::print(){
  cout << "Faculty ID: " << to_string(getID()) << endl;
  cout <<  "Name: " + getName() << endl;
  cout <<  "Level: " + getLevel() << endl;
  cout <<  "Department: " + getDepartment() << endl;
}

/**
 * void Faculty::printStudents()
 * @brief prints the list of student under this faculty member as an advisor
 * @param n/a
 * @return string
 */
void Faculty::printStudents(){
  advisees->printList();
}
