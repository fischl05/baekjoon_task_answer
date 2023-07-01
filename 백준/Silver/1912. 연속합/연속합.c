#include <stdio.h>
#include <stdlib.h>

int dp[100000];

int main(void) {
	int n, max = -1001;
	int* arr = NULL;

	scanf("%d", &n);
	
	arr = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	max = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + arr[i] > arr[i] ? dp[i - 1] + arr[i] : arr[i];
		if (dp[i] > max) max = dp[i];
	}
	printf("%d\n", max);

	free(arr);
	return 0;
}