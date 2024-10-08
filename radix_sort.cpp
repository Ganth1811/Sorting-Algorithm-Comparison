#include "sorting_algorithm.h"

void countingSort(vector<type>& v, int exp, ull& comparison_count) {
	int size = v.size();
	vector<type> res(size);
	vector<int> count(10, 0);

	for (int i = 0; ++comparison_count && i < size; i++) {
		count[(v[i] / exp) % 10]++;
	}

	for (int i = 1; ++comparison_count && i < 10; i++) {
		count[i] = count[i - 1] + count[i];
	}

	for (int i = size - 1; ++comparison_count && i >= 0; i--) {
		res[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}

	swap(res, v);
}

void radixSort(vector<type>& v, ull& comparison_count) {
	int size = v.size();
	int max_element = v[0];	 // Assume that input is all nonnegative intergers

	for (int i = 1; ++comparison_count && i < size; i++) {
		if (++comparison_count && max_element < v[i]) {
			max_element = v[i];
		}
	}

	for (int exp = 1; ++comparison_count && max_element / exp > 0; exp *= 10) {
		countingSort(v, exp, comparison_count);
	}
}

void countingSort(vector<type>& v, int exp) {
	int size = v.size();
	vector<type> res(size);
	vector<int> count(10, 0);

	for (int i = 0; i < size; i++) {
		count[(v[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] = count[i - 1] + count[i];
	}

	for (int i = size - 1; i >= 0; i--) {
		res[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}

	swap(res, v);
}

void radixSort(vector<type>& v) {
	int size = v.size();
	int max_element = v[0];	 // Assume that input is all nonnegative intergers

	for (int i = 1; i < size; i++) {
		if (max_element < v[i]) {
			max_element = v[i];
		}
	}

	for (int exp = 1; max_element / exp > 0; exp *= 10) {
		countingSort(v, exp);
	}
}