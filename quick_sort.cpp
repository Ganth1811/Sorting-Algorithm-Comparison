#include "sorting_algorithm.h"

int partition(vector<type>& v, int left, int right) {
    int mid = (left + right) / 2;

	swap(v[left], v[mid]);
	int pivotIndex = left;
	int pivotValue = v[left];

	for (int i = left + 1; i <= right; i++) {
		if (v[i] < pivotValue) {
			pivotIndex++;
			swap(v[pivotIndex], v[i]);
		}
	}
	swap(v[left], v[pivotIndex]);

	return pivotIndex;
}

void QuickSort(vector<type>& v, int left, int right) {
    if (left < right) {
		int pivot = partition(v, left, right);

		QuickSort(v, left, pivot - 1);
		QuickSort(v, pivot + 1, right);
	}
}

void quickSort(vector<type>& v) {
    QuickSort(v, 0, v.size() - 1);
}