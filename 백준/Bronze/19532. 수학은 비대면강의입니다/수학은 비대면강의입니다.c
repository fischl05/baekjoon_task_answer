#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (int i = -999; i <= 999; i++) 
		for (int j = -999; j <= 999; j++) 
			if (a * j + b * i == c) 
				if (d * j + e * i == f) {
					printf("%d %d", j, i);
					return 0;
				}

	return 0;
}