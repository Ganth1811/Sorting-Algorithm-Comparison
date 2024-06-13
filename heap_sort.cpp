#include "sorting_algorithm.h"

void heapify(vector<type>& v, int heapSize, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l < heapSize and v[l] > v[largest]) {
		largest = l;
	}
	if (r < heapSize and v[r] > v[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(v[i], v[largest]);
		heapify(v, heapSize, largest);
	}
}

void buildHeap(vector<type>& v, int heapSize) {
	for (int i = heapSize / 2 - 1; i >= 0; i--) {
		heapify(v, heapSize, i);
	}
}

void heapSort(vector<type>& v) {
	int heapSize = v.size();

	buildHeap(v, heapSize);
    for (int i = heapSize - 1; i >= 1; i--) {
		swap(v[i], v[0]);
		heapify(v, i, 0);
	}
}