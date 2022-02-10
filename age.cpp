#include <iostream>
using namespace std;

int main(){
  int age[3];
  cout << "Enter the ages of three people you know." << endl;
  cout << "Person 1: ";
  cin >> age[0];
  cout << "Person 2: ";
  cin >> age[1];
  cout << "Person 3: ";
  cin >> age[2];
  int greatestAge = age[0];
  int leastAge = age[0];
  for(int i = 0; i < 3; ++i){
    if(age[i] > greatestAge){
      greatestAge = age[i];
    } else if(age[i] < leastAge){
      leastAge = age[i];
    }
  }

  cout << "\n" << "Least: " << leastAge << endl;
  cout << "Greatest: " << greatestAge << endl;

  return 0;
}
