#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int n, int arr[n]) {
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			printf("%d\n", arr[i]);
		} else {
			printf("%d ", arr[i]);
		}
	}
}

int get_random(int lower, int upper) {
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int main() {
	srand(time(0));
	const int n = get_random(10, 10);
	int array[n];
	for (int i = 0; i < n; i++) {
		array[i] = get_random(0, 100);
	}
    
    clock_t time;
	time = clock();
	for (int i = 1; i < n; i++) {
		int buff_i = i;
		for (int j = i - 1; j >= 0 && array[j] > array[buff_i]; j--) {
			if (array[j] > array[buff_i]) {
				int buff = array[buff_i];
				array[buff_i] = array[j];
				array[j] = buff;
				buff_i -= 1;
			} else {
				break;
			}
		}
	}

	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");

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