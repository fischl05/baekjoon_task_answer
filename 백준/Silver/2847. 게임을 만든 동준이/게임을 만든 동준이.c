#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, max, cnt = 0;

	scanf("%d", &n);
	int* arr = (int*)calloc(sizeof(int), n);

	n -= 1;

	for (int i = 0; i <= n; i++)
		scanf("%d", &arr[i]);
	max = arr[n--];
	
	while (n >= 0) {
		if (arr[n] >= max) {
			arr[n] -= 1;
			cnt++;
		}
		else {
			max = arr[n];
			n--;
		}
	}
	printf("%d", cnt);

	return 0;
}