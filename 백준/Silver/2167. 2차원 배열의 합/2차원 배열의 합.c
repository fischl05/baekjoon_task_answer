#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m, n, k, out = 0;
	int** arr = NULL;

	scanf("%d %d", &n, &m);

	arr = (int**)calloc(sizeof(int*), n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)calloc(sizeof(int), m + 1);

	for(int i = 0 ; i < n ; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &y, &x);

		for (int a = i - 1; a < y; a++)
			out += arr[a][x] - arr[a][j - 1];

		printf("%d\n", out);
		out = 0;
	}

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	return 0;
}
