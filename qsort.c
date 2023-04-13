#include <stdio.h>
#include <stdlib.h>

int compare_item(int* a, int* b) {
	return *a > *b;
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	int* num = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	qsort((int*)num, n, sizeof(int), compare_item);

	for (int i = 0; i < n; i++)
		printf("%d\n", num[i]);

	return 0;
}