#include <stdio.h>
#include <stdlib.h>

char BW[8][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

char WB[8][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

int bw_test(char** arr, int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (arr[y + i][x + j] != BW[i][j]) cnt++;
	return cnt;
}

int wb_test(char** arr, int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (arr[y + i][x + j] != WB[i][j]) cnt++;
	return cnt;
}

int main(void) {
	int m, n;
	int cnt = 0, min = 2147483647;

	scanf("%d %d", &m, &n);

	char** arr = (char**)calloc(sizeof(char*), m);
	for (int i = 0; i < m; i++)
		arr[i] = (char*)calloc(sizeof(char), n + 1);

	for (int i = 0; i < m; i++)
		scanf("%s", arr[i]);

	for (int y = 0; y <= m - 8; y++) {
		for (int x = 0; x <= n - 8; x++) {
			int wcnt = 0, bcnt = 0;
			wcnt = wb_test(arr, x, y);
			bcnt = bw_test(arr, x, y);
			if (min > wcnt) min = wcnt;
			if (min > bcnt) min = bcnt;
		}
	}

	printf("%d", min);

	for (int i = 0; i < m; i++)
		free(arr[i]);
	free(arr);

	return 0;
}