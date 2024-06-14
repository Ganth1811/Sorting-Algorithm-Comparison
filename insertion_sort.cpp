#include "sorting_algorithm.h"

void insertionSort(vector<type>& v, unsigned long long& comparision_count) {
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