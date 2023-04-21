#include <stdio.h>

int main(void) {
	int n;
	int cnt = 0, res = 0;

	scanf("%d", &n);
	
	while(1){
		cnt++;

		int temp = cnt;
		while (temp > 0) {
			if (temp % 1000 == 666) {
				res++;
				break;
			}
			else temp /= 10;
		}

		if (res == n) {
			printf("%d", cnt);
			return 0;
		}
	}

	return 0;
}