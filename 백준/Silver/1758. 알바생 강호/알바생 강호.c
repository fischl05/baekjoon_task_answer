#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int sorted[100000];

void merge_sort(int* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (arr[i] > arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= last; t++)
			sorted[k++] = arr[t];
	}
	else {
		for (int t = i; t <= middle; t++)
			sorted[k++] = arr[t];
	}
	for (int t = start; t <= last; t++)
		arr[t] = sorted[t];
}

void merge(int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge(arr, start, middle);
		merge(arr, middle + 1, last);
		merge_sort(arr, start, middle, last);
	}
}

int main(void) {
	int n;
	uint64_t tip = 0;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		arr[i] -= i;
		if (arr[i] < 0) break;
		else tip += arr[i];
	}
	printf("%lld", tip);

	return 0;
}