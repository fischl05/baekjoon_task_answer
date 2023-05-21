#include <stdio.h>

int main(void) {
	int n, out = 0;
	int x, y;

	scanf("%d", &n);
	scanf("%d %d", &x, &y);

	if (n == 1) out = 0;
	else if ((x == 1 || x == n) && (y == 1 || y == n)) out = 2;
	else if ((x == 1 || x == n) || (y == 1 || y == n)) out = 3;
	else out = 4;

	printf("%d", out);

	return 0;
}