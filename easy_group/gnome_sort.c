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
    int index = 1;
    int buff_i = 0;
    while (index < n) {
        if (array[index - 1] < array[index]) {
            index = buff_i;
            buff_i += 1;
        } else {
            int buff = array[index];
            array[index] = array[index - 1];
            array[index - 1] = buff;
            index -= 1;
            if (index == 0) {
                index = buff_i;
                buff_i += 1;
            }
        }
    }

    print_array(n, array);
    
    return 0;
}