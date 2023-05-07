#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int max = 0;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] >= arr[j]) cnt++;
			else break;
		}
		if (cnt > max) max = cnt;
	}
	printf("%d", max);

	free(arr);
	return 0;
}