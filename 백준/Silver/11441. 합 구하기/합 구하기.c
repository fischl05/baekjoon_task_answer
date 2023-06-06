#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n + 1, sizeof(int));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int start, last;
		scanf("%d %d", &start, &last);

		printf("%d\n", arr[last] - arr[start - 1]);
	}

	free(arr);
	return 0;
}