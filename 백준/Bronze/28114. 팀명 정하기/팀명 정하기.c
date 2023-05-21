#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int year;
	char name[6];
}DATA;

int compare(const void* mem1, const void* mem2) {
	DATA* a = mem1;
	DATA* b = mem2;
	if (a->year > b->year) return 1;
	return 0;
}

int compare2(const void* mem1, const void* mem2) {
	DATA* a = mem1;
	DATA* b = mem2;
	if (a->num < b->num) return 1;
	return 0;
}

int main(void) {
	DATA arr[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d %d %s", &arr[i].num, &arr[i].year, arr[i].name);
		arr[i].year %= 100;
	}

	qsort((DATA*)arr, 3, sizeof(DATA), compare);

	printf("%d%d%d\n", arr[0].year, arr[1].year, arr[2].year);

	qsort((DATA*)arr, 3, sizeof(DATA), compare2);

	printf("%c%c%c", arr[0].name[0], arr[1].name[0], arr[2].name[0]);

	return 0;
}