#include <stdio.h>

int main(void) {
	int n, cnt = 0;

	scanf("%d", &n);
	
	while (n >= 5) {
		cnt += n / 5;
		n /= 5;
	}

	printf("%d", cnt);
}