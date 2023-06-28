#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int* arr = NULL;

	scanf("%d", &n);

	while (n != 0) {
		int max = -10001, sum = 0;
		arr = (int*)calloc(n + 1, sizeof(int));

		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			//sum = sum + arr[i] > sum ? sum + arr[i] : arr[i];
			if (arr[i] + arr[i - 1] > arr[i]) arr[i] = arr[i] + arr[i - 1];

			if (arr[i] > max) max = arr[i];
		}
		printf("%d\n", max);
		scanf("%d", &n);
	}

	return 0;
}