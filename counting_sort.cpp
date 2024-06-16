#include "sorting_algorithm.h"

void countingSort(vector<type>& v, ull& comparision_count) {
    int size = v.size();
    int max_element = v[0];
    for (int i = 1; ++comparision_count && i < size; i++) {
        if (++comparision_count && max_element < v[i]) {
            max_element = v[i];
        }
    }

    vector<int> count(max_element + 1, 0);
    for (int i = 0; ++comparision_count && i < size; i++) {
        count[v[i]]++;
    }

    for (int i = 1; ++comparision_count && i <= max_element; i++) {
        count[i] = count[i - 1] + count[i];
    }

    vector<type> res(size);
    for (int i = size - 1; ++comparision_count && i >= 0; i--) {
        res[count[v[i]] - 1] = v[i];
    }

    swap(res, v);
}