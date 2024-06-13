#include "sorting_algorithm.h"

void countingSort(vector<type>& v, int exp) {
    vector<type> res(v.size());
    vector<int> count(10, 0);

    for (int i = 0; i < v.size(); i++) {
        count[(v[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] = count[i - 1] + count[i];
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        res[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    swap(res, v);
}

void radixSort(vector<type>& v) {
    int m = v[0]; // Assume that input is all nonnegative intergers
    for (int i = 1; i < v.size(); i++) {
        if (m < v[i]) m = v[i];
    }

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(v, exp);
    }
}