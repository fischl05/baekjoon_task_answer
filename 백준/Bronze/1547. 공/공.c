#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int arr[3] = { 1, 0, 0 };
	int n;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		swap(&arr[first - 1], &arr[second - 1]);
	}
	
	for (int i = 0; i < 3; i++)
		if (arr[i] == 1) printf("%d\n", i + 1);

	return 0;
}