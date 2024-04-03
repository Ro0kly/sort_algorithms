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
	const int n = get_random(100, 100);
	int array[n];
	for (int i = 0; i < n; i++) {
		array[i] = get_random(0, 100);
	}

	clock_t time;
	time = clock();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int buff = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buff;
			}
		}
	}
	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------\n");

	return 0;
}