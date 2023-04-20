#include <stdio.h>

typedef struct {
	int min;
	int max;
}REC;

int main(void) {
	int n;
	REC pos_x = { 10001, -10001 };
	REC pos_y = { 10001, -10001 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (pos_x.min > x) pos_x.min = x;
		if (pos_x.max < x) pos_x.max = x;

		if (pos_y.min > y) pos_y.min = y;
		if (pos_y.max < y) pos_y.max = y;
	}
	printf("%d", (pos_x.max - pos_x.min) * (pos_y.max - pos_y.min));

	return 0;
}