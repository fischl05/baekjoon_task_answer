#include <stdio.h>

int main(void) {
	int min = 101;
	int sum = 0;
	
	for (int i = 0; i < 7; i++) {
		int a;
		scanf("%d", &a);
		if (a % 2 != 0) {
			sum += a;
			if (min > a) min = a;
		}
	}
	if (min == 101) {
		printf("%d", -1);
	}
	else printf("%d\n%d", sum, min);

	return 0;
}