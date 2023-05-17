#include <stdio.h>
#include <stdlib.h>

int compare(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	if (*a > *b) return 1;
	else if (*a < *b) return -1;
	return 0;
}

int bin_search(int* arr, int start, int last, int goal) {
	if (start > last) return 0;
	int middle = (start + last) / 2;
	if (arr[middle] == goal) return 1;
	else {
		if (arr[middle] > goal) return bin_search(arr, start, middle - 1, goal);
		else return bin_search(arr, middle + 1, last, goal);
	}
}

int main(void) {
	int n, m;
	int* origin = NULL;
	int* find = NULL;

	scanf("%d", &n);
	origin = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		scanf("%d", &origin[i]);

	scanf("%d", &m);
	find = (int*)calloc(sizeof(int), m);

	for (int i = 0; i < m; i++)
		scanf("%d", &find[i]);
	
	qsort((int*)origin, n, sizeof(int), compare);

	for (int i = 0; i < m; i++) {
		printf("%d\n", bin_search(origin, 0, n - 1, find[i]));
	}

	free(origin);
	free(find);
	return 0;
}