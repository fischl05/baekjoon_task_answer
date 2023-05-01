#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	int a, b, n = 0;
	int out = 0;

	scanf("%d %d", &a, &b);
	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (abs(b - a) > abs(b - arr[i])) {
			a = arr[i];
			out = 1;
		}
	}
	
	printf("%d", abs(b - a) + out);

	free(arr);
	return 0;
}