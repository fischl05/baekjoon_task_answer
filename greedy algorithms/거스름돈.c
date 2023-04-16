#include <stdio.h>

int main(void) {
	int value[6] = { 500, 100, 50, 10, 5, 1 };
	int out = 0, money;
	
	scanf("%d", &money);
	money = 1000 - money;

	for (int i = 0; i < 6; i++) {
		while (money >= value[i]) {
			money -= value[i];
			out++;
		}
	}
	printf("%d", out);

	return 0;
}