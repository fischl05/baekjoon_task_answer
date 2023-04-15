#include <stdio.h>
#include <string.h>

void reverse(char arr[]) {
	int idx = strlen(arr);
	for (int i = 0; i < strlen(arr) / 2; i++) {
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
				if (out[z] != 0) {
					out[j] += '0';
					break;
				}
		}
	}
}

int main(void) {
	int num = 0;
	char out[101];
	memset(out, 0, 101);

	scanf("%d", &num);

	bignum_multi(num, out);
	reverse(out);
	printf("%s", out);

	return 0;
}
