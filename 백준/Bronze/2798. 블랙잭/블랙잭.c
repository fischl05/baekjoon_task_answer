#include <stdio.h>
#include <stdlib.h>

int compare_item(int* a, int* b) {
	return *b - *a;
}

int main(void) {
	int n, num, max = 0;

	scanf("%d %d", &n, &num);
	int* arr = (int*)calloc(sizeof(int), n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int z = 0; z < n; z++) {
				if (z == i || z == j) continue;
				int sum = arr[i] + arr[j] + arr[z];
				if (sum <= num && sum > max) max = sum;
			}
		}
	}

	printf("%d", max);

	free(arr);
	return 0;
}