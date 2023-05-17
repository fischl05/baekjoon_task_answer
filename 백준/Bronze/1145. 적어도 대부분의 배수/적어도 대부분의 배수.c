#include <stdio.h>

int main(void) {
	int arr[5] = { 0 };
	int min = 101;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		if (min > arr[i]) min = arr[i];
	}

	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (min % arr[i] == 0) cnt++;
		}
		if (cnt >= 3) break;
		else min++;
	}
	printf("%d", min);

	return 0;
}