#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	long long int sum = 0, out = 0;
	long long int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(long long int));
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		sum += arr[i];
	}

	for (int i = 0; i < n; i++) {
		sum -= arr[i];
		out = (out + arr[i] * sum) % 1000000007;
	}
	printf("%lld\n", out);

	free(arr);
	return 0;
}