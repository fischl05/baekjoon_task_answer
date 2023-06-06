#include <stdio.h>
#include <math.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		long long int num;
		int i = 0;
		scanf("%lld", &num);
		while (1) {
			int snum = (int)sqrt(num);
			int j = 0;
			if (num <= 2) {
				printf("2\n");
				break;
			}
			else if (num % 2 == 0) num++;
			else {
				for (j = 3; j <= snum; j++) {
					if (num % j == 0) break;
				}
				if (j > snum) {
					printf("%lld\n", num);
					break;
				}
				else num++;
			}
		}
	}

	return 0;
}