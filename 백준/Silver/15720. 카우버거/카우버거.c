#include <stdio.h>
#include <stdlib.h>

int compare_item(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	return *b - *a;
}

int main(void) {
	int b, c, d, min = 1001;
	int sale_cost = 0, cost = 0;

	scanf("%d %d %d", &b, &c, &d);
	
	if (min > b) min = b;
	if (min > c) min = c;
	if (min > d) min = d;

	int* b_cost = (int*)calloc(sizeof(int), b);
	int* c_cost = (int*)calloc(sizeof(int), c);
	int* d_cost = (int*)calloc(sizeof(int), d);
	int* cal_cost = (int*)calloc(sizeof(int), min);

	int i = 0;
	for (i = 0; i < b; i++) {
		scanf("%d", &b_cost[i]);
		cost += b_cost[i];
	}
	for (i = 0; i < c; i++) {
		scanf("%d", &c_cost[i]);
		cost += c_cost[i];
	}
	for (i = 0; i < d; i++) {
		scanf("%d", &d_cost[i]);
		cost += d_cost[i];
	}

	qsort((int*)b_cost, b, sizeof(int), compare_item);
	qsort((int*)c_cost, c, sizeof(int), compare_item);
	qsort((int*)d_cost, d, sizeof(int), compare_item);

	for (i = min; i < b; i++) sale_cost += b_cost[i];
	for (i = min; i < c; i++) sale_cost += c_cost[i];
	for (i = min; i < d; i++) sale_cost += d_cost[i];

	for (i = 0; i < min; i++) {
		cal_cost[i] = b_cost[i] + c_cost[i] + d_cost[i];
		cal_cost[i] = cal_cost[i] - (cal_cost[i] / 10);
		sale_cost += cal_cost[i];
	}

	printf("%d\n%d", cost, sale_cost);

	free(b_cost);
	free(c_cost);
	free(d_cost);
	free(cal_cost);
	return 0;
}