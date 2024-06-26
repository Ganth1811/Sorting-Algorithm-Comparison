#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

using type = int;
typedef unsigned long long ull;

void bubbleSort(vector<type>&, ull&);
void insertionSort(vector<type>&, ull&);
void selectionSort(vector<type>&, ull&);
void mergeSort(vector<type>&, ull&);
void quickSort(vector<type>&, ull&);
void heapSort(vector<type>&, ull&);
void radixSort(vector<type>&, ull&);

void shakerSort(vector<type>&, ull&);
void shellSort(vector<type>&, ull&);
void countingSort(vector<type>&,ull&);
void flashSort(vector<type>&, ull&);

void optimizedBubbleSort(vector<type>&, ull&);
void binaryInsertionSort(vector<type>&, ull&);
void randomizedQuickSort(vector<type>&, ull&);
void medianQuickSort(vector<type>&, ull&);

// No-counter version

void bubbleSort(vector<type>&);
void insertionSort(vector<type>&);
void selectionSort(vector<type>&);
void mergeSort(vector<type>&);
void quickSort(vector<type>&);
void heapSort(vector<type>&);
void radixSort(vector<type>&);

void shakerSort(vector<type>&);
void shellSort(vector<type>&);
void countingSort(vector<type>&);
void flashSort(vector<type>&);

void optimizedBubbleSort(vector<type>&);
void binaryInsertionSort(vector<type>&);
void randomizedQuickSort(vector<type>&);
void medianQuickSort(vector<type>&);