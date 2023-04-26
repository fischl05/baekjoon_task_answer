#include <stdio.h>
#include <stdlib.h>

int compare_item(int* a, int* b) {
	return *b - *a;
}

int main(void) {
	int n, max = 0;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort((int*)arr, n, sizeof(int), compare_item);

	for (int i = 0; i < n; i++) {
		arr[i] += i + 1;
		if (max < arr[i]) max = arr[i];
	}
	printf("%d", max + 1);

	return 0;
}