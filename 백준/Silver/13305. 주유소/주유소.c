#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
	uint64_t n, out = 0;
	uint64_t* len = NULL;
	uint64_t* arr = NULL;

	scanf("%lld", &n);

	len = (uint64_t*)calloc(n - 1, sizeof(uint64_t));
	arr = (uint64_t*)calloc(n, sizeof(uint64_t));

	for (uint64_t i = 0; i < n - 1; i++)
		scanf("%lld", &len[i]);

	for (uint64_t i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	
	uint64_t min = arr[0];
	for (uint64_t i = 0; i < n - 1; i++) {
		if (min > arr[i]) min = arr[i];
		out += len[i] * min;
	}
	printf("%lld", out);

	return 0;
}