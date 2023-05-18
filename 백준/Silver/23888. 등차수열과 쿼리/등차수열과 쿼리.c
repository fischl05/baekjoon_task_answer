#include <stdio.h>
#include <stdlib.h>

long long int gcd(long long int a, long long int b) {
	if (b == 0) return a;
	long long int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

int main(void) {
	long long int a, d;
	long long int n;

	scanf("%lld %lld", &a, &d);
	
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		long long int com;
		long long int l, r;
		scanf("%lld %lld %lld", &com, &l, &r);
		if (com == 1) {
			long long int tmp1 = r * (2 * a + (r - 1) * d) / 2;
			long long int tmp2 = (l - 1) * (2 * a + (l - 2) * d) / 2;
			printf("%lld\n", tmp1 - tmp2);
		}
		else {
			if (l == r) printf("%lld\n", a + (l - 1) * d);
			else printf("%lld\n", gcd(a, d));
		}
	}

	return 0;
}