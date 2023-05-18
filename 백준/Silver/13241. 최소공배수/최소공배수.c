#include <stdio.h>

long long int gcm(long long int a, long long int b) {
	if (a % b == 0) return b;
	else gcm(b, a % b);
}

int main(void) {
	long long int a, b;
	long long int max = 0, min = 0;

	scanf("%lld %lld", &a, &b);

	max = a > b ? a : b;
	min = a > b ? b : a;

	printf("%lld", a * b / gcm(max, min));

	return 0;
}