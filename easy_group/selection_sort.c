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

	const int n = get_random(10, 10);
	int array[n];
	for (int i = 0; i < n; i++) {
		array[i] = get_random(0, 100);
	}
    
    clock_t time;
	time = clock();

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

	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");

    return 0;
}