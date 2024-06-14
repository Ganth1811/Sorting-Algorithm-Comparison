#include "sorting_algorithm.h"

void heapify(vector<type>& v, int heap_size, int i, int& comparision_count) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (++comparision_count && left < heap_size && ++comparision_count &&
		v[left] > v[largest]) {
		largest = left;
	}
	if (++comparision_count && right < heap_size && ++comparision_count &&
		v[right] > v[largest]) {
		largest = right;
	}
	if (++comparision_count && largest != i) {
		swap(v[i], v[largest]);
		heapify(v, heap_size, largest, comparision_count);
	}
}

void buildHeap(vector<type>& v, int heap_size, int& comparision_count) {
	for (int i = heap_size / 2 - 1; ++comparision_count && i >= 0; i--) {
		heapify(v, heap_size, i, comparision_count);
	}
}

void heapSort(vector<type>& v, int& comparision_count) {
	int heap_size = v.size();

	buildHeap(v, heap_size, comparision_count);
	for (int i = heap_size - 1; ++comparision_count && i >= 1; i--) {
		swap(v[i], v[0]);
		heapify(v, i, 0, comparision_count);
	}
}