#include "sorting_algorithm.h"

void selectionSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();
	
	for (int i = 0; ++comparison_count && i < size - 1; i++) {
		int min_id = i;

		for (int j = i + 1; ++comparison_count && j < size; j++) {
			if (++comparison_count && v[j] < v[min_id]) {
                min_id = j;
            }
		}

		if (++comparison_count && min_id != i) {
            swap(v[i], v[min_id]);
        }
	}
}

void selectionSort(vector<type>& v) {
	int size = v.size();
	
	for (int i = 0; i < size - 1; i++) {
		int min_id = i;

		for (int j = i + 1; j < size; j++) {
			if (v[j] < v[min_id]) {
                min_id = j;
            }
		}

		if (min_id != i) {
            swap(v[i], v[min_id]);
        }
	}
}