#include <stdio.h>
#include <stdlib.h>

int compare_item(const void* mem1, const void* mem2) {
	int* a = mem1;
	int* b = mem2;
	return *b - *a;
}

int main(void) {
	int n, m;
	int sum = 0, box_cnt = 0;

	scanf("%d %d", &n, &m);

	if (n == 0) {
		printf("0");
		return 0;
	}

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	//qsort((int*)arr, n, sizeof(int), compare_item);
	
	for(int i = 0 ; i < n ; i++){
		if (sum + arr[i] <= m) {
			sum += arr[i];
		}
		else {
			box_cnt++;
			sum = arr[i];
		}
	}
	printf("%d", box_cnt + 1);

	free(arr);
	return 0;
}