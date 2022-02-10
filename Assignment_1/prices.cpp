#include <iostream>
using namespace std;

int main(){
  double priceSum;
  double currPrice;
  cout << "Enter the price of some common items you buy" << endl;
  cin >> currPrice;
  while(currPrice > 0){
      priceSum += currPrice;
      cin >> currPrice;
  }
  cout << "Total Cost: $" << priceSum << endl;

  return 0;
}
