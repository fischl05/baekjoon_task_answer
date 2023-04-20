#include <stdio.h>

int main(void) {
	int a1, a2;
	int c, n;
	
	scanf("%d %d", &a2, &a1);
	scanf("%d", &c);
	scanf("%d", &n);

	if (a2 * n + a1 <= c * n && a2 <= c) printf("1");
	else printf("0");

	return 0;
}