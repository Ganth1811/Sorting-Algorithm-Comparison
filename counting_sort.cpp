#include "sorting_algorithm.h"

void countingSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();
	int max_element = v[0];
	for (int i = 1; ++comparison_count && i < size; i++) {
		if (++comparison_count && max_element < v[i]) {
			max_element = v[i];
		}
	}

	vector<int> count(max_element + 1, 0);
	for (int i = 0; ++comparison_count && i < size; i++) {
		count[v[i]]++;
	}

	for (int i = 1; ++comparison_count && i <= max_element; i++) {
		count[i] = count[i - 1] + count[i];
	}

	vector<type> res(size);
	for (int i = size - 1; ++comparison_count && i >= 0; i--) {
		res[count[v[i]] - 1] = v[i];
		count[v[i]]--;
	}

	swap(res, v);
}

void countingSort(vector<type>& v) {
	int size = v.size();
	int max_element = v[0];
	for (int i = 1; i < size; i++) {
		if (max_element < v[i]) {
			max_element = v[i];
		}
	}

	vector<int> count(max_element + 1, 0);
	for (int i = 0; i < size; i++) {
		count[v[i]]++;
	}

	for (int i = 1; i <= max_element; i++) {
		count[i] = count[i - 1] + count[i];
	}

	vector<type> res(size);
	for (int i = size - 1; i >= 0; i--) {
		res[count[v[i]] - 1] = v[i];
		count[v[i]]--;
	}

	swap(res, v);
}