#include <stdio.h>
#include <stdlib.h>

int compare(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	if (*a < *b) return 1;
	return 0;
}

int gcm(int a, int b) {
	if (a % b == 0) return b;
	else return gcm(b, a % b);
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int m;
		long long int sum = 0;
		int* arr = NULL;
		scanf("%d", &m);

		arr = (int*)calloc(m, sizeof(int));
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[j]);

		qsort((int*)arr, m, sizeof(int), compare);

		for (int j = 0; j < m; j++)
			for(int k = j + 1 ; k < m ; k++)
				sum += gcm(arr[j], arr[k]);

		printf("%lld\n", sum);
		free(arr);
	}

	return 0;
}