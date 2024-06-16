#include "sorting_algorithm.h"

int partition(vector<type>& v, int left, int right, ull& comparision_count) {
	int mid = (left + right) / 2;

	swap(v[left], v[mid]);
	int pivotIndex = left;
	int pivotValue = v[left];

	for (int i = left + 1; ++comparision_count && i <= right; i++) {
		if (++comparision_count && v[i] < pivotValue) {
			pivotIndex++;
			swap(v[pivotIndex], v[i]);
		}
	}
	swap(v[left], v[pivotIndex]);

	return pivotIndex;
}

void quickSort(vector<type>& v, int left, int right, ull& comparision_count) {
	if (++comparision_count && left < right) {
		int pivot = partition(v, left, right, comparision_count);

		quickSort(v, left, pivot - 1, comparision_count);
		quickSort(v, pivot + 1, right, comparision_count);
	}
}

void quickSort(vector<type>& v, ull& comparision_count) {
	quickSort(v, 0, v.size() - 1, comparision_count);
}

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

void quickSort(vector<type>& v, int left, int right) {
	if (left < right) {
		int pivot = partition(v, left, right);

		quickSort(v, left, pivot - 1);
		quickSort(v, pivot + 1, right);
	}
}

void quickSort(vector<type>& v){
	quickSort(v, 0, v.size() - 1);
}