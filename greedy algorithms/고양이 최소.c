#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint64_t input, res = 1, cnt = 0;
	
	scanf("%lld", &input);

	if (input == 0) {
		printf("0\n");
		return 0;
	}

	while (res < input) {
		if (res * 2 < input) {
			res *= 2;
			cnt++;
		}
		else if (res * 2 >= input) {
			cnt += 1;
			break;
		}
	}
	printf("%d\n", cnt + 1);

	return 0;
}