#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

using type = int;

void bubbleSort(vector<type>&);
void insertionSort(vector<type>&);
void selectionSort(vector<type>&);
void mergeSort(vector<type>&);
void quickSort(vector<type>&);
void heapSort(vector<type>&);
void radixSort(vector<type>&);

void sort(vector<type>&, void sortAlgorithm(vector<type>));


