#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
        temp[k++] = arr[i++];
        else
        temp[k++] = arr[j++];
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
    int m = (l + r) / 2;

    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    }

    return 0;
}
