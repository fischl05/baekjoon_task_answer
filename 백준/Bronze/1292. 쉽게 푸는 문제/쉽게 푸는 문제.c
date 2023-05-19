#include <stdio.h>

int main(void) {
	int start, last, cnt = 0, sum = 0;
	int arr[1000] = { 0 };

	scanf("%d %d", &start, &last);

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < i; j++) {
			if (cnt == 1000) break;
			arr[cnt] = i;
			cnt++;
		}
		if (cnt == 1000) break;
	}

	for (int i = start - 1; i < last; i++)
		sum += arr[i];

	printf("%d", sum);

	return 0;
}