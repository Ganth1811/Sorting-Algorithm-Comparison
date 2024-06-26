#include "sorting_algorithm.h"

void insertionSort(vector<type>& v, ull& comparision_count) {
	int size = v.size();

	for (int i = 1; ++comparision_count && i < size; i++) {
		int key = v[i];
		int j = i - 1;

		while (++comparision_count && j >= 0 && ++comparision_count &&
			   v[j] > key) {
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