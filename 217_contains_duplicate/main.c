#include <stdio.h>
#include <stdlib.h>

void _merge(int* arr, const int* left, const int* middle, const int* right) {
    printf("Do _merge: left: %d, middle: %d, right: %d\n", *left, *middle, *right);
    // temporary array to store sorted array
    int temp_len = right - left + 1;
    int temp[temp_len];

    int traceL = *left;
    int traceR = *middle;
    int tmp_index = 0;

    // Sort each halves to temp
    while (traceL < *middle || traceR < *right) {
        if (arr[traceL] < arr[traceR]) {
            temp[tmp_index] = arr[traceL];
            traceL += 1;
        } else {
            temp[tmp_index] = arr[traceR];
            traceR += 1;
        }
        tmp_index += 1;
    }

    // Put the remainning to temp
    while (traceL < *middle) {
        temp[tmp_index] = arr[traceL];
        traceL += 1;
    }

    while (traceR < *right) {
        temp[tmp_index] = arr[traceR];
        traceR += 1;
    }

    // Update the input
    tmp_index = *left;
    for (int i = 0; i <= temp_len; i++) {
        printf(">> Update the input array: arr[%d] = temp[%d] (value: %d)\n", tmp_index, i, temp[i]);
        arr[tmp_index] = temp[i];
    }
}

void _do_merge_sort(int* arr, int left, int right) {
    if (left < right) {
        int middle = (right - left) / 2 + left;

        _do_merge_sort(arr, left, middle);
        _do_merge_sort(arr, middle, right);

        _merge(arr, &left, &middle, &right);
    }
}

void merge_sort(int* arr, int arr_size) {
    _do_merge_sort(arr, 0, arr_size - 1);
}

int main() {
    // use sort algorithm then for loop one more to find the dupplicate
    int arr[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    merge_sort(arr, (sizeof(arr) / sizeof(arr[0])));
    return 0;
}