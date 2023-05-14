#include <stdio.h>

int main(void) {
	int a, b, c, m;
	int out = 0, firo = 0;

	scanf("%d %d %d %d", &a, &b, &c, &m);

	for(int i = 0 ; i < 24 ; i++){
		if (firo + a <= m) {
			firo += a;
			out += b;
		}
		else {
			firo -= c;
			if (firo < 0) firo = 0;
		}
	}
	printf("%d", out);

	return 0;
}