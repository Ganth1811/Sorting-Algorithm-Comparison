#include "sorting_algorithm.h"

void shakerSort(vector<type>& v, ull& comparison_count) {
    bool swapped = true;
    int left = 0, right = v.size() - 1;

    while (++comparison_count && swapped) {
        swapped = false;

        for (int i = left; ++comparison_count && i < right; i++) {
            if (++comparison_count && v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        if (++comparison_count && !swapped) break;
        swapped = false;

        --right;
        for (int i = right; ++comparison_count && i >= left; i--) {
            if (++comparison_count && v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        left++;
    }
}

void shakerSort(vector<type>& v) {
    bool swapped = true;
    int left = 0, right = v.size() - 1;

    while (swapped) {
        swapped = false;

        for (int i = left; i < right; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
        swapped = false;

        --right;
        for (int i = right; i >= left; i--) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        left++;
    }
}