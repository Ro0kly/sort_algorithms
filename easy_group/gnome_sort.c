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
	const int n = get_random(100000, 100000);
	int array[n];
	for (int i = 0; i < n; i++) {
		array[i] = get_random(0, 100);
	}
	clock_t time;
	time = clock();
	int index = 1;
	int buff_i = 1;
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

	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");

	return 0;
}