#include <stdio.h>
#include <stdlib.h>

int sorted[100000];

void merge(int* arr, int start, int middle, int last) {
	int i = start, j = middle + 1, k = start;
	while (i <= middle && j <= last) {
		if (arr[i] < arr[j])
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

void merge_sort(int* arr, int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, last);
		merge(arr, start, middle, last);
	}
}

int main(void) {
	int n;
	long long int out = 0;
	int* arr = NULL;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n - 1; i++) {
		int low = i;
		int high = n - 1;
		int idx = i;
		while (low <= high) {
			int mid = (low + high) / 2;
			//작은 파일의 크기가 큰 파일의 0.9배보다 클 경우 검사
			//오름차순으로 정렬되어 있기에 arr[i]의 값보다 arr[mid]의 값이 무조건 크기 때문에 idx의 최대 값을 구하면 그의 왼쪽에 있는 값도 모두 성립
			if (arr[i] * 10 >= arr[mid] * 9) {
				low = mid + 1;
				if (mid > idx) idx = mid;
			}
			else high = mid - 1;
		}
		// i밑에 있는 값은 애초에 값이 작은 것이라서 빼주기
		out += idx - i;
	}
	printf("%lld", out);

	free(arr);
	return 0;
}
