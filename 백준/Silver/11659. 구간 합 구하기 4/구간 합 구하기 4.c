#include <stdio.h>
#include <stdlib.h>

int sum[100000];

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int start, last;
		scanf("%d %d", &start, &last);
		printf("%d\n", sum[last] - sum[start - 1]);
	}

	return 0;
}