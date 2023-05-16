#include <stdio.h>

int main(void) {
	int arr[2] = { 0 };
	int min, max;

	scanf("%d %d", arr, arr + 1);
	
	min = arr[0] > arr[1] ? arr[1] : arr[0];
	max = arr[0] > arr[1] ? arr[0] : arr[1];

	for (int i = min; i >= 0; i--) {
		if (arr[0] % i == 0 && arr[1] % i == 0) {
			min = i;
			break;
		}
	}
	while (1) {
		if (max % arr[0] == 0 && max % arr[1] == 0)
			break;
		max++;
	}
	printf("%d %d\n", min, max);

	return 0;
}