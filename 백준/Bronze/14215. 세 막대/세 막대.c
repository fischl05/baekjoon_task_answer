#include <stdio.h>

int main(void) {
	int arr[3], max = 0, idx = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}
	}
	if (arr[0] == arr[1] && arr[1] == arr[2]) printf("%d", arr[0] + arr[1] + arr[2]);
	else {
		if (arr[0] + arr[1] + arr[2] - max <= max) {
			arr[idx] = arr[0] + arr[1] + arr[2] - max - 1;
		}
		printf("%d", arr[0] + arr[1] + arr[2]);
	}
	return 0;
}