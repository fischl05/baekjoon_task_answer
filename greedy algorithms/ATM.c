#include <stdio.h>
#include <stdlib.h>

int compare_item(int* a, int* b) {
	return *a > *b;
}

int main(void) {
	int n, out = 0;;
	
	scanf("%d", &n);
	
	int* min = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &min[i]);

	qsort((int*)min, n, sizeof(int), compare_item);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			out += min[j];
	}
	printf("%d", out);

	return 0;
}