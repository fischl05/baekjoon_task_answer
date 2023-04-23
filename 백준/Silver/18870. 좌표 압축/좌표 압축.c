#include <stdio.h>
#include <stdlib.h>

int sorted[1000000];

int compare_item(int* a, int* b) {
	if (*a >= *b) return 1;
	else return 0;
}

void merge(int* arr, int start, int middle, int last) {
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

void merge_sort(int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int BinSearch(int* arr, int start, int last, int num) {
	int middle = (start + last) / 2;
	if (start > last) return -1;
	else if (arr[middle] == num) return middle;
	else {
		if (num > arr[middle])
			return BinSearch(arr, middle + 1, last, num);
		else
			return BinSearch(arr, start, middle - 1, num);
	}
}

//int BinSearch(int* arr, int start, int last, int num) {
//	while (start <= last) {
//		int middle = (start + last) / 2;
//		if (arr[middle] == num) return middle;
//		if (num > arr[middle]) start = middle + 1;
//		else last = middle - 1;
//	}
//	return -1;
//}

int main(void) {
	int n;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	int* sorted_arr = (int*)calloc(sizeof(int), n);
	int* arr_buf = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sorted_arr[i] = arr[i];
	}

	merge_sort(sorted_arr, 0, n - 1);
	
	arr_buf[0] = sorted_arr[0];
	int j = 1;
	for (int i = 1; i < n; i++)
		if (arr_buf[j - 1] != sorted_arr[i]) {
			arr_buf[j++] = sorted_arr[i];
		}

	for (int i = 0; i < n; i++)
		printf("%d ", BinSearch(arr_buf, 0, j, arr[i]));

	free(arr);
	free(sorted_arr);
	free(arr_buf);
	return 0;
}