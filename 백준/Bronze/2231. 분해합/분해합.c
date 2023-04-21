#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(int num, int goal) {
	char str[8];
	int len = 0, sum = 0;
	sprintf(str, "%d", num);
	len = strlen(str);

	for (int i = 0; i < len; i++)
		sum += str[i] - '0';
	if (sum + num == goal) return 1;
	else return 0;
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 1; i < n; i++)
		if (check(i, n) == 1) {
			printf("%d", i);
			return 0;
		}
	printf("0");

	return 0;
}