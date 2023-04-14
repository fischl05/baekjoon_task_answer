#include <stdio.h>
#include <string.h>

void reverse(char arr[]) {
	int idx = strlen(arr);
	for (int i = 0; i < idx / 2; i++) {
		char temp = arr[i];
		arr[i] = arr[idx - 1 - i];
		arr[idx - 1 - i] = temp;
	}
}

void bignum_multi(int n, char out[]) {
	int carry[101];
	out[0] = '1';
	memset(carry, 0, 101);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sizeof(carry) / sizeof(int) - 1; j++) {
			if (out[j] >= '0') out[j] -= '0';
			out[j] = (out[j]) * 2 + carry[j];
			carry[j] = 0;
			carry[j + 1] = out[j] / 10;
			out[j] = out[j] % 10;
			for (int z = j; z < sizeof(carry) / sizeof(int) - 1; z++)
				if (out[z] > 0 || carry[j + 1] > 0) {
					out[j] += '0';
					break;
				}
		}
	}
	out[0] -= 1;
	reverse(out);
}

void hanoi(int num, int from, int by, int to) {
	if (num == 1) printf("%d %d\n", from, to);
	else {
		hanoi(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(num - 1, by, from, to);
	}
}

int main(void) {
	int i, num = 0;
	char print[101];
	memset(print, 0, 101);
	scanf("%d", &i);
	
	bignum_multi(i, print);
	printf("%s\n", print);

	/*if (i < 5)*/ hanoi(i, 1, 2, 3);

	return 0;
}