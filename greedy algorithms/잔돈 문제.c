#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int value[4] = { 25, 10, 5, 1 };

	int* money = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &money[i]);
	}

	for (int i = 0; i < n; i++) {
		int out[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4; j++) {
			while(money[i] >= value[j]) {
				money[i] -= value[j];
				out[j]++;
			}
		}
		for (int j = 0; j < 4; j++)
			printf("%d ", out[j]);
		printf("\n");
	}
	
	free(money);
	return 0;
}