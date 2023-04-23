#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int r, c;
	int multi;
}RECT;

RECT sorted_arr[1000];

void merge(RECT* arr, int start, int middle, int last) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= last) {
		if (arr[i].multi > arr[j].multi) {
			sorted_arr[k] = arr[i];
			i++;
		}
		else {
			sorted_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int t = j; t <= last; t++)
			sorted_arr[k++] = arr[t];
	}
	else {
		for (int t = i; t <= middle; t++)
			sorted_arr[k++] = arr[t];
	}

	for (int t = start; t <= last; t++)
		arr[t] = sorted_arr[t];
}

void merge_sort(RECT* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int candy, num, cnt = 0;
		int j = 0;
		scanf("%d %d", &candy, &num);
		
		RECT* rect = (RECT*)calloc(sizeof(RECT), num);
		for (j = 0; j < num; j++) {
			scanf("%d %d", &rect[j].r, &rect[j].c);
			rect[j].multi = rect[j].r * rect[j].c;
		}

		merge_sort(rect, 0, num - 1);
		
		j = 0;
		while (candy > 0) {
			if (candy >= rect[j].multi) {
				candy -= rect[j].multi;
				cnt++;
			}
			else if(candy < rect[j].multi) {
				candy = 0;
				cnt++;
			}
			j++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}