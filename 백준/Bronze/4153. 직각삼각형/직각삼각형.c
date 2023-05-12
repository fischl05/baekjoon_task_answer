#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	return *a - *b;
}

int main(void) {
	int arr[3];

	for (int i = 0; i < 3; i++)
		scanf("%d", &arr[i]);

	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0) {
		qsort((int*)arr, 3, sizeof(int), compare);
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) printf("right\n");
		else printf("wrong\n");

		for (int i = 0; i < 3; i++)
			scanf("%d", &arr[i]);
	}

	return 0;
}