#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, out = 0;
	
	scanf("%d", &n);

	int* a = (int*)calloc(sizeof(int), n);
	int* b = (int*)calloc(sizeof(int), n);
	int* max_idx = (int*)calloc(sizeof(int), n);
	int* min_idx = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < n; i++) {
		int max = 0, min = 101;
		int j = 0, idx = 0;
		for (j = 0; j < n; j++)
			if (max <= b[j] && !max_idx[j]) {
				max = b[j];
				idx = j;
			}
		max_idx[idx] = 1;
		for (j = 0; j < n; j++)
			if (min >= a[j] && !min_idx[j]) {
				min = a[j];
				idx = j;
			}
		min_idx[idx] = 1;

		out += max * min;
	}

	printf("%d", out);

	free(a); free(b); free(max_idx); free(min_idx);

	return 0;
}