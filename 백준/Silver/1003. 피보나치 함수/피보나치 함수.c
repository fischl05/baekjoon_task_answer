#include <stdio.h>
#include <string.h>

int fibo[42];
int out[2];

int fibonacci(int num) {
	if (num <= 1) {
		fibo[num] = num;
		return num;
	}
	else {
		if (fibo[num] > 0)
			return fibo[num];
		fibo[num] = fibonacci(num - 1) + fibonacci(num - 2);
		return fibo[num];
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (num == 0) {
			printf("1 0\n");
		}
		else {
			fibonacci(num);
			printf("%d %d\n", fibo[num - 1], fibo[num]);
		}
	}

	return 0;
}