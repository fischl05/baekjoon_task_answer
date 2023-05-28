#include <stdio.h>
#include <math.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int cnt = 0, rep;
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		scanf("%d", &rep);
		for (int j = 0; j < rep; j++) {
			int cx, cy, cr;
			int check = 0;
			scanf("%d %d %d", &cx, &cy, &cr);

			double distance = pow(cx - sx, 2) + pow(cy - sy, 2);
			if (distance > pow(cr, 2)) check++;

			distance = pow(cx - ex, 2) + pow(cy - ey, 2);
			if (distance > pow(cr, 2)) check++;
			
			if (check == 1) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}