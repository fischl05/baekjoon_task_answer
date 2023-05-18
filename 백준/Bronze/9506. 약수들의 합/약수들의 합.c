#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	int arr[40] = { 0 };

	scanf("%d", &n);

	while (n != -1) {
		memset(arr, 0, 40);
		int cnt = 0, sum = 0;
		for (int i = 1; i < n; i++)
			if (n % i == 0) {
				arr[cnt++] = i;
				sum += i;
			}
		if (sum == n) {
			printf("%d = ", n);
			for (int i = 0; i < cnt - 1; i++) printf("%d + ", arr[i]);
			printf("%d\n", arr[cnt - 1]);
		}
		else printf("%d is NOT perfect.\n", n);

		scanf("%d", &n);
	}

	return 0;
}