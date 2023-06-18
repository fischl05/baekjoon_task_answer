#include <stdio.h>
#include <stdlib.h>

int compare(const void* mem1, const void* mem2) {
	double* a = mem1;
	double* b = mem2;
	if (*a < *b) return 1;
	else return 0;
}

double dp[10001], arr[10001];

int main(void) {
	int n;
	double max = 0.0;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%lf", &arr[i]);

	dp[0] = arr[0];
	max = dp[0];
	for (int i = 1; i < n; i++) {
		double num = arr[i] * dp[i - 1];
		dp[i] = arr[i] > num ? arr[i] : num;
		if (dp[i] > max) max = dp[i];
	}
	printf("%.3lf", max);

	return 0;
}