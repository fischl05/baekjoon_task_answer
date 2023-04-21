#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] < arr[j]) swap(&arr[i], &arr[j]);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	free(arr);
	return 0;
}