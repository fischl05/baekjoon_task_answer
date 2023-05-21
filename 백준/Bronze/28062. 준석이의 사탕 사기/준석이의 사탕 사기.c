#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, max = 0, min = 1001, cnt = 0;
	int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		max += arr[i];
		if (arr[i] % 2 != 0) {
			if(min > arr[i]) min = arr[i];
			cnt++;
		}
	}
	if (cnt % 2 != 0 && (max - min) % 2 == 0)
		printf("%d", max - min);
	else if (cnt == n && max % 2 != 0)
		printf("0");
	else
		printf("%d", max);
	
	free(arr);
	return 0;
}