#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;
	int* arr1 = NULL;
	int* arr2 = NULL;
	int* out = NULL;

	scanf("%d %d", &n, &m);

	arr1 = (int*)calloc(n, sizeof(int));
	arr2 = (int*)calloc(m, sizeof(int));
	out = (int*)calloc(n + m, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr2[i]);

	int i = 0, j = 0, k = 0;

	while (i < n && j < m) {
		if (arr1[i] < arr2[j])
			out[k++] = arr1[i++];
		else
			out[k++] = arr2[j++];
	}
	while (i < n)
		out[k++] = arr1[i++];
	while (j < m)
		out[k++] = arr2[j++];

	for (int i = 0; i < n + m; i++)
		printf("%d ", out[i]);

	return 0;
}