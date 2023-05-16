#include <stdio.h>
#include <stdlib.h>

int sorted[100];

void merge(int* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (arr[i] > arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > middle)
		for (int t = j; t <= last; t++)
			sorted[k++] = arr[t];
	else
		for (int t = i; t <= middle; t++)
			sorted[k++] = arr[t];
	for (int t = start; t <= last; t++)
		arr[t] = sorted[t];
}

void merge_sort(int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n, out = 0;
	int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > 1440) {
			printf("-1");
			return 0;
		}
	}
	
	merge_sort(arr, 0, n - 1);

	while (arr[0] > 0) {
		if (arr[0] > 0) {
			arr[0] -= 1;
			if (n >= 2)
				if (arr[1] > 0) arr[1] -= 1;
			out++;
		}
		merge_sort(arr, 0, n - 1);
	}
	if (out > 1440) printf("-1");
	else printf("%d", out);

	free(arr);
	return 0;
}