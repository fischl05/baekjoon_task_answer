#include <stdio.h>

int main(void) {
	int n;
	long long int num = 1; 

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		num *= i;
		while (num % 10 == 0) num /= 10;
		num %= 1000000000000;
	}
	num %= 100000;
	printf("%05lld", num);

	return 0;
}