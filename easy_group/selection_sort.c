#include <stdio.h>

void print_array(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    const int n = 10;
    int array[n] = {6, 4 ,5 ,0 ,2, 1, 934, 632, 52 ,31};
    for (int i = 0; i < n; i++) {
        int min_value = array[i];
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (min_value > array[j]) {
                min_value = array[j];
                min_index = j;
            }
        }
        int buff = array[i];
        array[i] = min_value;
        array[min_index] = buff;
    }
    print_array(n, array);
    return 0;
}