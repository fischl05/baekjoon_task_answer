#include <stdio.h>

int main(void) {
	int n = 0, out = 0;

	scanf("%d", &n);

	while(n >= 3) {
		if (n % 5 != 0) {
			n -= 3;
			out++;
		}
		else { 
			out += n / 5; 
			n = 0;
		}
	}
	
	if (n == 0) printf("%d", out);
	else printf("-1");

	return 0;
}