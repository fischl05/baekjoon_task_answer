#include <stdio.h>

int main(void) {
	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);

	if (a < b) printf("Bus");
	else if (a == b) {
		if (n > b) printf("Bus");
		else if (n == b || n < b) printf("Anything");
		else printf("Subway");
	}
	else {
		if (n > b) printf("Bus");
		else printf("Subway");
	}

	return 0;
}