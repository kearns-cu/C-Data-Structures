/**
 * @file sortAlgos.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header template file for sortAlgos
 */
#ifndef SORT_H
#define SORT_H
#include <string>

using namespace std;

/**
 * class sortAlgos
 * @brief class for a sortAlgos
 * @return n/a
 * @param n/a
 */
class sortAlgos{
public:
	sortAlgos();
	~sortAlgos();
	void swap(double* x, double* y);
	void merge(double* arr, int m, int lo, int hi);
	void mergeSort(double* arr, int lo, int hi);
	void selectionSort(double* arr, int n);
	void bubbleSort(double* arr, int n);
	double getMax(double* arr, int n);
	void countSort(double* arr, int n, double temp);
	void radixSort(double* arr, int n);
	void printArray(double* arr, int n);
	void run(const string& mode, int number, const string& filename);

private:
	void randomNumberFileGenerator(int number, const string& filename);
	void readFile(const string& filename);
	void clear();

  int size;
	double* arr;
  double* mergeArr;
  double* selectionArr;
  double* bubbleArr;
  double* radixArr;
};
#endif
