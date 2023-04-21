#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int arr[5] = { 0 };
	int sum = 0;
	
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[j] < arr[i]) swap(&arr[i], &arr[j]);

	printf("%d\n%d", sum / 5, arr[2]);

	return 0;
}