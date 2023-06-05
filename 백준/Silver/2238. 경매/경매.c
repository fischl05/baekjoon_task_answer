#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[11];
	int money;
	int num;
}DATA;

DATA sorted[100000];

int compare(DATA* a, DATA* b) {
	if (a->money < b->money) return 1;
	else if (a->money == b->money) {
		if (a->num < b->num) return 1;
		else return 0;
	}
	else return 0;
}

void merge(DATA* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (compare(&arr[i], &arr[j]))
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > middle)
		for (int t = j; t <= last; t++)
			sorted[k++] = arr[t];
	else
		for (int t = i; t <= middle; t++)
			sorted[k++] = arr[t];
	for (int t = start; t <= last; t++)
		arr[t] = sorted[t];
}

void merge_sort(DATA* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n, m, idx = -1, min = 10001;
	int money[10001] = { 0 };
	DATA* arr = NULL;

	scanf("%d %d", &m, &n);

	arr = (DATA*)calloc(n + 1, sizeof(DATA));
	for (int i = 0; i < n; i++) {
		scanf("%s %d", arr[i].name, &arr[i].money);
		money[arr[i].money] += 1;
		arr[i].num = i;
	}

	merge_sort(arr, 0, n - 1);
	
	int i = 0;
	for (i = 0; i < n; i++) {
		if (money[arr[i].money] < min) {
			idx = arr[i].money;
			min = money[arr[i].money];
		}
	}

	for(int i = 0 ; i < n ; i++)
		if (arr[i].money == idx) {
			printf("%s %d\n", arr[i].name, arr[i].money);
			break;
		}

	free(arr);
	return 0;
}