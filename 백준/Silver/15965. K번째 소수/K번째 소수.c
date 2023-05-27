#include <stdio.h>

int arr[500001];

int main(void) {
	int n, cnt = 0;
		
	scanf("%d", &n);

	for (int i = 2; i <= 500000; i++)
		arr[i] = i;

	for (int i = 2; i <= 500000; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 500000; j += i)
			arr[j] = 0;
	}

	for (int i = 2; i <= 500000; i++) {
		if (arr[i] != 0) cnt++;
		if (cnt == n) {
			printf("%d", arr[i]);
			return 0;
		}
	}

	return 0;
}