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

void sort(int n, int *arr) {
	int i = 0;
	int j = n - 1;
	int pivot = arr[n / 2];
	do {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			int buff = arr[i];
			arr[i] = arr[j];
			arr[j] = buff;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		sort(j + 1, &arr[0]);
	}
	if (i < n) {
		sort(n - i, &arr[i]);
	}
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

	clock_t time;
	time = clock();

	sort(n, array);

	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");
	return 0;
}