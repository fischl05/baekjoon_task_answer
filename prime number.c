#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, cnt = 0;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 2) cnt++;
		else {
			int j;
			for (j = 2; j < arr[i]; j++)
				if (arr[i] % j == 0) break;
			if (j == arr[i]) cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}