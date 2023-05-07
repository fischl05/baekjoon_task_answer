#include <stdio.h>
#include <stdlib.h>

int sorted[1000];

void merge_sort(int* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (arr[i] < arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
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

void merge(int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge(arr, start, middle);
		merge(arr, middle + 1, last);
		merge_sort(arr, start, middle, last);
	}
}

int main(void) {
	int n, m;
	int money = 0, idx = 0;

	scanf("%d %d", &n, &m);
	int* arr = (int*)calloc(sizeof(int), m);
	
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	merge(arr, 0, m - 1);
	
	for (int i = 0; i < m; i++) {
		int egg = n;
		int cnt = 0;
		int j = i;
		while (egg > 0 && j < m) {
			if (arr[j] >= arr[i]) {
				cnt += arr[i];
				egg--;
				j++;
			}
		}
		if (cnt > money) {
			money = cnt;
			idx = i;
		}
	}
	printf("%d %d", arr[idx], money);

	return 0;
}