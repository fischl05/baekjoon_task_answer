#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, max = 0;
	int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr[i] -= n - i;
		if (arr[i] < 0) arr[i] = 0;
		if (arr[i] > max) max = arr[i];
	}
	printf("%d", max);

	free(arr);
	return 0;
}