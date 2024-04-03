#include <stdio.h>
#include <stdlib.h>

void print_array(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

void sort(int n, int* arr) {
    int i = 0;
    int j = n - 1;
    int pivot = arr[n / 2];
    do {
        while(arr[i] < pivot) { i++; }
        while(arr[j] > pivot) { j--; }
        if (i <= j) {
            int buff = arr[i];
            arr[i] = arr[j];
            arr[j] = buff;
            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        sort(j + 1, &arr[0]);
    }
    if (i < n) {
        sort(n - i, &arr[i]);
    }
}

int main() {
    const int n = 10;
    int array[n] = {15, 2, 33, 81, 4, 1, 5, 0, 89 ,102};
    sort(n, array);
    print_array(n, array);
    return 0;
}