#include "sorting_algorithm.h"

void bubbleSort(vector<type>& v, unsigned long long& comparision_count) {
	int size = v.size();

	for (int i = 0; ++comparision_count && i < size - 1; i++) {
		for (int j = 0; ++comparision_count && j < size - 1 - i; j++) {
			if (++comparision_count && v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}
