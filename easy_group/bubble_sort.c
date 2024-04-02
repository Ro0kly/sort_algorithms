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
    int array[n] = {2, 4 ,5 ,6 ,2, 1, 934, 632, 52 ,31};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int buff = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buff;
            }
        }
    }
    print_array(n, array);
    return 0;
}