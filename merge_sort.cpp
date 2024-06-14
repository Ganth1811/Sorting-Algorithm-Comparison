#include "sorting_algorithm.h"

void merge(vector<type> a, vector<type> b, vector<type>& v,
		   int& comparision_count) {
	v.clear();

	int i = 0, j = 0;
	while (++comparision_count && i < a.size() && ++comparision_count &&
		   j < b.size()) {
		if (++comparision_count && a[i] < b[j]) {
			v.push_back(a[i]);
			i++;
		} else {
			v.push_back(b[j]);
			j++;
		}
	}

	while (++comparision_count && i < a.size()) {
		v.push_back(a[i]);
		i++;
	}

	while (++comparision_count && j < b.size()) {
		v.push_back(b[j]);
		j++;
	}
}

void MergeSort(vector<type>& v, int& comparision_count) {
	int size = v.size();

	if (size > 1) {
		vector<type> a(v.begin(), v.begin() + size / 2);
		vector<type> b(v.begin() + size / 2, v.end());

		mergeSort(a, comparision_count);
		mergeSort(b, comparision_count);
		merge(a, b, v, comparision_count);
	}
}