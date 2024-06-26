#include "sorting_algorithm.h"

void bubbleSort(vector<type>& v, ull& comparision_count) {
	int size = v.size();

	for (int i = 0; ++comparision_count && i < size - 1; i++) {
		for (int j = 0; ++comparision_count && j < size - 1 - i; j++) {
			if (++comparision_count && v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

void bubbleSort(vector<type>& v) {
	int size = v.size();

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}
