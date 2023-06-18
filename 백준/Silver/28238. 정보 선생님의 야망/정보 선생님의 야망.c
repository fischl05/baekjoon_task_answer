#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int** arr = NULL;
	int save[5] = { 0 }, max = 0;

	scanf("%d", &n);

	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			
			int cnt = 0;

			for (int x = 0; x < n; x++)
				if (arr[x][i] == 1 && arr[x][j] == 1) cnt++;
			
			if (cnt > max) {
				max = cnt;
				save[0] = save[1] = save[2] = save[3] = save[4] = 0;
				save[i] = 1;
				save[j] = 1;
			}

		}
	}

	printf("%d\n", max);
	if (save[0] + save[1] + save[2] + save[3] + save[4] < 2) printf("1 1 0 0 0");
	else {
		for (int i = 0; i < 5; i++)
			printf("%d ", save[i]);
	}

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	return 0;
}