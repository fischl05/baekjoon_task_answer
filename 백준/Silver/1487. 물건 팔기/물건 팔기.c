#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pay;
	int minus;
}DATA;

DATA sorted[50];

int compare(DATA* a, DATA* b) {
	if (a->pay < b->pay) return 1;
	else if (a->pay == b->pay) {
		if (a->minus < b->minus) return 1;
	}
	else return 0;
}

void merge(DATA* arr, int start, int middle, int last) {
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

void merge_sort(DATA* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n, money = 0, max = 0, max_idx = 0;
	DATA* arr = NULL;

	scanf("%d", &n);

	arr = (DATA*)calloc(n, sizeof(DATA));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].pay, &arr[i].minus);
		if (arr[i].pay > money) money = arr[i].pay;
	}

	merge_sort(arr, 0, n - 1);
	
	for (int i = 0; i <= money; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j].pay >= i) {
				int num = i - arr[j].minus;
				if (num > 0) sum += num;
			}
		}
		if (sum > max) {
			max = sum;
			max_idx = i;
		}
	}
	printf("%d\n", max_idx);

	return 0;
}