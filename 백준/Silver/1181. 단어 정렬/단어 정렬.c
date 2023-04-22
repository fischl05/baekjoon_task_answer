#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char str[51];
	int len;
}STR;

STR sorted[20001];

int compare_item(STR* a, STR* b) {
	if (a->len > b->len) return 1;
	else if (a->len < b->len) return 0;
	else {
		if (strcmp(a->str, b->str) > 0) return 1;
		else return 0;
	}
	return 0;
}

void merge(STR* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= last) {
		if (compare_item(&arr[i], &arr[j])) {
			sorted[k] = arr[j];
			j++;
		}
		else {
			sorted[k] = arr[i];
			i++;
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

void merge_sort(STR* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	STR* arr = (STR*)calloc(sizeof(STR), n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i].str);
		arr[i].len = strlen(arr[i].str);
	}

	merge_sort(arr, 0, n - 1);
	
	printf("%s\n", arr[0].str);
	for (int i = 1; i < n; i++) {
		if(strcmp(arr[i].str, arr[i - 1].str) != 0) printf("%s\n", arr[i].str);
	}

	free(arr);
	return 0;
}