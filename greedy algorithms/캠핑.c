#include <stdio.h>

int main(void) {
	int p, l, v, n = 0;

	scanf("%d %d %d", &l, &p, &v);

	while (l != 0 && p != 0 && v != 0) {
		int out = 0;
		while (v > 0) {
			if (v > p) {
				v -= p;
				out += l;
			}
			else if (v <= p && v > l) {
				v -= p;
				out += l;
			}
			else if (v <= l) {
				out += v;
				v = 0;
			}
		}
		printf("Case %d: %d\n", ++n, out);

		scanf("%d %d %d", &l, &p, &v);
	}

	return 0;
}