#include "sorting_algorithm.h"

void bubbleSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();

	for (int i = 0; ++comparison_count && i < size - 1; i++) {
		for (int j = 0; ++comparison_count && j < size - 1 - i; j++) {
			if (++comparison_count && v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

void optimizedBubbleSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();
	bool swapped;

	for (int i = 0; ++comparison_count && i < size - 1; i++) {
		swapped = false;
		for (int j = 0; ++comparison_count && j < size - 1 - i; j++) {
			if (++comparison_count && v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}

		if (++comparison_count && swapped == false) break;
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

void optimizedBubbleSort(vector<type>& v) {
	int size = v.size();
	bool swapped;

	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}
		
		if (swapped == false) break;
	}
}