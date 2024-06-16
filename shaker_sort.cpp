#include "sorting_algorithm.h"

void shakerSort(vector<type>& v, ull& comparision_count) {
    bool swapped = true;
    int left = 0, right = v.size() - 1;

    while (++comparision_count && swapped) {
        swapped = false;

        for (int i = left; ++comparision_count && i < right; i++) {
            if (++comparision_count && v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        if (++comparision_count && !swapped) break;
        swapped = false;

        --right;
        for (int i = right; ++comparision_count && i >= left; i--) {
            if (++comparision_count && v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        left++;
    }
}