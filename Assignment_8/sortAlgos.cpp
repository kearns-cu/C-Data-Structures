/**
 * @file sortAlgos.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for sorting class
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "sortAlgos.h"

using namespace std;


/**
 * sortAlgos::sortAlgos()
 * @brief create a sortAlgo object with null arrays and sets the seed
 * @brief default constructor
 * @param n/a
 */
sortAlgos::sortAlgos(): size(0){

	arr = mergeArr = selectionArr = bubbleArr = radixArr = NULL;
	srand(static_cast<unsigned int>(time(NULL)));
}

/**
 * sortAlgos::~sortAlgos()
 * @brief destructs a sortAlgo object by deleting all arrays
 * @brief default destructor
 * @param n/a
 */
sortAlgos::~sortAlgos(){
	clear();
}

/**
 * void Student::addTime(int t)
 * @brief swaps two pointers values
 * @param double* x, double* y
 * @return void
 */
void sortAlgos::swap(double* x, double* y){
    double temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * void sortAlgos::merge(double* arr, int lo, int m, int hi)
 * @brief merge the elements using recursion
 * @param double* arr, int lo, int m, int hi
 * @return void
 */
void sortAlgos::merge(double* arr, int lo, int m, int hi){
	int n1 = m - lo + 1;
	int n2 = hi - m;

	//create temp arrays
	double* low =  new double[n1];
	double* high = new double[n2];

	for (int i = 0; i < n1; i++){
		low[i] = arr[lo + i];
	}

	for (int j = 0; j < n2; j++){
		high[j] = arr[m + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = lo;

	while (i < n1 && j < n2){
		if (low[i] <= high[j]){
			arr[k] = low[i];
			i++;
		}
		else{
			arr[k] = high[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		arr[k] = low[i];
		i++;
		k++;
	}

	while (j < n2){
		arr[k] = high[j];
		j++;
		k++;
	}

	delete[] high;
	delete[] low;
}

/**
 * void sortAlgos::mergeSort(double* arr, int lo, int hi)
 * @brief performs a merge sort
 * @param double* arr, int lo, int hi
 * @return void
 */
void sortAlgos::mergeSort(double* arr, int lo, int hi){
  if (lo >= hi){
    return;
  }
    //Compute the middle of the data
    int m = lo + (hi - lo) / 2;
    mergeSort(arr, lo, m); //sort the low to middle using recursion
    mergeSort(arr, m + 1 , hi); //sort the middle to high using recursion
    merge(arr, lo, m, hi);
}

/**
 * void sortAlgos::selectionSort(double* arr, int n)
 * @brief performs a selection sort
 * @param double* arr, int n
 * @return void
 */
void sortAlgos::selectionSort(double* arr, int n){
	//K to the right of k, therefore min
	//Swap values
	int i, j, minIndex;
	for (i = 0; i < n-1; i++){
		minIndex = i;
		for (j = i + 1; j < n; j++){
			if (arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(&arr[minIndex], &arr[i]);
	}
}

/**
 * void sortAlgos::bubbleSort(double* arr, int n)
 * @brief performs a bubble sort
 * @param double* arr, int n
 * @return void
 */
void sortAlgos::bubbleSort(double* arr, int n){
	  for(int i = 0; i < n-1; ++i){
			for(int j = 0; j < n-1; ++j){
		  	if(arr[j] > arr[j+1]){
					swap(&arr[j], &arr[j + 1]);
		  	}
			}
	  }
}

/**
 * double sortAlgos::getMax(double* arr, int n)
 * @brief returns max double in array
 * @param double* arr, int n
 * @return double max
 */
double sortAlgos::getMax(double* arr, int n){
  double max = arr[0];

  for (int i = 0; i < n; ++i){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

/**
 * void sortAlgos::countSort(double* arr, int n, double temp)
 * @brief performs a count sort
 * @param double* arr, int n, double temp
 * @return void
 */
void sortAlgos::countSort(double* arr, int n, double temp){
	const int MAX = 10;
	double* tempArray = new double[n];
	int count[MAX];
	for (int i = 0; i < MAX; ++i){
		count[i] = 0;
	}

	//Num elements
	for (int i = 0; i < n; ++i){
		count[static_cast<int>((arr[i] / temp)) % 10]++;
	}

	//Cumulative
	for (int i = 1; i < MAX; i++){
		count[i] += count[i-1];
	}

	//Sorted
	for (int i = n - 1; i >= 0; i--){
		tempArray[count[static_cast<int>((arr[i] / temp)) % 10] - 1] = arr[i];
		count[static_cast<int>((arr[i] / temp)) % 10]--;
	}

	for (int i = 0; i < n; i++){
		arr[i] = tempArray[i];
	}
	delete[] tempArray;
}

/**
 * void sortAlgos::radixSort(double* arr, int n)
 * @brief performs a raxix sort, using count sort
 * @param double* arr, int n
 * @return void
 */
void sortAlgos::radixSort(double* arr, int n){
	double max = getMax(arr,n);
	for (int temp = 1; max/temp > 0; temp *=10){
		countSort(arr,n,temp);
	}
}

/**
 * void sortAlgos::printArray(double* arr, int n)
 * @brief prints the each double array element
 * @param double* arr, int n
 * @return void
 */
void sortAlgos::printArray(double* arr, int n){
	for (int i = 0; i < n; i++){
		cout << fixed << setprecision(2) << arr[i] << " ";
	}
}

/**
 * void sortAlgos::randomNumberFileGenerator(int number, const string& filename)
 * @brief generates a random data file to be sorted
 * @param int number, const string& filename
 * @return void
 */
void sortAlgos::randomNumberFileGenerator(int number, const string& filename){
	ofstream outFile(filename, ios::trunc);
	outFile << number << endl;
	for (int i = 0; i < number; i++){
		double ranDbl = (100000.0 - 0.0) * (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) + 0;
		outFile << fixed << setprecision(2) << ranDbl << endl;
	}

	outFile.close();
}

/**
 * void sortAlgos::readFile(const string& filename)
 * @brief reads data from a file and stores it in each type of sort array
 * @param const string& filename
 * @return void
 */
void sortAlgos::readFile(const string& filename){
	ifstream inFile(filename);
	inFile >> size;
	if (arr){
		clear();
	}

	arr = new double[size];
	mergeArr = new double[size];
	selectionArr = new double[size];
	bubbleArr = new double[size];
	radixArr = new double[size];

	int index = 0;
	while (inFile >> arr[index++] >> ws) {}
	for (int i = 0; i < size; i++){
		arr[i] = mergeArr[i] = selectionArr[i] = bubbleArr[i] = radixArr[i];
	}
	inFile.close();
}

/**
 * void sortAlgos::clear()
 * @brief deletes all arrays for each type of sorting algo
 * @param n/a
 * @return void
 */
void sortAlgos::clear(){
	delete[] arr;
	delete[] mergeArr;
	delete[] selectionArr;
	delete[] bubbleArr;
	delete[] radixArr;

	size = 0;
}

/**
 * void sortAlgos::run(const string& mode, int number, const string& filename)
 * @brief either creates or sorts a data file while running the time library
 * @param const string& mode, int number, const string& filename
 * @return void
 */
void sortAlgos::run(const string& mode, int number, const string& filename){
	if (mode == "create"){
		randomNumberFileGenerator(number, filename);
	}

	else if (mode == "sort"){
		readFile(filename);
		cout << "\nMERGE sorted array:" << endl;
		clock_t mergeStart = clock();
		cout << "Start time: " << mergeStart << endl;
		mergeSort(mergeArr, 0, size - 1);
		clock_t mergeEnd = clock();
		cout << "End time: " << mergeEnd << endl;
		cout << "Duration (s): " << (float(mergeEnd - mergeStart) / (CLOCKS_PER_SEC)) << " seconds" << endl;
		cout << "Duration (ms): " << (float(mergeEnd - mergeStart) / (CLOCKS_PER_SEC)) * 1000 << " milliseconds" << endl << endl;

		cout << "\nSELECTION sorted array:" << endl;
		clock_t selectionStart = clock();
		cout << "Start time: " << selectionStart << endl;
		selectionSort(selectionArr, size);
		clock_t selectionEnd = clock();
		cout << "End time: " << selectionEnd << endl;
		cout << "Duration (s): " << (float(selectionEnd - selectionStart) / (CLOCKS_PER_SEC)) << " seconds" << endl;
		cout << "Duration (ms): " << (float(selectionEnd - selectionStart) / (CLOCKS_PER_SEC)) * 1000 << " milliseconds" << endl << endl;

		cout << "\nBUBBLE sorted array:" << endl;
		clock_t bubbleStart = clock();
		cout << "Start time: " << bubbleStart << endl;
		bubbleSort(bubbleArr, size);
		clock_t bubbleEnd = clock();
		cout << "End time: " << bubbleEnd << endl;
		cout << "Duration (s): " << (float(bubbleEnd - bubbleStart) / (CLOCKS_PER_SEC)) << " seconds" << endl;
		cout << "Duration (ms): " << (float(bubbleEnd - bubbleStart) / (CLOCKS_PER_SEC)) * 1000 << " milliseconds" << endl << endl;

		cout << "\nRADIX sorted array:" << endl;
		clock_t radixStart = clock();
		cout << "Start time: " << radixStart << endl;
		radixSort(radixArr, size);
		clock_t radixEnd = clock();
		cout << "End time: " << radixEnd << endl;
		cout << "Duration (s): " << (float(radixEnd - radixStart) / (CLOCKS_PER_SEC)) << " seconds" << endl;
		cout << "Duration (ms): " << (float(radixEnd - radixStart) / (CLOCKS_PER_SEC)) * 1000 << " milliseconds" << endl << endl;

	}
}
