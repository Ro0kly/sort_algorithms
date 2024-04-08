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

    array[4] = 500;
    array[500] = 4;
    int middle = n / 2;

    clock_t time;
	time = clock();

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
	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");
    return 0;
}