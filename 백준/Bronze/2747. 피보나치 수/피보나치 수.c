#include <stdio.h>

int fibo_num[47];

int fibo(int num) {
	if (num < 2) return num;
	else {
		if (fibo_num[num] > 0) return fibo_num[num];
		fibo_num[num] = fibo(num - 1) + fibo(num - 2);
		return fibo_num[num];
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	printf("%d", fibo(n));

	return 0;
}