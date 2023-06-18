#include <stdio.h>
#include <string.h>

void change(long long int num, char str[]) {
	int idx = 0;
	while (num >= 2) {
		str[idx++] = num % 2 + '0';
		num /= 2;
	}
	str[idx++] = num % 2 + '0';
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		long long int num;
		int len = 0, cnt = 0, arr[2] = { 0 };
		char str[101] = { 0 };

		scanf("%lld", &num);

		change(num, str);
		len = strlen(str);
		
		for (int j = 0; j < len; j++) {
			if (str[j] == '1') {
				arr[cnt++] = j;
			}
			if (cnt >= 2) break;
		}
		if (cnt == 1) {
			arr[0] -= 1;
			arr[1] = arr[0];
		}
		printf("%d %d", arr[0], arr[1]);
		printf("\n");
	}

	return 0;
}