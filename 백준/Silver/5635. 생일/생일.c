#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int date;
	char name[16];
}PERSON;

PERSON sorted[100];

int compare(PERSON* a, PERSON* b) {
	if (a->year < b->year) return 1;
	else if (a->year == b->year) {
		if (a->month < b->month) return 1;
		else if (a->month == b->month) {
			if (a->date < b->date) return 1;
		}
	}
	return 0;
}

void merge(PERSON* arr, int start, int middle, int last) {
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

void merge_sort(PERSON* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;
	PERSON* arr = NULL;

	scanf("%d", &n);

	arr = (PERSON*)calloc(n, sizeof(PERSON));
	for (int i = 0; i < n; i++)
		scanf("%s %d %d %d", arr[i].name, &arr[i].date, &arr[i].month, &arr[i].year);

	merge_sort(arr, 0, n - 1);

	printf("%s\n%s", arr[n - 1].name, arr[0].name);

	free(arr);
	return 0;
}