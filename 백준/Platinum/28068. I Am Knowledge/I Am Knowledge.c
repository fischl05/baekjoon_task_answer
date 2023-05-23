#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int minus;
	int plus;
}BOOK;

BOOK sorted[100000];

int compare_as(BOOK* a, BOOK* b) {
	if (a->minus < b->minus) return 1;
	else if (a->minus > b->minus) return 0;
	else {
		if (a->plus > b->plus) return 1;
		else return 0;
	}
}

int compare_de(BOOK* a, BOOK* b) {
	if (a->plus < b->plus) return 1;
	else if (a->plus > b->plus) return 0;
	else {
		if (a->minus > b->minus) return 1;
		else return 0;
	}
}

void reverse(BOOK arr[], int len) {
	for (int i = 0; i < len / 2; i++) {
		BOOK temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

void merge(BOOK* arr, int start, int middle, int last, int (*compare)(BOOK* a, BOOK* b)) {
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

void merge_sort(BOOK* arr, int start, int last, int (*compare)(BOOK* a, BOOK* b)) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle, compare);
		merge_sort(arr, middle + 1, last, compare);
		merge(arr, start, middle, last, compare);
	}
}

// as = ai <= bi
// de = ai > bi
int main(void) {
	long long int happy = 0;
	int n, as_cnt = 0, de_cnt = 0;
	BOOK* arr = NULL;
	BOOK* as = NULL;
	BOOK* de = NULL;

	scanf("%d", &n);

	arr = (BOOK*)calloc(n, sizeof(BOOK));
	as = (BOOK*)calloc(n, sizeof(BOOK));
	de = (BOOK*)calloc(n, sizeof(BOOK));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].minus, &arr[i].plus);
		if (arr[i].minus <= arr[i].plus)
			as[as_cnt++] = arr[i];
		else
			de[de_cnt++] = arr[i];
	}
	
	merge_sort(as, 0, as_cnt - 1, compare_as);
	merge_sort(de, 0, de_cnt - 1, compare_de);
	reverse(de, de_cnt);
	
	int idx = 0;
	for (int i = 0; i < as_cnt; i++)
		arr[idx++] = as[i];
	for (int i = 0; i < de_cnt; i++)
		arr[idx++] = de[i];

	for (int i = 0; i < n; i++) {
		happy -= arr[i].minus;
		if (happy < 0) break;
		happy += arr[i].plus;
	}
	if (happy >= 0) printf("1");
	else printf("0");

	return 0;
}