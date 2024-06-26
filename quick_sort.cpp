#include "sorting_algorithm.h"
#include <time.h>
#include <stdlib.h>

int partition(vector<type>& v, int left, int right, ull& comparison_count) {
	int pivotIndex = left;
	int pivotValue = v[left];

	for (int i = left + 1; ++comparison_count && i <= right; i++) {
		if (++comparison_count && v[i] < pivotValue) {
			pivotIndex++;
			swap(v[pivotIndex], v[i]);
		}
	}
	swap(v[left], v[pivotIndex]);

	return pivotIndex;
}

int partitionMid(vector<type>& v, int left, int right, ull& comparison_count) {
	int mid = (left + right) / 2;

	swap(v[left], v[mid]);

	return partition(v, left, right, comparison_count);
}

void quickSort(vector<type>& v, int left, int right, ull& comparison_count) {
	if (++comparison_count && left < right) {
		int pivot = partitionMid(v, left, right, comparison_count);

		quickSort(v, left, pivot - 1, comparison_count);
		quickSort(v, pivot + 1, right, comparison_count);
	}
}

void quickSort(vector<type>& v, ull& comparison_count) {
	quickSort(v, 0, v.size() - 1, comparison_count);
}

int partitionRandomized(vector<type>& v, int left, int right, ull& comparison_count) {
	srand(time(NULL));
	int pivot = left + rand() % (right - left);

	swap(v[left], v[pivot]);

	return partition(v, left, right, comparison_count);
}

void randomizedQuickSort(vector<type>& v, int left, int right, ull& comparison_count) {
	if (++comparison_count && left < right) {
		int pivot = partitionRandomized(v, left, right, comparison_count);

		randomizedQuickSort(v, left, pivot - 1, comparison_count);
		randomizedQuickSort(v, pivot + 1, right, comparison_count);
	}
}

void randomizedQuickSort(vector<type>& v, ull& comparison_count) {
	randomizedQuickSort(v, 0, v.size() - 1, comparison_count);
}

int partitionMedian(vector<type>& v, int left, int right, ull& comparison_count) {
	int pivot, mid = (left + right) / 2;
	int a = v[left], b = v[mid], c = v[right];

	// Find the median of three
	if (++comparison_count && a > b) {
		if (++comparison_count && b > c) 
			pivot = mid;
		else if (++comparison_count && a > c)
			pivot = right;
		else 
			pivot = left;
	} else {
		if (++comparison_count && a > c) 
			pivot = left;
		else if (++comparison_count && b > c)
			pivot = right;
		else
			pivot = mid;
	}

	swap(v[left], v[pivot]);

	return partition(v, left, right, comparison_count);
}

void medianQuickSort(vector<type>& v, int left, int right, ull& comparison_count) {
	if (++comparison_count && left < right) {
		int pivot = partitionMedian(v, left, right, comparison_count);

		medianQuickSort(v, left, pivot - 1, comparison_count);
		medianQuickSort(v, pivot + 1, right, comparison_count);
	}
}

void medianQuickSort(vector<type>& v, ull& comparison_count) {
	medianQuickSort(v, 0, v.size() - 1, comparison_count);
}

int partition(vector<type>& v, int left, int right) {
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

int partitionMid(vector<type>& v, int left, int right) {
	int mid = (left + right) / 2;

	swap(v[left], v[mid]);

	return partition(v, left, right);
}

void quickSort(vector<type>& v, int left, int right) {
	if (left < right) {
		int pivot = partitionMid(v, left, right);

		quickSort(v, left, pivot - 1);
		quickSort(v, pivot + 1, right);
	}
}

void quickSort(vector<type>& v){
	quickSort(v, 0, v.size() - 1);
}

int partitionRandomized(vector<type>& v, int left, int right) {
	srand(time(NULL));
	int pivot = left + rand() % (right - left);

	swap(v[left], v[pivot]);

	return partition(v, left, right);
}

void randomizedQuickSort(vector<type>& v, int left, int right) {
	if (left < right) {
		int pivot = partitionRandomized(v, left, right);

		randomizedQuickSort(v, left, pivot - 1);
		randomizedQuickSort(v, pivot + 1, right);
	}
}

void randomizedQuickSort(vector<type>& v) {
	randomizedQuickSort(v, 0, v.size() - 1);
}

int partitionMedian(vector<type>& v, int left, int right) {
	int pivot, mid = (left + right) / 2;
	int a = v[left], b = v[mid], c = v[right];

	// Find the median of three
	if (a > b) {
		if (b > c) 
			pivot = mid;
		else if (a > c)
			pivot = right;
		else 
			pivot = left;
	} else {
		if (a > c) 
			pivot = left;
		else if (b > c)
			pivot = right;
		else
			pivot = mid;
	}

	swap(v[left], v[pivot]);

	return partition(v, left, right);
}

void medianQuickSort(vector<type>& v, int left, int right) {
	if (left < right) {
		int pivot = partitionMedian(v, left, right);

		medianQuickSort(v, left, pivot - 1);
		medianQuickSort(v, pivot + 1, right);
	}
}

void medianQuickSort(vector<type>& v) {
	medianQuickSort(v, 0, v.size() - 1);
}