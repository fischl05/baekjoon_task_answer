#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k = 0;
	int cnt = 0;
	int* arr = NULL;

	scanf("%d %d", &n, &k);

	arr = (int*)calloc(n + 1, sizeof(int));
	for (int i = 2; i <= n; i++)
		arr[i] = i;

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (arr[j] == 0) continue;
			cnt++;
			if (cnt >= k) {
				printf("%d", arr[j]);
				return 0;
			}
			arr[j] = 0;
		}
	}

	free(arr);
	return 0;
}