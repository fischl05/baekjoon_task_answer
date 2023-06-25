#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int first, second;
}PERSON;

PERSON sorted[100000];

void merge(PERSON* arr, int start, int middle, int last) {
	int i = start, j = middle + 1, k = start;
	while (i <= middle && j <= last) {
		if (arr[i].first < arr[j].first) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
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

void merge_sort(PERSON* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int re;

	scanf("%d", &re);
	
	while (re--){
		int n, best_second, out = 1;
		PERSON* arr = NULL;

		scanf("%d", &n);
		
		arr = (PERSON*)calloc(n, sizeof(PERSON));
		for (int i = 0; i < n; i++)
			scanf("%d %d", &arr[i].first, &arr[i].second);

		merge_sort(arr, 0, n - 1);
		best_second = arr[0].second;

		for (int i = 1; i < n; i++) {
			if (arr[i].second < best_second) {
				out++;
				best_second = arr[i].second;
			}
		}
		printf("%d\n", out);
	}

	return 0;
}