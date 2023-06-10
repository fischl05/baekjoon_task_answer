#include <stdio.h>

int main(void) {
	int n;
	
	long long int num = 1, cnt = 1;

	while (scanf("%d", &n) != EOF) {
		cnt = 1;
		num = 1;
		while (num % n != 0) {
			num = (num * 10) % n + 1 % n;
			num %= n;
			cnt++;
		}
		printf("%lld\n", cnt);
	}

	return 0;
}