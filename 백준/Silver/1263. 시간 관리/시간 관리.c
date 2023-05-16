#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int len;
	int end_time;
	int start_time;
}DATA;

int compare(const void* mem1, const void* mem2) {
	DATA* a = mem1;
	DATA* b = mem2;
	return a->end_time - b->end_time;
}

int main(void) {
	int n;
	DATA* arr = NULL;

	scanf("%d", &n);
	arr = (DATA*)calloc(sizeof(DATA), n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].len, &arr[i].end_time);
		arr[i].start_time = arr[i].end_time - arr[i].len;
	}

	qsort((DATA*)arr, n, sizeof(DATA), compare);

	int time = 0;
	while (1) {
		int i = time, j = 0;
		for (j = 0; j < n; j++) {
			i += arr[j].len;
			if (i > arr[j].end_time)
				break;
		}
		if (j >= n) time++;
		else break;
	}
	printf("%d", time - 1);

	free(arr);
	return 0;
}