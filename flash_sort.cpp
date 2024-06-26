#include "sorting_algorithm.h"

void flashSort(vector<type>& v, ull& comparison_count) {
	int max = 0, min = v[0];
	int size = v.size();
	int m = size * 0.45;
	vector<int> L(m, 0);

	for (int i = 1; ++comparison_count && i < size; i++) {
		if (++comparison_count && v[i] < min) {
			min = v[i];
		} else if (++comparison_count && v[i] > v[max]) {
			max = i;
		}
	}

	double c = (double)(m - 1) / (v[max] - min);
	for (int i = 0; ++comparison_count && i < size; i++) {
		int k = (v[i] - min) * c;
		L[k]++;
	}
	for (int i = 1; ++comparison_count && i < m; i++) {
		L[i] = L[i - 1] + L[i];
	}
	swap(v[max], v[0]);

	int count = 0, i = 0;
	int k = m - 1;

	while (++comparison_count && count < size - 1) {
		while (++comparison_count && i > L[k] - 1) {
			i++;
			k = (v[i] - min) * c;
		}

		int flash = v[i];
		while (++comparison_count && i != L[k]) {
			k = (flash - min) * c;
			swap(flash, v[L[k] - 1]);

			L[k]--;
			count++;
		}
	}

	insertionSort(v, comparison_count);
}

void flashSort(vector<type>& v) {
	int max = 0, min = v[0];
	int size = v.size();
	int m = size * 0.45;
	vector<int> L(m, 0);

	for (int i = 1; i < size; i++) {
		if (v[i] < min) {
			min = v[i];
		} else if (v[i] > v[max]) {
			max = i;
		}
	}

	double c = (double)(m - 1) / (v[max] - min);
	for (int i = 0; i < size; i++) {
		int k = (v[i] - min) * c;
		L[k]++;
	}
	for (int i = 1; i < m; i++) {
		L[i] = L[i - 1] + L[i];
	}
	swap(v[max], v[0]);

	int count = 0, i = 0;
	int k = m - 1;

	while (count < size - 1) {
		while (i > L[k] - 1) {
			i++;
			k = (v[i] - min) * c;
		}

		int flash = v[i];
		while (i != L[k]) {
			k = (flash - min) * c;
			swap(flash, v[L[k] - 1]);

			L[k]--;
			count++;
		}
	}

	insertionSort(v);
}