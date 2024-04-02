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
    for (int i = 1; i < n; i++) {
        int buff_i = i;
        for (int j = i - 1; j >= 0 && array[j] > array[buff_i]; j--) {
            printf("\n%d - %d\n", array[buff_i], array[j]);
            if (array[j] > array[buff_i]) {
                int buff = array[buff_i];
                array[buff_i] = array[j];
                array[j] = buff;
                buff_i -= 1;
            } else {
                break;
            }
            print_array(n, array);
        }
        printf("\n");
    }
    print_array(n, array);
    return 0;
}

// int main() {
//     const int n = 10;
//     int array[n] = {6, 4 ,5 ,0 ,2, 1, 934, 632, 52 ,31};
//     for (int i = 1; i < n; i++) {
//         int buff_i = i;
//         while (buff_i >= 0 && array[buff_i - 1] > array[buff_i]) {
//             int buff = array[buff_i];
//             array[buff_i] = array[buff_i - 1];
//             array[buff_i - 1] = buff;
//             buff_i -= 1;
//         }
//         print_array(n, array);
//         printf("\n");
//     }
//     print_array(n, array);
//     return 0;
// }

// Показать как выглядит алгоритм
// Показать модификацию с брейк
// Показать модификацию синтаксическу - вынести if в условия
// Потом показать вариант с while где пропадает дополнительная j