#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}COR;

COR sorted[100001];

int compare_item(COR* a, COR* b) {
	if (a->x < b->x) return 1;
	else if (a->x == b->x) {
		if (a->y <= b->y) return 1;
		else return 0;
	}
	return 0;
}

void marge(COR arr[], int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= last) {
		if (compare_item(&arr[i], &arr[j])) sorted[k] = arr[i++];
		else sorted[k] = arr[j++];
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= last; t++)
			sorted[k++] = arr[t];
	}
	else {
		for (int t = i; t <= middle; t++)
			sorted[k++] = arr[t];
	}

	for (int t = start; t <= last; t++)
		arr[t] = sorted[t];
}

void marge_sort(COR arr[], int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		marge_sort(arr, start, middle);
		marge_sort(arr, middle + 1, last);
		marge(arr, start, middle, last);
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	COR* cor = (COR*)calloc(sizeof(COR), n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &cor[i].x, &cor[i].y);
	
	marge_sort(cor, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", cor[i].x, cor[i].y);

	return 0;
}