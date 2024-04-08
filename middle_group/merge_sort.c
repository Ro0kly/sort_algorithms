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

void sort(int n, int l, int r, int a[n]) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;

	sort(n, l, mid, a);
	sort(n, mid + 1, r, a);
	int i = l;
	int j = mid + 1;
	int buff[r];
	for (int step = 0; step < r - l + 1; step++) {
		if ((j > r) || ((i <= mid) && (a[i] < a[j]))) {
			buff[step] = a[i];
			i++;
		} else {
			buff[step] = a[j];
			j++;
		}
	}
	for (int step = 0; step < r - l + 1; step++) {
		a[l + step] = buff[step];
	}
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

	sort(n, 0, n - 1, array);

	time = clock() - time;
	printf("--------------------\n");
	printf("Result: ");
	print_array(n, array);
	printf("Time of produce (sec): %f\n", (double)time / CLOCKS_PER_SEC);
	printf("--------------------");
}
