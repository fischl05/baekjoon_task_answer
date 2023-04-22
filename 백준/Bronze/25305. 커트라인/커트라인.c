#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);
	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[j] < arr[i]) swap(&arr[i], &arr[j]);

	printf("%d", arr[k - 1]);

	free(arr);
	return 0;
}