#include <stdio.h>
#include <string.h>

long long int user_pow(int n) {
	long long int num = 1;
	for (int i = 0; i < n; i++) {
		num *= 3;
	}
	return num;
}

int main(void) {
	long long int num, idx = 0, wnum = -1, out = 0;
	char str[51] = { 0 };

	scanf("%lld", &num);

	while (num > 1) {
		str[idx++] = num % 2 + '0';
		num /= 2;
	}
	str[idx++] = num + '0';
	
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		wnum++;
		if (str[i] == '0') continue;
		else {
			out += user_pow(wnum);
		}
	}
	printf("%lld", out);

	return 0;
}