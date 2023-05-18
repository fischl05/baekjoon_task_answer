#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_check(int num) {
	int check = (int)sqrt(num);
	for (int i = 2; i < check; i++)
		if (num % i == 0) return 0;
	return 1;
}

int main(void) {
	int start, last;
	int len = 0, num = 0, prime = 0;
	int* arr = NULL;

	scanf("%d %d", &start, &last);

	len = last - start + 1;

	arr = (int*)calloc(len, sizeof(int));
	for (int i = start; i <= last; i++) {
		arr[num++] = i;
	}

	num = 2;
	prime = (int)sqrt(last);
	if (arr[0] == 1) arr[0] = 0;

	while (num <= prime) {
		for (int i = 0; i < len; i++) {
			if (arr[i] == 0) continue;
			if (arr[i] != num && arr[i] % num == 0) arr[i] = 0;
		}
		num++;
	}

	for (int i = 0; i < len; i++)
		if (arr[i] != 0) printf("%d\n", arr[i]);

	free(arr);
	return 0;
}