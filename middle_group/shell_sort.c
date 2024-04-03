#include <stdio.h>

void print_array(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    const int n = 10;
    int array[n] = {15, 2 , 33, 81, 4, 1, 5, 0, 89 ,102};
    int middle = n / 2;

    while (middle > 0) {
        for (int i = 0; i < n - middle; i++) {
            int j = i;
            while (j >= 0 && array[j] > array[j + middle]) {
                int buff = array[j];
                array[j] = array[j + middle];
                array[j + middle] = buff;
                j -= middle;
            }
        }
        middle /= 2;
    }

    print_array(n, array);
    return 0;
}