#include <stdio.h>

double sorted[101];

void merge(double* arr, int start, int middle, int last) {
	int i = start, j = middle + 1, k = start;
	while (i <= middle && j <= last) {
		if (arr[i] > arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
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

void merge_sort(double* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n, m, k;
	double arr[101] = { 0.0 };
	double out = 0.0;

	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int idx;
			double value;
			scanf("%d %lf", &idx, &value);
			if (value > arr[idx]) arr[idx] = value;
		}
	}

	merge_sort(arr, 0, 100);
	
	for (int i = 0; i < k; i++)
		out += arr[i];

	printf("%.1lf", out);

	return 0;
}