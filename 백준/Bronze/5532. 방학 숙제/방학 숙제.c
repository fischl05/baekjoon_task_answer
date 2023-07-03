#include <stdio.h>

int main(void) {
	int l, a, b, c, d;

	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	while (a > 0 || b > 0) {
		a -= c;
		b -= d;
		l--;
	}
	printf("%d", l);

	return 0;
}