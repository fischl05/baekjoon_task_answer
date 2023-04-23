#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int six;
	int one;
}GUITAR;

int main(void) {
	int n, m;
	int idx[2] = { 0 };
	int use_money = 0;

	scanf("%d %d", &n, &m);
	GUITAR* cost = (GUITAR*)calloc(sizeof(GUITAR), m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &cost[i].six, &cost[i].one);
		if (cost[idx[0]].six > cost[i].six) idx[0] = i;
		if (cost[idx[1]].one > cost[i].one) idx[1] = i;
	}
	
	while (n > 0) {
		int multi = n;
		if (multi > 6) multi = 6;
		if (cost[idx[0]].six <= cost[idx[1]].one * multi) {
			use_money += cost[idx[0]].six;
		}
		else {
			use_money += cost[idx[1]].one * multi;
		}
		n -= 6;
	}

	printf("%d", use_money);

	free(cost);
	return 0;
}