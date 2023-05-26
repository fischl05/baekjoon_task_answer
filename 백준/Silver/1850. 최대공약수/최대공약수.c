#include <stdio.h>

long long int gcm(long long int a, long long int b) {
	if (a % b == 0) return b;
	else return gcm(b, a % b);
}

int main(void) {
	long long int a, b, min, max;
	long long int g;

	scanf("%lld %lld", &a, &b);

	min = a > b ? b : a;
	max = a > b ? a : b;
		
	g = gcm(max, min);

	for (int i = 0; i < g; i++)
		printf("1");

	return 0;
}