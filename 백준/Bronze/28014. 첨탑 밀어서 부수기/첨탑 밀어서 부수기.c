#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int cnt = 0;

	scanf("%d", &n);
	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int i = 0;
	for (i = 1; i < n; i++)
		if (arr[i - 1] <= arr[i]) cnt++;
	i--;
	//if (arr[i] > arr[i - 1]) cnt++;
	printf("%d", cnt + 1);

	free(arr);
	return 0;
}