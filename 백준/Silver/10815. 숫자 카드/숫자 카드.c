#include <stdio.h>
#include <stdlib.h>

int sorted[500000];

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

int bin_search(int* arr, int start, int last, int goal) {
	if (start > last) return 0;
	int middle = (start + last) / 2;
	if (arr[middle] == goal) return 1;
	else {
		if (arr[middle] > goal) return bin_search(arr, start, middle - 1, goal);
		else return bin_search(arr, middle + 1, last, goal);
	}
}

int main(void) {
	int n, m;
	int* arr = NULL;
	int* find = NULL;

	scanf("%d", &n);
	arr = (int*)calloc(sizeof(int), n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	find = (int*)calloc(sizeof(int), m);

	for (int i = 0; i < m; i++)
		scanf("%d", &find[i]);

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < m; i++)
		printf("%d ", bin_search(arr, 0, n - 1, find[i]));

	free(arr);
	free(find);
	return 0;
}