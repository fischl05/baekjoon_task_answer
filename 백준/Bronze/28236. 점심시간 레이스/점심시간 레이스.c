#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	int class;
	int f, d, len;
}CLASS;

CLASS sorted[100000];

int compare(CLASS* a, CLASS* b) {
	if (a->len < b->len) return 1;
	else if (a->len == b->len) {
		if (a->class < b->class) return 1;
	}
	else return 0;
}

void merge(CLASS* arr, int start, int middle, int last) {
	int i = start, j = middle + 1, k = start;
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

void merge_sort(CLASS* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n, m, k;
	CLASS* arr = NULL;

	scanf("%d %d %d", &n, &m, &k);

	arr = (CLASS*)calloc(k, sizeof(CLASS));
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &arr[i].f, &arr[i].d);
		arr[i].class = i + 1;
		arr[i].len = abs(m - arr[i].d);
		arr[i].len += arr[i].f - 1;
	}

	merge_sort(arr, 0, k - 1);

	printf("%d\n", arr[0].class);

	return 0;
}