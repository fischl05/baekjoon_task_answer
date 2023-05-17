#include <stdio.h>
#include <stdlib.h>

int compare(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	return *b - *a;
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int arr[10] = { 0 };

		for (int j = 0; j < 10; j++)
			scanf("%d", &arr[j]);

		qsort((int*)arr, 10, sizeof(int), compare);
		printf("%d\n", arr[2]);
	}

	return 0;
}