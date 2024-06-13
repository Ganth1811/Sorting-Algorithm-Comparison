#include "sorting_algorithm.h"

void merge(vector<type> a, vector<type> b, vector<type>& v) {
    v.clear();

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            v.push_back(a[i]);
            i++;
        } else {
            v.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        v.push_back(a[i]);
        i++;
    }

     while (j < b.size()) {
        v.push_back(b[j]);
        j++;
    }
}

void mergeSort(vector<type> &v) {
    int n = v.size();
    if (n > 1) {
        vector<type> a(v.begin(), v.begin() + n / 2);
        vector<type> b(v.begin() + n /2, v.end());

        mergeSort(a);
        mergeSort(b);
        merge(a, b, v);        
    }
}