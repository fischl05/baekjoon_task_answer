#include <stdio.h>
#include <stdlib.h>

int compare(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	return *a - *b;
}

int main(void) {
	int piro, n;
	int out = 0;

	scanf("%d %d", &piro, &n);
	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	qsort((int*)arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		if (piro < 200) {
			piro += arr[i];
			out++;
		}
		else break;
	}
	printf("%d", out);

	free(arr);
	return 0;
}