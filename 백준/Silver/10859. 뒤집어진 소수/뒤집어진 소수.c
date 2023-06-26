#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime_test(long long int num) {
	if (num <= 1) return 0;
	for (long long int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int reverse(long long int a) {
	long long int out = 0;
	while (a > 0) {
		int temp = a % 10;
		if (temp == 0 || temp == 1 || temp == 2 || temp == 5 || temp == 8) temp = temp;
		else if (temp == 6) temp = 9;
		else if (temp == 9) temp = 6;
		else return 0;
		out *= 10;
		out += temp;
		a /= 10;
	}
	return prime_test(out);
}

int main(void) {
	long long int n;

	scanf("%lld", &n);

	if (prime_test(n)) {
		if (reverse(n)) printf("yes");
		else printf("no");
	}
	else printf("no");

	return 0;
}