#include "sorting_algorithm.h"

void heapify(vector<type>& v, int heap_size, int i, ull& comparison_count) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (++comparison_count && left < heap_size && ++comparison_count &&
		v[left] > v[largest]) {
		largest = left;
	}
	if (++comparison_count && right < heap_size && ++comparison_count &&
		v[right] > v[largest]) {
		largest = right;
	}
	if (++comparison_count && largest != i) {
		swap(v[i], v[largest]);
		heapify(v, heap_size, largest, comparison_count);
	}
}

void buildHeap(vector<type>& v, int heap_size, ull& comparison_count) {
	for (int i = heap_size / 2 - 1; ++comparison_count && i >= 0; i--) {
		heapify(v, heap_size, i, comparison_count);
	}
}

void heapSort(vector<type>& v, ull& comparison_count) {
	int heap_size = v.size();

	buildHeap(v, heap_size, comparison_count);
	for (int i = heap_size - 1; ++comparison_count && i >= 1; i--) {
		swap(v[i], v[0]);
		heapify(v, i, 0, comparison_count);
	}
}

void heapify(vector<type>& v, int heap_size, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if ( left < heap_size && 
		v[left] > v[largest]) {
		largest = left;
	}
	if ( right < heap_size && 
		v[right] > v[largest]) {
		largest = right;
	}
	if ( largest != i) {
		swap(v[i], v[largest]);
		heapify(v, heap_size, largest);
	}
}

void buildHeap(vector<type>& v, int heap_size) {
	for (int i = heap_size / 2 - 1;  i >= 0; i--) {
		heapify(v, heap_size, i);
	}
}

void heapSort(vector<type>& v) {
	int heap_size = v.size();

	buildHeap(v, heap_size);
	for (int i = heap_size - 1;  i >= 1; i--) {
		swap(v[i], v[0]);
		heapify(v, i, 0);
	}
}