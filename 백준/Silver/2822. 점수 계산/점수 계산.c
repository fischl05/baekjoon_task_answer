#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	int idx;
}DATA;

DATA sorted[8];

int compare_value(DATA* a, DATA* b) {
	if (a->value >= b->value) return 1;
	else return 0;
}

int compare_idx(DATA* a, DATA* b) {
	if (a->idx < b->idx) return 1;
	else return 0;
}

void merge(DATA* arr, int start, int middle, int last, int (*compare)(DATA* a, DATA* b)) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (compare(&arr[i], &arr[j]))
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

void merge_sort(DATA* arr, int start, int last, int (*compare)(DATA* a, DATA* b)) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle, compare);
		merge_sort(arr, middle + 1, last, compare);
		merge(arr, start, middle, last, compare);
	}
}

int main(void) {
	int max = 0;
	DATA arr[8] = { 0 };

	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i].value);
		arr[i].idx = i;
	}

	merge_sort(arr, 0, 7, compare_value);

	max = arr[0].value + arr[1].value + arr[2].value + arr[3].value + arr[4].value;
	printf("%d\n", max);
	
	merge_sort(arr, 0, 4, compare_idx);

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i].idx + 1);

	return 0;
}