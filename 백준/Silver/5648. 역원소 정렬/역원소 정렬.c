#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int StringToInt(char str[]) {
	int len = strlen(str);
	long long int num = 0;
	for (int i = 0; i < len; i++) {
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

void reverse(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

long long int sorted[1000000];

void merge(long long int* arr, int start, int middle, int last) {
	int i = start, j = middle + 1, k = start;
	while (i <= middle && j <= last) {
		if (arr[i] < arr[j])
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

void merge_sort(long long int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;
	long long int* arr = NULL;

	scanf("%d", &n);

	arr = (long long int*)calloc(n, sizeof(long long int));

	for (int i = 0; i < n; i++) {
		char str[14] = { 0 };
		scanf("%s", str);
		reverse(str);
		arr[i] = StringToInt(str);
	}

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%lld\n", arr[i]);

	free(arr);
	return 0;
}
