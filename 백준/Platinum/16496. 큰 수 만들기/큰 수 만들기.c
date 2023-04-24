#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char str[31];
}STR;

int str_compare(const void* mem1, const void* mem2) {
	STR* a = (STR*)mem1;
	STR* b = (STR*)mem2;
	char string1[31];
	char string2[31];
	uint64_t num[2] = { 0 };

	strcpy(string1, a->str);
	strcat(string1, b->str);

	strcpy(string2, b->str);
	strcat(string2, a->str);

	if (strcmp(string1, string2) > 0) return 1;
	else return 0;
}

STR sorted_arr[1000];

void merge(STR* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (str_compare(&arr[i], &arr[j])) {
			sorted_arr[k] = arr[i];
			i++;
		}
		else {
			sorted_arr[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= last ; t++)
			sorted_arr[k++] = arr[t];
	}
	else {
		for (int t = i; t <= middle; t++)
			sorted_arr[k++] = arr[t];
	}
	for (int t = start; t <= last; t++)
		arr[t] = sorted_arr[t];
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
	int n, idx = 0;
	STR* str;

	scanf("%d", &n);

	str = (STR*)calloc(sizeof(STR), n);

	for (int i = 0; i < n; i++) {
		int len = 0;
		scanf("%s", str[i].str);
	}

	merge_sort(str, 0, n - 1);
	
	while (str[idx].str[0] == '0') idx++;
	if (idx == n) idx--;

	for (int i = idx; i < n; i++)
		printf("%s", str[i].str);

	free(str);
	return 0;
}