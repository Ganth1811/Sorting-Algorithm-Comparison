#include "sorting_algorithm.h"

void insertionSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();

	for (int i = 1; ++comparison_count && i < size; i++) {
		int key = v[i];
		int j = i - 1;

		while (++comparison_count && j >= 0 && ++comparison_count &&
			   v[j] > key) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

int binarySearch(vector<type> v, int item, int left, int right, ull& comparison_count) {
	while (++comparison_count && left <= right) {
		int mid = left + (right - left) / 2;
		if (++comparison_count && item == v[mid])
			return mid + 1;
		else if (++comparison_count && item > v[mid])
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return left;
}

void binaryInsertionSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();

	for (int i = 1; ++comparison_count && i < size; i++) {
		int key = v[i];
		int j = i - 1;

		int loc = binarySearch(v, key, 0, j, comparison_count);

		while (++comparison_count && j >= loc) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

void insertionSort(vector<type>& v) {
	int size = v.size();

	for (int i = 1; i < size; i++) {
		int key = v[i];
		int j = i - 1;

		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

int binarySearch(vector<type> v, int item, int left, int right) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (item == v[mid])
			return mid + 1;
		else if (item > v[mid])
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return left;
}

void binaryInsertionSort(vector<type>& v) {
	int size = v.size();

	for (int i = 1; i < size; i++) {
		int key = v[i];
		int j = i - 1;

		int loc = binarySearch(v, key, 0, j);

		while (j >= loc) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}