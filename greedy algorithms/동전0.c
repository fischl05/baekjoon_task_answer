#include <stdio.h>
#include <stdlib.h>

int compare_standard(int* a, int* b) {
	return *a < *b;
}

int main(void) {
	int n, k, out = 0;;
	
	scanf("%d %d", &n, &k);
	int* money = (int*)calloc(sizeof(int), n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &money[i]);

	qsort((int*)money, n, sizeof(int), compare_standard);

	for (int i = 0; i < n; i++) {
		while (k >= money[i]) {
			k -= money[i];
			out++;
		}
	}
	printf("%d", out);

	free(money);
	return 0;
}