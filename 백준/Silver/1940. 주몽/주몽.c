#include <stdio.h>
#include <stdlib.h>

int sorted[15000];

void merge(int* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (arr[i] < arr[j])
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
	int n, m, cnt = 0;
	int* arr = NULL;

	scanf("%d", &n);
	scanf("%d", &m);
	
	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == m) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	
	return 0;
}