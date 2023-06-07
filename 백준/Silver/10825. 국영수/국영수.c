#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[11];
	int kor, eng, math;
}STUDENT;

STUDENT sorted[100000];

int compare(STUDENT* a, STUDENT* b) {
	if (a->kor > b->kor) return 1;
	else if (a->kor == b->kor) {
		if (a->eng < b->eng) return 1;
		else if (a->eng == b->eng) {
			if (a->math > b->math) return 1;
			else if (a->math == b->math) {
				if (strcmp(b->name, a->name) > 0) return 1;
			}
		}
	}
	return 0;
}

void merge(STUDENT* arr, int start, int middle, int last) {
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

void merge_sort(STUDENT* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;
	STUDENT* arr = NULL;
	
	scanf("%d", &n);

	arr = (STUDENT*)calloc(n, sizeof(STUDENT));
	for (int i = 0; i < n; i++)
		scanf("%s %d %d %d", arr[i].name, &arr[i].kor, &arr[i].eng, &arr[i].math);

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i].name);

	return 0;
}