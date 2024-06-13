#include "sorting_algorithm.h"

void selectionSort(vector<double> &v){
    int n = v.size();
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (v[j] < v[min])
                min = j;
        }

        if (min != i) 
            swap(v[i], v[min]);
    }
}