#include "sorting_algorithm.h"

void merge(vector<type>& v, int l, int mid, int r,
		   ull& comparison_count) {
	int left_size = mid - l + 1;
	int right_size = r - mid;

	vector<type> left(left_size), right(right_size);
	for (int i = 0; ++comparison_count && i < left_size; i++) {
		left[i] = v[l + i];
	}
	for (int i = 0; ++comparison_count && i < right_size; i++) {
		right[i] = v[mid + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (++comparison_count && i < left_size && ++comparison_count && j < right_size) {
		if (++comparison_count && left[i] <= right[j]) {
			v[k++] = left[i++];
		} else {
			v[k++] = right[j++];
		}
	}

	while (++comparison_count && i < left_size) {
		v[k++] = left[i++];
	}

	while (++comparison_count && j < right_size) {
		v[k++] = right[j++];
	}
}

void mergeSort(vector<type>& v, int l, int r, ull& comparison_count) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	
	mergeSort(v, l, mid, comparison_count);
	mergeSort(v, mid + 1, r, comparison_count);
	merge(v, l, mid, r, comparison_count);
}

void mergeSort(vector<type>& v, ull& comparison_count) {
	mergeSort(v, 0, v.size() - 1, comparison_count);
}

void merge(vector<type>& v, int l, int mid, int r) {
	int left_size = mid - l + 1;
	int right_size = r - mid;

	vector<type> left(left_size), right(right_size);
	for (int i = 0; i < left_size; i++) {
		left[i] = v[l + i];
	}
	for (int i = 0; i < right_size; i++) {
		right[i] = v[mid + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (i < left_size && j < right_size) {
		if (left[i] <= right[j]) {
			v[k++] = left[i++];
		} else {
			v[k++] = right[j++];
		}
	}

	while (i < left_size) {
		v[k++] = left[i++];
	}

	while (j < right_size) {
		v[k++] = right[j++];
	}
}

void mergeSort(vector<type>& v, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	
	mergeSort(v, l, mid);
	mergeSort(v, mid + 1, r);
	merge(v, l, mid, r);
}

void mergeSort(vector<type>& v) {
	mergeSort(v, 0, v.size() - 1);
}