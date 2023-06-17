#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void) {
	uint64_t num, start, last, middle/*, idx = INT64_MAX*/;

	scanf("%lld", &num);

	start = 0, last = 3037000500;
	//idx = sqrt(num);

	while (start <= last) {
		middle = (start + last) / 2;
		if (middle * middle > num) last = middle - 1;
		else if (middle * middle < num)  start = middle + 1;
		else break;
	}
	if (num > middle * middle) middle++;
	printf("%lld\n", middle);

	return 0;
}