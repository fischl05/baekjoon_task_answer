#include <stdio.h>

int main(void) {
	int num = 0, out = 0;

	scanf("%d", &num);

	while (num > 0) {
		if (num % 5 != 0) {
			num -= 2;
			out += 1;
		}
		else {
			out += num / 5;
			num = 0;
		}
	}
	if (num == 0)
		printf("%d", out);
	else printf("-1");

	return 0;
}