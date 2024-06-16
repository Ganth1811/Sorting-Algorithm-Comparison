#include "sorting_algorithm.h"

void shellSort(vector<type>& v, ull& comparision_count) {
    int size = v.size();

	for (int gap = size / 2; ++comparision_count && gap > 0; gap /= 2) {
		for (int i = gap; ++comparision_count && i < size; i++) {
			int key = v[i];
			int j = i - gap;

			while (++comparision_count && j >= 0 && ++comparision_count &&
				   v[j] > key) {
				v[j + gap] = v[j];
				j = j - gap;
			}
			v[j + gap] = key;
		}
	}
}