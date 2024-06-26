#include "sorting_algorithm.h"

void shellSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();

	for (int gap = size / 2; ++comparison_count && gap > 0; gap /= 2) {
		for (int i = gap; ++comparison_count && i < size; i++) {
			int key = v[i];
			int j = i - gap;

			while (++comparison_count && j >= 0 && ++comparison_count &&
				   v[j] > key) {
				v[j + gap] = v[j];
				j = j - gap;
			}
			v[j + gap] = key;
		}
	}
}

void shellSort(vector<type>& v) {
	int size = v.size();

	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int key = v[i];
			int j = i - gap;

			while (j >= 0 && v[j] > key) {
				v[j + gap] = v[j];
				j = j - gap;
			}
			v[j + gap] = key;
		}
	}
}