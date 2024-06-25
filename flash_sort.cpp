#include "sorting_algorithm.h"

void flashSort(vector<type>& v, ull& comparision_count) {
	int max = 0, min = v[0];
	int size = v.size();
	int m = size * 0.45;
	vector<int> L(m, 0);

	for (int i = 1; ++comparision_count && i < size; i++) {
		if (++comparision_count && v[i] < min) {
			min = v[i];
		} else if (++comparision_count && v[i] > v[max]) {
			max = i;
		}
	}

	double c = (double) (m - 1) / (v[max] - min);
	for (int i = 0; ++comparision_count && i < size; i++) {
		int k = (v[i] - min) * c;
		L[k]++;
	}
	for (int i = 1; ++comparision_count && i < m; i++) {
		L[i] = L[i - 1] + L[i];
	}
    swap(v[max], v[0]);

	int count = 0, i = 0;
	int k = m - 1;

	while (++comparision_count && count < size - 1) {
		while (++comparision_count && i > L[k] - 1) {
			i++;
			k = (v[i] - min) * c;
		}

		int flash = v[i];
		while (++comparision_count && i != L[k]) {
			k = (flash - min) * c;
			swap(flash, v[L[k] - 1]);

			L[k]--;
			count++;
		}
	}

    insertionSort(v, comparision_count);
}