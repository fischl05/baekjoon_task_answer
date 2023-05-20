#include <stdio.h>

int main(void) {
	int n, out = 0;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i *= 10) {
		out += n - i + 1;
	}
	printf("%d", out);

	return 0;
}